MENU7   := MENU/MENU7.PRG
MENU7.o := $(BUILD)/src/$(MENU7)/260.o

$(BUILD)/config/$(MENU7)/link.d: $(patsubst %,config/%/symbol_addrs.txt,SLUS_010.40 BATTLE/BATTLE.PRG MENU/MAINMENU.PRG)

$(BUILD)/data/$(MENU7).elf: LDFLAGS += \
	--retain-symbols-file=config/$(MENU7)/exports.txt

$(MENU7.o): ASFLAGS += -no-pad-sections
$(MENU7.o): CC1VER := 2.8.1-psx
