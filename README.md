# Anchor
A stack-based esolang

There are two registers, A and B, as well as a stack. Everything is stored as a single bit. Instructions are seperated by spaces. In order to push a number onto the stack, simply put the number. 
```
 - [pop] Pop the top item into register A
 - [psh] Push register A onto the stack, keep what's in register A
 - [swp] Swap register A and B
 - [out] Print register A 
 - [inp] Take input and store it in register A
 - [jmp x] Jump to instruction x if register A is 1
```
'\n', '\t', and ' ' are whitespaces. 

## Preprocessor
The preprocessor compiles input to pure Anchor. Everything must be in a main macro.  
To declare a macro, type :name. Everything after that until the next macro is part of that macro.  
In order to call that macro, type @name. It must be already declared. Macros can't call themselves.  
In order to declare a global label, type .name.  
In order to call that label, type &label.  
