DISKIMAGE      := disks/$(DISKCODE).bin
DISKCONFIG     := config/$(DISKCODE).xml
DISKLBA        := $(BUILD)/config/$(DISKCODE)_LBA.txt
PSXISO         := tools/mkpsxiso
PSXISOBUILD    := $(PSXISO)/build
DUMPSXISO      := $(PSXISOBUILD)/Release/dumpsxiso
MKPSXISO       := $(PSXISOBUILD)/Release/mkpsxiso
DUMPSXISOFLAGS := -x data -s $(DISKCONFIG)
MKPSXISOFLAGS  := -q -lba -noisogen

BUILDDEPS  += $(DUMPSXISO)
PYTHONDEPS += pandas

$(DISKCONFIG): | $(DISKIMAGE) $$(BUILDDEPS)
	$(ECHO) Dumping files from disk
	$(DUMPSXISO) $(DUMPSXISOFLAGS) $(DISKIMAGE) $(if $(DEBUG),,> /dev/null)

$(DISKLBA): | $$(@D)/
	$(ECHO) Generating $@
	$(MKPSXISO) $(MKPSXISOFLAGS) $(DISKCONFIG)
	$(MV) $(@F) $(BUILD)/config/

$(BUILD)/src/include/lbas.h: $(DISKLBA) | $$(@D)/
	$(ECHO) Generating $@
	$(VPYTHON) tools/etc/make_lba_import.py $< $@

$(DUMPSXISO):
	$(ECHO) Building mkpsxiso
	$(CMAKE) -S $(PSXISO) -B $(PSXISOBUILD) --preset release --log-level=ERROR \
		$(if $(DEBUG),,> /dev/null)
	$(CMAKE) --build $(PSXISOBUILD) -j --config Release $(if $(DEBUG),,> /dev/null)

$(DISKIMAGE):
	$(ECHO) $@ not found
	false
