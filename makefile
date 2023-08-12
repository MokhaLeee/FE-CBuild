MAKEFLAGS += --no-print-directory

CACHE_DIR := .cache_dir
$(shell mkdir -p $(CACHE_DIR) > /dev/null)

TOOL_DIR := Tools
LIB_DIR  := $(TOOL_DIR)/FE-CLib-Mokha

FE8_GBA := fe8.gba
FE8_REF := $(LIB_DIR)/reference/fireemblem8.ref.s
FE8_SYM := $(LIB_DIR)/reference/fireemblem8.sym
EXT_REF := usr-defined.ref.s

MAIN    := main.event
FE8_CHX := fe8-chax.gba

CLEAN_FILES :=
CLEAN_DIRS  := $(CACHE_DIR) $(shell find -name __pycache__)

WIZARDRY_DIR := Wizardry
CONTANTS_DIR := Contants
GAMEDATA_DIR := GameData
HACK_DIRS    := $(WIZARDRY_DIR) $(CONTANTS_DIR) $(GAMEDATA_DIR)

# =========
# = Tools =
# =========

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

EA_DIR            := $(TOOL_DIR)/EventAssembler
EA                := $(EA_DIR)/ColorzCore$(EXE)
PARSEFILE         := $(EA_DIR)/Tools/ParseFile$(EXE)
PORTRAITFORMATTER := $(EA_DIR)/Tools/PortraitFormatter$(EXE)
PNG2DMP           := $(EA_DIR)/Tools/Png2Dmp$(EXE)
COMPRESS          := $(EA_DIR)/Tools/compress$(EXE)
LYN               := $(EA_DIR)/Tools/lyn$(EXE) -longcalls
EA_DEP            := $(EA_DIR)/ea-dep$(EXE)

PORTRAIT_PROCESS  := $(PYTHON3) $(TOOL_DIR)/FE-PyTools/portrait-process.py
TEXT_PROCESS      := $(PYTHON3) $(TOOL_DIR)/FE-PyTools/text-process-classic.py
C2EA              := $(PYTHON3) $(TOOL_DIR)/FE-PyTools/NMM2CSV/c2ea.py
TMX2EA            := $(PYTHON3) $(TOOL_DIR)/FE-PyTools/TMX2EA/tmx2ea.py

GRIT              := $(DEVKITPRO)/tools/bin/grit$(EXE)

# ========
# = Main =
# ========

MAIN_DEPS := $(shell $(EA_DEP) $(MAIN) -I $(EA_DIR) --add-missings)

$(FE8_CHX): $(MAIN) $(FE8_GBA) $(FE8_SYM) $(MAIN_DEPS)
	@echo "[GEN]	$@"
	@cp -f $(FE8_GBA) $(FE8_CHX)
	@$(EA) A FE8 -input:$(MAIN) -output:$(FE8_CHX) --nocash-sym || rm -f $(FE8_CHX)
	@cat $(FE8_SYM) >> $(FE8_CHX:.gba=.sym)

CLEAN_FILES += $(FE8_CHX)  $(FE8_CHX:.gba=.sym)

# ============
# = Wizardry =
# ============

INC_DIRS := include $(LIB_DIR)/include
INC_FLAG := $(foreach dir, $(INC_DIRS), -I $(dir))

ARCH    := -mcpu=arm7tdmi -mthumb -mthumb-interwork
CFLAGS  := $(ARCH) $(INC_FLAG) -Wall -Wextra -Wno-unused-parameter -O2 -mtune=arm7tdmi -mlong-calls
ASFLAGS := $(ARCH) $(INC_FLAG)

CDEPFLAGS = -MMD -MT "$*.o" -MT "$*.asm" -MF "$(CACHE_DIR)/$(notdir $*).d" -MP
SDEPFLAGS = --MD "$(CACHE_DIR)/$(notdir $*).d"

LYN_REF := $(CACHE_DIR)/lyn-ref.o

$(LYN_REF): $(FE8_REF) $(EXT_REF)
	@echo "[AS ]	$@"
	@cp $(FE8_REF) $(LYN_REF:.o=.s)
	@cat $(EXT_REF) >> $(LYN_REF:.o=.s)
	@$(AS) $(LYN_REF:.o=.s) -o $@

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

# Grit related
%.img.bin %.map.bin %.pal.bin: %.png
	@echo "[GEN]	$@"
	@$(GRIT) $< -gB 4 -gzl -m -mLf -mR4 -mzl -pn 16 -ftb -fh! -o $@

CLEAN_FILES += $(PNG_FILES:.png=.img.bin) $(PNG_FILES:.png=.map.bin) $(PNG_FILES:.png=.pal.bin)

# ==========
# = Banims =
# ==========

BANIM_DIR     := Contants/Banim
BANIM_SRC_DIR := $(BANIM_DIR)/Source
BANIM_SOURCES := $(shell find $(BANIM_SRC_DIR) -type f -name '*.txt')

%Installer.event: %.txt
	@$(MAKE) -f $(BANIM_DIR)/makefile $@

CLEAN_FILES += $(BANIM_SOURCES:.txt=Installer.event)

# ============
# = Portrait =
# ============

PORTRAIT_DIR       := Contants/Portrait
PORTRAIT_LIST      := $(PORTRAIT_DIR)/PortraitList.txt
PORTRAIT_INSTALLER := $(PORTRAIT_DIR)/Portraits.event

PORTRAIT_DEPS := $(shell $(PORTRAIT_PROCESS) $(PORTRAIT_LIST) --list-files)

$(PORTRAIT_INSTALLER): $(PORTRAIT_LIST) $(PORTRAIT_DEPS)
	@echo "[GEN]	$@"
	@$(PORTRAIT_PROCESS) $< --output $@

%_mug.dmp %_palette.dmp %_frames.dmp %_minimug.dmp: %.png
	@echo "[GEN]	$@"
	@$(PORTRAITFORMATTER) $<

CLEAN_FILES += $(PORTRAIT_DEPS) $(PORTRAIT_INSTALLER)

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
clean:
	@rm -f $(CLEAN_FILES)
	@rm -rf $(CLEAN_DIRS)
	@echo "cleaned .."
