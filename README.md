# Anchor
A stack-based esolang that uses anchors  

All instructions are separated by a space. In order to push an integer onto the stack, simply put the number. There are two registers, register A and register B. Anchors divide the stack into sectors. The top-most segment is segment 0. Everything after :main is executed as code. Below are all the instructions in Anchor:
```
 - [ppa] Pop the top item into register A
 - [ppb] Pop the top item into register B
 - [psa] Duplicate register A and push it 
 - [psb] Duplicate register B and push it 
 - [swp] Swap the positions of the sectors indicated in registers A and B
 - [dup] Duplicate the sector indicated in register A
 - [del] Remove the sector indicated in register B
 - [dch] Remove the top-most anchor
 - [!] Push an anchor onto the stack
 - [@] Push the current value of the program counter into register A
 - [+] Add register A and B, and push the result onto the stack
 - [-] Subtract register B from register A, and push the result onto the stack
 - [prt] Print register A as an ascii character
 - [out] Print register A as a number
 - [ina] Take a single ascii character as input, and store it in register A
 - [inp] Take a number as input, and store it in register B
 - [jmp] Jump to the index stored in register A
 - [ife] Perform the next operation if the two registers are equal
 - [ifg] Perform the next operation if register A is greater than register B
 - [ifl] Perform the next operation if register A is less than register B
 - [hlt] Halt the program
```
### Implementation details
In this implementation values are 32 bit integers. Illegal operations are simply skipped. 
