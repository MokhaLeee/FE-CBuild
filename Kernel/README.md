# FE-C-Build Kernel

Engine-hacks for FE-Cbuild, including skillsys, battle-system hacks, etc. But the irrelevant parts were stripped away, such as banims, portraits, P/J game info, etc. Such contants which are not related to wizardry is put outside.

Main purpose to split kernel form c-build is to make it independent form the wizardry to the real game. Such as: if I want to make another game based on wizardry output of this project, I just need a copy of Kernel, and the None-kernel contants can be directly replaced.

You can directly build kernel by `make -j` here.

## Build Chinese version

This repo support multi-language. For now, Chinese is supported, if you want to use Chinese version of kernel, follow these steps before `make`:

- Uncomment `include Fonts/fonts.mk` in **./makefile**:
- Uncomment `CONFIG_LANG_CHINESE` in **./Configs/configs.h**
- Uncomment `#include "Fonts/Fonts.event"` in **./main.event**
- Modify on **./Contants/Texts/Source/TextMain.txt**, use `texts-cn.txt` rather than `texts.txt`
