# FE-C-Build Kernel

Engine-hacks for FE-Cbuild, including skillsys, battle-system hacks, etc. But the irrelevant parts were stripped away, such as banims, portraits, P/J game info, etc. Such contants which are not related to wizardry is put outside.

Main purpose to split kernel form c-build is to make it independent form the wizardry to the real game. Such as: if I want to make another game based on wizardry output of this project, I just need a copy of Kernel, and the None-kernel contants can be directly replaced.

You can directly build kernel by `make -j` here.
