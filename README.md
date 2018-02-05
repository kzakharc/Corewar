# Corewar
Algorithmic Project. ASM and Virtual Machine.

This project can be broken down into three distinctive parts:
• The assembler: this is the program that will compile your champions and translate
them from the language you will write them in (assembly language) into “Bytecode”.Bytecode
is a machine code, which will be directly interpreted by the virtual
machine.
• The virtual machine: It’s the “arena” in which your champions will be executed.
It offers various functions, all of which will be useful for the battle of the champions.
Obviously, the virtual machine should allow for numerous simultaneous processes;
we are asking you for a gladiator fight, not a one-man show simulator.
• The champion: This one is a special case. Later, in the championship, you will
need to render a super powerful champion, who will scare the staff team to death.
However, rendering this kind of champion is serious work. And since, for now, we
are mostly interested in your capacity to create Corewar’s other programs (i.e. the
assembler and virtual machine), your current champion will only need to prove to
us that you can write bits and pieces of Corewar ASM. This means that the champion
you should render for this project only needs to scare the bejesus out of a
neurasthenic hedgehog.

-- Installing:
>make

-- Creating champions with asm:
```
./asm ./examples_assembler/<*.s>
will create .cor source files to be launched by ./corewar executable
-a : Instead of creating a .cor file, outputs a stripped and annotated version of the code to the standard output
```

-- Corewar usage:
```
>./corewar     [-dump nbr_cycles] [-n number] [-v] [-a] <champion1.cor> <...>
    -a               : Prints output from "aff" (Default is to hide it)
    -n number        : Sets the number of the next player
###################### MAP OUTPUT MODE #########################
    -dump nbr_cycles : Dumps memory after nbr_cycles then exits
#################### NCURSES OUTPUT MODE #######################
    -v               : Ncurses output mode
```

Authors:
Katerina Zakharchuk - Assembler [kzakharc](https://github.com/kzakharc)

Vitalii Poltavets - Virtual machine [ChoadPet](https://github.com/ChoadPet)

Yaroslav Zakharchuk - Virtual machine [ElCorte](https://github.com/yaro-zakh)

Dmitry Spiridonov - Ncurses visualisation [d-spiridonov](https://github.com/d-spiridonov)
