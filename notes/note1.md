## Part 2 the loader

1. At what point does the processor start executing 32-bit code? What exactly \
causes the switch from 16- to 32-bit mode?

After running the line,
  ljmp    $PROT_MODE_CSEG, $protcseg

Set up GDT and set protected mode.

2. What is the last instruction of the boot loader executed, and what is the \
first instruction of the kernel it just loaded?

The last instruction is `((void (*)(void)) (ELFHDR->e_entry))();`,
`call   *0x10018`.

The first instruction of the kernel is `movw   $0x1234,0x472`.

3. Where is the first instruction of the kernel?

entry.S
4. How does the boot loader decide how many sectors it must read in order to \
fetch the entire kernel from disk? Where does it find this information?

ELF header has the information of total size, which is e_phnum.

Changing the load address to 0x7c04 will cause instructions like `ljmp` fail
because the dest address is affected.

Exercise 6:
The main.c has loaded the sectors of program after entering the kernel.
