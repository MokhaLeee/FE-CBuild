MAKEFLAGS += --no-print-directory
CACHE_DIR := $(MK_DIR).cache_dir
$(shell mkdir -p $(CACHE_DIR) > /dev/null)

MK_PATH   := $(abspath $(lastword $(MAKEFILE_LIST)))
MK_DIR    := $(dir $(MK_PATH))
BUILD_DIR := $(shell pwd)

MAIN    := $(MK_DIR)main.event
FE8_CHX := $(MK_DIR)fe8-chax.gba

KERNEL_DIR := $(MK_DIR)Kernel
KERNEL_GBA := $(KERNEL_DIR)/fe8-kernel.gba
KERNEL_SYM := $(KERNEL_DIR)/fe8-kernel.sym
K_REF      := $(CACHE_DIR)/kernel.ref.s

TOOL_DIR   := $(MK_DIR)Tools
KTOOL_DIR := $(KERNEL_DIR)/Tools
LIB_DIR   := $(KTOOL_DIR)/FE-CLib-Mokha
FE8_REF   := $(LIB_DIR)/reference/fireemblem8.ref.o
FE8_SYM   := $(LIB_DIR)/reference/fireemblem8.sym

KERNEL_MK  := $(TOOL_DIR)/Scripts/kernel.mk

CONFIG_DIR := $(KERNEL_DIR)/Configs
EXT_REF    := $(CONFIG_DIR)/usr-defined.ref.s

GAMEDATA_DIR := $(MK_DIR)GameData
CONTANTS_DIR := $(MK_DIR)Contants
HACK_DIRS := $(CONFIG_DIR) $(GAMEDATA_DIR) $(CONTANTS_DIR)

CLEAN_FILES :=
CLEAN_DIRS  := $(CACHE_DIR) $(shell find -name __pycache__)
CLEAN_BUILD :=

# =========
# = Tools =
# =========

ifeq ($(strip $(DEVKITPRO)),)
	$(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path to>devkitpro)
endif

ifeq ($(strip $(DEVKITARM)),)
	$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM)
endif

TOOLCHAIN ?= $(DEVKITARM)
ifneq (,$(TOOLCHAIN))
	export PATH := $(TOOLCHAIN)/bin:$(PATH)
endif

ifeq ($(OS),Windows_NT)
	EXE := .exe
else
	EXE :=
endif

ifeq ($(shell python3 -c 'import sys; print(int(sys.version_info[0] > 2))'),1)
	PYTHON3 := python3
else
	PYTHON3 := python
endif

PREFIX  ?= arm-none-eabi-
CC      := $(PREFIX)gcc
AS      := $(PREFIX)as
OBJCOPY := $(PREFIX)objcopy

EA_DIR            := $(KTOOL_DIR)/EventAssembler
EA                := $(EA_DIR)/ColorzCore$(EXE)
PARSEFILE         := $(EA_DIR)/Tools/ParseFile$(EXE)
PORTRAITFORMATTER := $(EA_DIR)/Tools/PortraitFormatter$(EXE)
PNG2DMP           := $(EA_DIR)/Tools/Png2Dmp$(EXE)
COMPRESS          := $(EA_DIR)/Tools/compress$(EXE)
LYN               := $(EA_DIR)/Tools/lyn$(EXE) -longcalls
EA_DEP            := $(EA_DIR)/ea-dep$(EXE)

TEXT_PROCESS      := $(PYTHON3) $(KTOOL_DIR)/FE-PyTools/text-process-classic.py
C2EA              := $(PYTHON3) $(KTOOL_DIR)/FE-PyTools/NMM2CSV/c2ea.py
TMX2EA            := $(PYTHON3) $(KTOOL_DIR)/scripts/tmx2ea-mokha.py
GRIT              := $(DEVKITPRO)/tools/bin/grit$(EXE)

PORTRAIT_PROCESS  := $(PYTHON3) $(KTOOL_DIR)/scripts/portrait-process-mokha.py
SYM2REF           := $(PYTHON3) $(TOOL_DIR)/Scripts/sym-to-ref.py

# ========
# = Main =
# ========

all:
	@$(MAKE) pre_build kernel
	@$(MAKE) chax

pre_build: portrait text
chax: $(FE8_CHX)

$(FE8_CHX): $(MAIN) $(KERNEL_GBA) $(KERNEL_SYM) $(shell $(EA_DEP) $(MAIN) -I $(EA_DIR) --add-missings)
	@echo "[GEN]	$@"
	@cp -f $(KERNEL_GBA) $(FE8_CHX)
	@$(EA) A FE8 -werr -input:$(MAIN) -output:$(FE8_CHX) --nocash-sym || rm -f $(FE8_CHX)
	@cat $(KERNEL_SYM) >> $(FE8_CHX:.gba=.sym)
	@cat $(FE8_SYM) >> $(FE8_CHX:.gba=.sym)

$(KERNEL_GBA): kernel

kernel:
	$(MAKE) -f $(KERNEL_MK) all

$(K_REF): $(KERNEL_SYM)
	$(SYM2REF) $< > $@

# ============
# = Wizardry =
# ============

INC_DIRS := include $(LIB_DIR)/include $(KERNEL_DIR)/include
INC_FLAG := $(foreach dir, $(INC_DIRS), -I $(dir))

ARCH    := -mcpu=arm7tdmi -mthumb -mthumb-interwork
CFLAGS  := $(ARCH) $(INC_FLAG) -Wall -Wextra -Werror -Wno-unused-parameter -O2 -mtune=arm7tdmi -mlong-calls
ASFLAGS := $(ARCH) $(INC_FLAG)

CDEPFLAGS = -MMD -MT "$*.o" -MT "$*.asm" -MF "$(CACHE_DIR)/$(notdir $*).d" -MP
SDEPFLAGS = --MD "$(CACHE_DIR)/$(notdir $*).d"

LYN_REF := $(EXT_REF:.s=.o) $(K_REF:.s=.o)

%.lyn.event: %.o $(LYN_REF)
	@echo "[LYN]	$@"
	@$(LYN) $< $(LYN_REF) > $@

%.dmp: %.o
	@echo "[GEN]	$@"
	@$(OBJCOPY) -S $< -O binary $@

%.o: %.s
	@echo "[AS ]	$@"
	@$(AS) $(ASFLAGS) $(SDEPFLAGS) -I $(dir $<) $< -o $@

%.o: %.c
	@echo "[CC ]	$@"
	@$(CC) $(CFLAGS) $(CDEPFLAGS) -g -c $< -o $@

%.asm: %.c
	@echo "[CC ]	$@"
	@$(CC) $(CFLAGS) $(CDEPFLAGS) -S $< -o $@ -fverbose-asm

# Avoid make deleting objects it thinks it doesn't need anymore
# Without this make may fail to detect some files as being up to date
.PRECIOUS: %.o;

-include $(wildcard $(CACHE_DIR)/*.d)

CFILES := $(shell find $(HACK_DIRS) -type f -name '*.c')
CLEAN_FILES += $(CFILES:.c=.o) $(CFILES:.c=.asm) $(CFILES:.c=.dmp) $(CFILES:.c=.lyn.event)

SFILES := $(shell find $(HACK_DIRS) -type f -name '*.s')
CLEAN_FILES += $(SFILES:.s=.o) $(SFILES:.s=.dmp) $(SFILES:.s=.lyn.event)

# ============
# = Spritans =
# ============

PNG_FILES := $(shell find $(HACK_DIRS) -type f -name '*.png')
TSA_FILES := $(shell find $(HACK_DIRS) -type f -name '*.tsa')

%.4bpp: %.png
	@echo "[GEN]	$@"
	@$(PNG2DMP) $< -o $@

%.gbapal: %.png
	@echo "[GEN]	$@"
	@$(PNG2DMP) $< -po $@ --palette-only

%.lz: %
	@echo "[LZ ]	$@"
	@$(COMPRESS) $< $@

CLEAN_FILES += $(PNG_FILES:.png=.gbapal) $(PNG_FILES:.png=.4bpp) $(PNG_FILES:.png=.4bpp.lz)
CLEAN_FILES += $(TSA_FILES:.tsa=.tsa.lz)

%.img.bin %.map.bin %.pal.bin: %.png
	@echo "[GEN]	$@"
	@$(GRIT) $< -gB 4 -gzl -m -mLf -mR4 -mzl -pn 16 -ftb -fh! -o $@

CLEAN_FILES += $(PNG_FILES:.png=.img.bin) $(PNG_FILES:.png=.map.bin) $(PNG_FILES:.png=.pal.bin)

# =========
# = Texts =
# =========

TEXT_DIR     := $(CONTANTS_DIR)/Texts
TEXT_MAIN   := $(TEXT_DIR)/Source/TextMain.txt
TEXT_SOURCE := $(shell find $(TEXT_DIR) -type f -name '*.txt')

export TEXT_DEF := $(TEXT_DIR)/TextDefinitions.h

text: $(TEXT_DEF)

$(TEXT_DEF): $(TEXT_MAIN) $(TEXT_SOURCE)
	@$(MAKE) -C $(TEXT_DIR)

%.fetxt.dmp: %.fetxt
	@$(MAKE) -f $(TEXT_DIR)/makefile $@

CLEAN_BUILD += $(TEXT_DIR)

# ==========
# = Banims =
# ==========

BANIM_DIR := $(MK_DIR)Contants/Banim

%.banim.event: %.banim.txt
	@$(MAKE) -f $(BANIM_DIR)/makefile $@

CLEAN_BUILD += $(BANIM_DIR)

# ============
# = Portrait =
# ============

PORTRAIT_DIR       := $(MK_DIR)Contants/Portrait
PORTRAIT_LIST      := $(PORTRAIT_DIR)/PortraitList.txt
PORTRAIT_INSTALLER := $(PORTRAIT_DIR)/PortraitInstaller.event
PORTRAIT_HEADER    := $(PORTRAIT_DIR)/PortraitDef.h

portrait: $(PORTRAIT_INSTALLER)

PORTRAIT_DEPS := $(shell $(PORTRAIT_PROCESS) $(PORTRAIT_LIST) --list-files)

$(PORTRAIT_INSTALLER) $(PORTRAIT_HEADER): $(PORTRAIT_LIST) $(PORTRAIT_DEPS)
	@echo "[GEN]	$@"
	@$(PORTRAIT_PROCESS) $< --installer $(PORTRAIT_INSTALLER) --definition $(PORTRAIT_HEADER)

%_mug.dmp %_palette.dmp %_frames.dmp %_minimug.dmp: %.png
	@echo "[GEN]	$@"
	@$(PORTRAITFORMATTER) $<

CLEAN_FILES += $(PORTRAIT_DEPS) $(PORTRAIT_INSTALLER) $(PORTRAIT_HEADER)

# ========
# = MAPS =
# ========

%.event %_data.dmp: %.tmx
	$(NOTIFY_PROCESS)
	@echo | $(TMX2EA) $< > /dev/null

TMXS := $(shell find -type f -name '*.tmx')
CLEAN_FILES += $(TMXS:.tmx=.event) $(TMXS:.tmx=_data.dmp)

# ==========
# = Sounds =
# ==========

SOUND_DIR := $(MK_DIR)Contants/Sounds
SOUND_ASM_SOURCE := $(shell find $(SOUND_DIR)/Songs -type f -name '*.s')

CLEAN_FILES += $(SOUND_ASM_SOURCE:.s=.o) $(SOUND_ASM_SOURCE:.s=.lyn.event)

# ==========
# = Tables =
# ==========

%.csv.event: %.csv %.nmm
	@echo "[GEN]	$@"
	@echo | $(C2EA) -csv $*.csv -nmm $*.nmm -out $@ $(ROM_SOURCE) > /dev/null

CSV_SOURCES := $(shell find $(GAMEDATA_DIR) -type f -name '*.csv')
CLEAN_FILES += $(CSV_SOURCES:.csv=.csv.event)

# ==============
# = MAKE CLEAN =
# ==============

clean_basic:
	@$(MAKE) -f $(KERNEL_MK) $@ > /dev/null
	@rm -f $(CLEAN_FILES)
	@rm -rf $(CLEAN_DIRS)
	@echo "Cleaned .."

clean:
	@for i in $(CLEAN_BUILD); do if test -e $$i/makefile ; then $(MAKE) -f $$i/makefile clean || { exit 1;} fi; done;
	@$(MAKE) clean_basic > /dev/null
	@$(MAKE) -f $(KERNEL_MK) $@ > /dev/null
	@echo "All cleaned .."
