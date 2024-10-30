### **1. Basic Instruction Tracing**

```
mov eax, 5
mov ebx, 3
add eax, ebx
```

1. What is the final value in the **EAX** register after these instructions?
8 

---

### **2. Conditional Branching**

```
mov eax, 10
cmp eax, 5
jg greater_label
mov eax, 1
jmp end_label

greater_label:
mov eax, 0

end_label:
```

1. Will the CPU jump to **greater_label**? Why or why not?
Yes, the comparison is tru  (`EAX > 5` )
1. What will the value of **EAX** be at the end of execution?
0
---

### **3. Loop Tracing with Conditional Check**

```
mov ecx, 5
mov eax, 0

loop_start:
add eax, 1
cmp ecx, 0
je end_loop
sub ecx, 1
jmp loop_start

end_loop:
```

1. How many times will the **loop_start** block execute before exiting the loop?
6
1. What will the value of **EAX** be after the loop finishes?
6
---

### **4. Understanding Flags**

```
mov eax, 3
sub eax, 3
cmp eax, 0
je zero_label

zero_label:
```

1. Will the CPU jump to **zero_label**? Why or why not?
Yes, 3 is added and then substracted from the EAX before the comparasion
1. Which flag determines whether the jump occurs?
**Zero Flag**
1. What would happen if the instruction **sub eax, 3** was changed to **sub eax, 2**?
The CPU would NOT jump to **zero_label**
---

### **5. Memory Addressing**

```
mov eax, [0x1000]
mov [ebx], 5
```

1. If **0x1000** contains the value **10**, what will be in **EAX** after the first instruction?
10
3. If **EBX** contains the value **0x2000**, where will the value **5** be stored?
0x2000

---

### **6. Data Types**

```
mov al, 0xFF
mov ah, 0x00
```

1. What will the full 16-bit value of **AX** be after these instructions?
`F`
1. If the instruction **mov eax, 0xFFFFFFFF** is added afterward, what will be the value of **EAX**?
`FF`
---

### **7. Realistic Endianness Example**

Consider the value `0x1234ABCD` stored in memory starting at address `0x2000` in **little-endian format**.

1. How will the value be laid out in memory? Indicate the value stored at each memory address starting from `0x2000`.
`0x2000` | CD
`0x2001` | AB
`0x2002` | 34
`0x2003` | 12

---

### **8. Conditional Logic II**

```

mov eax, 8
cmp eax, 10
jle less_or_equal_label
mov

 eax, 15
jmp end_label

less_or_equal_label:
mov eax, 5

end_label:
```

1. What will be the final value of **EAX** after this code executes? Trace the program and explain your answer.
5
---

### **9. GDB Disassembly of a Function**

```

0x08049060 <+0>:    mov    eax,0x0          
0x08049065 <+5>:    mov    ebx,0x14         
0x0804906a <+10>:   and    eax,0x1          
0x0804906d <+13>:   jne    0x08049075       
0x0804906f <+15>:   call   print_eax        
0x08049075 <+20>:   inc    eax              
0x08049078 <+23>:   cmp    eax,ebx          
0x0804907b <+26>:   jle    0x0804906a       
0x08049080 <+31>:   call   exit_program     
```

### **Questions**:

1. Trace the execution of the program step-by-step, showing the value of **EAX** for each iteration.
```
Move 0 into EAX
Move 0x14 (decimal 20) into EBX register
-- loop start --
EAX (0) & 1 = 0 = (ZERO FLAG SET)
JUMP if Not Equal = JUMP Zero Flag is NOT set, but (ZERO FLAG IS SET) so on this iteration we continue to print
Print EAX (0)
INCREMENT EAX (EAX = 1)
COMPARE EAX (1) <= EBX (20)
JUMP to 0x0804906a (start of loop)

EAX (1) & 1 = 1 = ZERO FLAG NOT SET
JUMP if Not Equal = JUMP Zero Flag is NOT set (ZERO FLAG IS NOT SET) so on this iteration we JUMP 0x08049075 
JUMP (jumping over print) to 0x08049075 (increment instruction)
INCREMENT EAX (EAX = 2)
COMPARE EAX (2) <= EBX (20)
JUMP to 0x0804906a (start of loop)

0 0 1 0
0 0 0 1 &
---------
0 0 0 0

EAX (2) & 1 = 0 (See above) = ZERO FLAG SET 
JUMP if Not Equal = JUMP Zero Flag is NOT set, but (ZERO FLAG IS SET) so on this iteration we continue to print
Print EAX (2)
INCREMENT EAX (EAX = 3)
COMPARE EAX (3) <= EBX (20)
JUMP to 0x0804906a (start of loop)

I now see the pattern, this is a loop that will print all even numbers upto and including 20


```
1. Indicate which values of **EAX** are printed during the loop.
All even numbers
3. Based on the disassembly, explain the purpose of the function and how the loop behaves.
Prints all even numbers by checking if the current ith value is even, if it is then i is printed, else the loop continues incrementing i until i > 20
