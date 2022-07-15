# Anchor
A stack-based esolang

There are two single bit register, A and B, one unsigned unbounded register, C, and one stack with single bit elements. Instructions are seperated by spaces, new lines, and tabs. 
```
 - [pop] Pop the top item of the stack into register A
 - [psh] Push register A onto the stack, keep the value of register A
 - [swp] Swap registers A and B
 - [inp] Take input into register A
 - [out] Print register A
 - [con] if A == 0 -> C--; if A == 1 -> C++
 - [jmp-x] Jump to instruction x if C.size() == 0
 - [0] Push 0 onto the stack
 - [1] Push 1 onto the stack
 - [#] Value of C. Used with jumps
```
## Preprocessor
The preprocessor compiles input to pure Anchor. Everything executed must be in a main macro.  
To declare a macro, type :name. Everything after that until the next macro is part of that macro.  
In order to call that macro, type @name. It must be already declared. Macros can't call themselves.  
In order to declare a global label, type .name.  
In order to call that label, type &label.  
