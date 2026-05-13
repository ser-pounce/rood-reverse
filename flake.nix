{
  description = "Development environment for rood-reverse";

  nixConfig = {
    extra-substituters = [ "https://rood-reverse.cachix.org" ];
    extra-trusted-public-keys = [
      "rood-reverse.cachix.org-1:mbBDtJQi0uyGBmXXRo2yZhnAhfnKi0wLXaBskSS+lwA="
    ];
  };

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  # Pinned for the cross-mipsel preprocessor only: Ubuntu 24.04 ships
  # gcc-mipsel-linux-gnu 12.4.0, and matching codegen depends on cpp from that
  # exact major version. nixpkgs-unstable removed gcc12 (Aug 2025); nixos-24.11
  # is the last release branch that still has it.
  inputs.nixpkgs-gcc12.url = "github:NixOS/nixpkgs/nixos-24.11";

  outputs = { self, nixpkgs, nixpkgs-gcc12 }:
    let
      systems = [
        "aarch64-darwin"
        "x86_64-darwin"
        "x86_64-linux"
      ];

      forAllSystems = f:
        nixpkgs.lib.genAttrs systems (system: f nixpkgs.legacyPackages.${system} nixpkgs-gcc12.legacyPackages.${system});
    in
    {
      devShells = forAllSystems (pkgs: pkgsGcc12:
        let
          oldGccVersion = "0.17";

          oldGccRelease = name: hash:
            pkgs.fetchurl {
              url = "https://github.com/decompals/old-gcc/releases/download/${oldGccVersion}/${name}";
              inherit hash;
            };

          oldGccArchives = {
            "2.7.2-cdk" = oldGccRelease "gcc-2.7.2-cdk-macos.tar.gz"
              "sha256-Q/499Eut0j1XB1rcBqsXfZgLHinwOSpUJuifZSyDLRo=";
            "2.7.2-psx" = oldGccRelease "gcc-2.7.2-psx-macos.tar.gz"
              "sha256-QoCJRmHJeSvBn1yXDCg9NTgZN/tE5HmpHQwETJX80gg=";
            "2.8.1-psx" = oldGccRelease "gcc-2.8.1-psx-macos.tar.gz"
              "sha256-urDG6h85RXPVqrvdezfjas7rg8UiFB2Uaoep9YwZnqA=";
          };

          setupOldGcc = pkgs.writeShellApplication {
            name = "setup-old-gcc";
            runtimeInputs = [ pkgs.gnutar pkgs.gzip pkgs.coreutils ];
            text = ''
              root="''${1:-$PWD}"
              oldgcc="$root/tools/old-gcc"

              if [ ! -d "$oldgcc" ]; then
                echo "tools/old-gcc is missing; run git submodule update --init --recursive first" >&2
                exit 1
              fi

              install_archive() {
                version="$1"
                archive="$2"
                out="$oldgcc/build-gcc-$version"

                if [ -x "$out/cc1" ]; then
                  return
                fi

                echo "Installing old-gcc $version to $out"
                mkdir -p "$out"
                tar -xzf "$archive" -C "$out"
                chmod +x "$out"/cpp "$out"/cc1 "$out"/gcc "$out"/cc1plus "$out"/g++
              }

              install_archive 2.7.2-cdk ${oldGccArchives."2.7.2-cdk"}
              install_archive 2.7.2-psx ${oldGccArchives."2.7.2-psx"}
              install_archive 2.8.1-psx ${oldGccArchives."2.8.1-psx"}
            '';
          };

          # crossBt (binutils) is small and cached. crossGcc (gcc-unwrapped) pulls a from-source
          # cross-GCC closure on Darwin — slow on first build for any individual mac contributor,
          # but rood-reverse.cachix.org substitutes the result for everyone after the first push.
          # We need cpp from it: the original Makefile invokes $(ARCH)cpp = mipsel-linux-gnu-cpp,
          # and matching codegen depends on modern GCC's preprocessor (not old-gcc's PSY-Q-era cpp).
          crossPkgs = pkgs.pkgsCross.mipsel-linux-gnu;
          crossBt = crossPkgs.buildPackages.binutils;
          # Pin gcc12 cross from nixos-24.11 — modern cpp (>= gcc13) emits subtly different
          # preprocessed output that breaks matching codegen for SLUS/TITLE/BATTLE/several
          # MENU PRGs. The Ubuntu 24.04 reference uses gcc-mipsel-linux-gnu 12.4.0; we pin
          # the same major version through `pkgsGcc12` (a separate nixpkgs input).
          crossGcc = pkgsGcc12.pkgsCross.mipsel-linux-gnu.buildPackages.gcc12.cc;
          crossTriplet = crossPkgs.stdenv.targetPlatform.config;
          mipselLinuxGnuBin = pkgs.runCommand "mipsel-linux-gnu-toolchain-aliases" { } ''
            mkdir -p $out/bin
            for name in as ld ar nm objdump objcopy ranlib readelf size strip strings addr2line c++filt elfedit; do
              ln -s ${crossBt}/bin/${crossTriplet}-$name $out/bin/mipsel-linux-gnu-$name
            done
            ln -s ${crossGcc}/bin/${crossTriplet}-cpp $out/bin/mipsel-linux-gnu-cpp
          '';
        in
        {
          default = pkgs.mkShell {
            packages = [
              pkgs.bash
              pkgs.cmake
              pkgs.clang-tools
              pkgs.gnumake
              pkgs.git
              pkgs.rustup
              pkgs.python3
              setupOldGcc
              crossBt
              mipselLinuxGnuBin
            ];

            shellHook = ''
              setup-old-gcc "''$PWD"
              p="${crossBt}/bin/${crossTriplet}"
              export PATH="${mipselLinuxGnuBin}/bin:''$PATH"
              export MAKEFLAGS="AS=''$p-as LD=''$p-ld AR=''$p-ar NM=''$p-nm OBJDUMP=''$p-objdump OBJCOPY=''$p-objcopy RANLIB=''$p-ranlib READELF=''$p-readelf SIZE=''$p-size ''$MAKEFLAGS"
              echo "Run: make check"
            '';
          };
        });
    };
}
