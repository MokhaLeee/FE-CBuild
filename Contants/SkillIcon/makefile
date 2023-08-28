mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir  := $(dir $(mkfile_path))
build_dir   := $(shell pwd)

ICON_GENERATOR := $(mkfile_dir)Scripts/sicon-installer.sh

SOURCE_DIR  := $(mkfile_dir)Sources/
ALL_SOURCES := $(shell find $(SOURCE_DIR)/ -type f -name '*.png')

SICON_HEADER    ?= $(mkfile_dir)SkillIconDefs.h
SICON_INSTALLER ?= $(mkfile_dir)SkillIconInstaller.event

$(SICON_HEADER) $(SICON_INSTALLER): $(ALL_SOURCES)
	@echo "[GEN]	$@"
	@cd $(dir $(mkfile_dir)..) && $(ICON_GENERATOR) $(SICON_HEADER) $(SICON_INSTALLER) && cd $(build_dir)

clean:
	rm -f $(SICON_HEADER) $(SICON_INSTALLER)
