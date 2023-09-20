# What is CHAX

It is origined from [StanHash/FE-CHAX](https://github.com/StanHash/FE-CHAX) with the main purpose to write EngineHacks in C rather than ASM. The early work mainly focus on how to achieve elf2ea (or say, [lyn utilly](https://feuniverse.us/t/ea-asm-tool-lyn-elf2ea-if-you-will/2986)). With the progress on [Decomp](https://github.com/FireEmblemUniverse/fireemblem8u) and other tools such as [ea-dep, a dependence generator](https://github.com/StanHash/ea-dep), now we may go further with the following goals:

1. All components are all generated at once via a `make` command, rather than we compile each *.c* or *.s* file before intergrating to ColorzCore, which requires a better sorting on makefile dependency.
2. Alignment on CHAX and Decomp, which means we could use the same header files and directly port source code from decomp output for our hack.
3. More C-Hacks and less ASM-Hacks.
