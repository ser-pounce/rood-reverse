DISKLBA        ?= $(BUILD)/config/$(DISKCODE)_LBA.txt
PSXISO_VERSION ?= 2.30
PSXISO         ?= tools/mkpsxiso/
DUMPSXISO      ?= $(PSXISO)dumpsxiso
MKPSXISO       ?= $(PSXISO)mkpsxiso
DUMPSXISOFLAGS ?= -x data -s $(DISKCONFIG)
MKPSXISOFLAGS  ?= -q -lba -noisogen

BUILDDEPS  += $(DUMPSXISO)
PYTHONDEPS += pandas

$(DISKCONFIG): | $(DISKIMAGE)
	$(ECHO) Dumping files from disk
	$(DUMPSXISO) $(DUMPSXISOFLAGS) $(DISKIMAGE) $(if $(DEBUG),,> /dev/null)

$(DISKLBA): | $$(@D)/
	$(ECHO) Generating $@
	$(MKPSXISO) $(MKPSXISOFLAGS) $(DISKCONFIG)
	$(MV) $(@F) $(BUILD)/config/

$(BUILD)/src/include/lbas.h: $(DISKLBA) | $$(@D)/
	$(ECHO) Generating $@
	$(VPYTHON) tools/etc/make_lba_import.py $< $@

$(DUMPSXISO): | $$(@D)/
	$(ECHO) Downloading mkpsxiso
	$(WGET) $(WGETFLAGS) https://github.com/Lameguy64/mkpsxiso/releases/download/v$(PSXISO_VERSION)/mkpsxiso-$(PSXISO_VERSION)-Linux.zip -P $(@D)
	$(UNZIP) $(UNZIPFLAGS) $(@D)/mkpsxiso-$(PSXISO_VERSION)-Linux.zip -d $(@D)
	$(RM) $(RMFLAGS) $(@D)/mkpsxiso-$(PSXISO_VERSION)-Linux.zip

$(DISKIMAGE):
	$(error $@ not found)
