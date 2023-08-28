mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))
build_dir := $(shell pwd)

ICON_GENERATOR := $(mkfile_dir)Scripts/sicon-installer.sh

SOURCE_DIR := $(mkfile_dir)Sources/
ALL_SOURCES := $(shell find $(SOURCE_DIR)/ -type f -name '*.png')
INSTALLER := $(mkfile_dir)SkillIconInstaller.event
HEADER := $(mkfile_dir)SkillIconDefs.h

$(HEADER) $(INSTALLER): $(ALL_SOURCES)
	@echo "[GEN]	$@"
	@cd $(dir $@) && $(ICON_GENERATOR) && cd $(build_dir)

clean:
	rm -f $(HEADER) $(INSTALLER)
