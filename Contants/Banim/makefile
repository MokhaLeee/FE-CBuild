mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))
build_dir := $(shell pwd)

AAA := python3 $(mkfile_dir)Scripts/AAA.py

SOURCE_DIR := $(mkfile_dir)Source
ALL_SOURCE_BANIM := $(shell find $(SOURCE_DIR) -type f -name '*.txt')
ALL_TARGET_BANIM := $(ALL_SOURCE_BANIM:.txt=Installer.event)

all: $(ALL_TARGET_BANIM)

%Installer.event: %.txt
	@echo "[AAA]	$@"
	@cd $(dir $<) && $(AAA) $(notdir $<) && cd $(build_dir)

clean:
	rm -f $(ALL_TARGET_BANIM)
