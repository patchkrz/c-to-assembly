This code read .c file then translates c language to its MSP430 assembly instructions.

At first, code is planned to print the assembly code to the screen. For summation and
subtraction and multiplication, c code works perfectly fine.

Now, function takes an input .c file. Then gives an output .asm file. And the code 
works for just one type of operation at a time. That is to say, when the programmer 
calls for summation, it gives summation assembly. This is valid for other 2 mathematical
operation.

Pseudocode of source code
1 File name is written by user, and program opens it in read mode.
2 "search_block" function finds block statements inside the code.
3 "operator type" funcion looks for mathematical operation (+,-,*)
4 "add_assembly", "sub_assembly", "mult_assembly" functions opens assembly file write 
  mode and makes changes.

.cpp => source file (DEV-C output. Code is written in C.)
.exe => the file that is asked
.c   => input file (test file)
.asm => output file 
