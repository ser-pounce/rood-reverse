$(BUILD)/data/EFFECT/%.BIN: LDFLAGS += \
	--defsym=vs_scratch=0x1F800000

$(BUILD)/src/EFFECT/%.o: ASFLAGS += -no-pad-sections

BINARIES += $(patsubst %,EFFECT/%.BIN,EFFPURGE $(addprefix PLG,005 044 045 047 049))
