# Anchor
A stack-based esolang

There are two registers, A and B, as well as a stack. Everything is stored as a single bit. Instructions are seperated by spaces. In order to push a number onto the stack, simply put the number. 
```
 - [pop] Pop the top item into register A
 - [psh] Push register A onto the stack, keep what's in register A
 - [swp] Swap register A and B
 - [out] Print register A 
 - [inp] Take input and store it in register A
 - [jmp|x] Jumps to instruction x if register A is 1
```
'\n', '\t', ' ', and '|' are whitespaces. 
