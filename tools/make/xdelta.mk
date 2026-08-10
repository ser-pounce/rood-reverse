XDELTA         ?= tools/xdelta/xdelta3
XDELTA_VERSION ?= 3.2.0

BUILDDEPS += $(XDELTA)

$(XDELTA): TARFLAGS += -C $(@D) --strip-components=1 -xf
$(XDELTA): | $$(@D)/
	$(ECHO) Downloading Xdelta
	$(WGET) $(WGETFLAGS) https://github.com/jmacd/xdelta/releases/download/v$(XDELTA_VERSION)/xdelta3-$(XDELTA_VERSION)-linux-x86_64.tar.gz -O $(@D)/xdelta3.tar.gz
	$(TAR) $(TARFLAGS) $(@D)/xdelta3.tar.gz
	$(RM) $(RMFLAGS) $(@D)/xdelta3.tar.gz
