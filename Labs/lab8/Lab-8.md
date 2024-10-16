1. Screenshots or a record of your GDB session, showing the disassembled code for each program
**Simple.C**

```
Dump of assembler code for function main:
   0x5655619d <+0>:	lea    ecx,[esp+0x4]
   0x565561a1 <+4>:	and    esp,0xfffffff0
   0x565561a4 <+7>:	push   DWORD PTR [ecx-0x4]
   0x565561a7 <+10>:	push   ebp
   0x565561a8 <+11>:	mov    ebp,esp
   0x565561aa <+13>:	push   ebx
   0x565561ab <+14>:	push   ecx
   0x565561ac <+15>:	sub    esp,0x10
   0x565561af <+18>:	call   0x565561f8 <__x86.get_pc_thunk.ax>
   0x565561b4 <+23>:	add    eax,0x2e24
=> 0x565561b9 <+28>:	mov    DWORD PTR [ebp-0x14],0x5
   0x565561c0 <+35>:	mov    DWORD PTR [ebp-0x10],0x7
   0x565561c7 <+42>:	mov    ecx,DWORD PTR [ebp-0x14]
   0x565561ca <+45>:	mov    edx,DWORD PTR [ebp-0x10]
   0x565561cd <+48>:	add    edx,ecx
   0x565561cf <+50>:	mov    DWORD PTR [ebp-0xc],edx
   0x565561d2 <+53>:	sub    esp,0x8
   0x565561d5 <+56>:	push   DWORD PTR [ebp-0xc]
   0x565561d8 <+59>:	lea    edx,[eax-0x1fd0]
   0x565561de <+65>:	push   edx
   0x565561df <+66>:	mov    ebx,eax
   0x565561e1 <+68>:	call   0x56556050 <printf@plt>
   0x565561e6 <+73>:	add    esp,0x10
   0x565561e9 <+76>:	mov    eax,0x0
   0x565561ee <+81>:	lea    esp,[ebp-0x8]
   0x565561f1 <+84>:	pop    ecx
   0x565561f2 <+85>:	pop    ebx
   0x565561f3 <+86>:	pop    ebp
   0x565561f4 <+87>:	lea    esp,[ecx-0x4]
   0x565561f7 <+90>:	ret
End of assembler dumP
```

- DWORD PTR making space for variable a
- DWORD PTR making space for variable b
- Add instruction which adds the values
- call to print
**If-statement**
```assembly
Dump of assembler code for function main:
   0x5655619d <+0>:	lea    ecx,[esp+0x4]
   0x565561a1 <+4>:	and    esp,0xfffffff0
   0x565561a4 <+7>:	push   DWORD PTR [ecx-0x4]
   0x565561a7 <+10>:	push   ebp
   0x565561a8 <+11>:	mov    ebp,esp
   0x565561aa <+13>:	push   ebx
   0x565561ab <+14>:	push   ecx
   0x565561ac <+15>:	sub    esp,0x10
   0x565561af <+18>:	call   0x5655620b <__x86.get_pc_thunk.ax>
   0x565561b4 <+23>:	add    eax,0x2e24
=> 0x565561b9 <+28>:	mov    DWORD PTR [ebp-0x10],0xa
   0x565561c0 <+35>:	mov    DWORD PTR [ebp-0xc],0x14
   0x565561c7 <+42>:	mov    edx,DWORD PTR [ebp-0x10]
   0x565561ca <+45>:	cmp    edx,DWORD PTR [ebp-0xc]
   0x565561cd <+48>:	jge    0x565561dc <main+63>
   0x565561cf <+50>:	mov    ecx,DWORD PTR [ebp-0x10]
   0x565561d2 <+53>:	mov    edx,DWORD PTR [ebp-0xc]
   0x565561d5 <+56>:	add    edx,ecx
   0x565561d7 <+58>:	mov    DWORD PTR [ebp-0x14],edx
   0x565561da <+61>:	jmp    0x565561e5 <main+72>
   0x565561dc <+63>:	mov    edx,DWORD PTR [ebp-0x10]
   0x565561df <+66>:	sub    edx,DWORD PTR [ebp-0xc]
   0x565561e2 <+69>:	mov    DWORD PTR [ebp-0x14],edx
   0x565561e5 <+72>:	sub    esp,0x8
   0x565561e8 <+75>:	push   DWORD PTR [ebp-0x14]
   0x565561eb <+78>:	lea    edx,[eax-0x1fd0]
   0x565561f1 <+84>:	push   edx
   0x565561f2 <+85>:	mov    ebx,eax
   0x565561f4 <+87>:	call   0x56556050 <printf@plt>
   0x565561f9 <+92>:	add    esp,0x10
   0x565561fc <+95>:	mov    eax,0x0
   0x56556201 <+100>:	lea    esp,[ebp-0x8]
   0x56556204 <+103>:	pop    ecx
   0x56556205 <+104>:	pop    ebx
   0x56556206 <+105>:	pop    ebp
   0x56556207 <+106>:	lea    esp,[ecx-0x4]
   0x5655620a <+109>:	ret
End of assembler dump.
```
- mov DWORD PTR [ebp-0x10],0xa | Corresponds to `int x = 10;`
- 0x565561c0: mov DWORD PTR [ebp-0xc],0x14 | Corresponds to `int y = 20;`
```
0x565561c7: mov edx,DWORD PTR [ebp-0x10]
0x565561ca: cmp edx,DWORD PTR [ebp-0xc]
0x565561cd: jge 0x565561dc <main+63>
```
- These instructions compare `x` and `y` for the `if (x < y)` condition.
- `0x565561cf - 0x565561d7` | result = x + y; in the if block.
- `0x565561dc - 0x565561e2` | instructions correspond to `result = x - y;`
- `0x565561e5 - 0x565561f9` | set up and call the `printf` function.
- `0x565561fc - 0x5655620a` return 0;
**With an loop**
```
Dump of assembler code for function main:
   0x5655619d <+0>:	lea    ecx,[esp+0x4]
   0x565561a1 <+4>:	and    esp,0xfffffff0
   0x565561a4 <+7>:	push   DWORD PTR [ecx-0x4]
   0x565561a7 <+10>:	push   ebp
   0x565561a8 <+11>:	mov    ebp,esp
   0x565561aa <+13>:	push   ebx
   0x565561ab <+14>:	push   ecx
   0x565561ac <+15>:	sub    esp,0x10
   0x565561af <+18>:	call   0x565561ff <__x86.get_pc_thunk.ax>
   0x565561b4 <+23>:	add    eax,0x2e24
=> 0x565561b9 <+28>:	mov    DWORD PTR [ebp-0x10],0x0
   0x565561c0 <+35>:	mov    DWORD PTR [ebp-0xc],0x0
   0x565561c7 <+42>:	jmp    0x565561d3 <main+54>
   0x565561c9 <+44>:	mov    edx,DWORD PTR [ebp-0xc]
   0x565561cc <+47>:	add    DWORD PTR [ebp-0x10],edx
   0x565561cf <+50>:	add    DWORD PTR [ebp-0xc],0x1
   0x565561d3 <+54>:	cmp    DWORD PTR [ebp-0xc],0x4
   0x565561d7 <+58>:	jle    0x565561c9 <main+44>
   0x565561d9 <+60>:	sub    esp,0x8
   0x565561dc <+63>:	push   DWORD PTR [ebp-0x10]
   0x565561df <+66>:	lea    edx,[eax-0x1fd0]
   0x565561e5 <+72>:	push   edx
   0x565561e6 <+73>:	mov    ebx,eax
   0x565561e8 <+75>:	call   0x56556050 <printf@plt>
   0x565561ed <+80>:	add    esp,0x10
   0x565561f0 <+83>:	mov    eax,0x0
   0x565561f5 <+88>:	lea    esp,[ebp-0x8]
   0x565561f8 <+91>:	pop    ecx
   0x565561f9 <+92>:	pop    ebx
   0x565561fa <+93>:	pop    ebp
   0x565561fb <+94>:	lea    esp,[ecx-0x4]
   0x565561fe <+97>:	ret
End of assembler dump.
```

**Breakdown**
 `0x5655619d - 0x565561b4` 
 Setup stack frame
 
 `0x565561b9 <+28>: mov DWORD PTR [ebp-0x10],0x0`  
 `int sum = 0`
 
 `0x565561c0 <+35>:	mov    DWORD PTR [ebp-0xc],0x0` 
 `int i = 0;`
 ``
 ```
 0x565561c7 <+42>:	jmp    0x565561d3 <main+54>
   0x565561c9 <+44>:	mov    edx,DWORD PTR [ebp-0xc]
   0x565561cc <+47>:	add    DWORD PTR [ebp-0x10],edx
   0x565561cf <+50>:	add    DWORD PTR [ebp-0xc],0x1
   0x565561d3 <+54>:	cmp    DWORD PTR [ebp-0xc],0x4
   0x565561d7 <+58>:	jle    0x565561c9 <main+44>
```
corresponds to `for (; i < 5; ) {` (<= 4 is the same as < 5)

```
 0x565561c9 <+44>:	mov    edx,DWORD PTR [ebp-0xc]
   0x565561cc <+47>:	add    DWORD PTR [ebp-0x10],edx
   0x565561cf <+50>:	add    DWORD PTR [ebp-0xc],0x1

```
Loop body `sum += i; i++;`

```
   0x565561d9 <+60>:	sub    esp,0x8
   0x565561dc <+63>:	push   DWORD PTR [ebp-0x10]
   0x565561df <+66>:	lea    edx,[eax-0x1fd0]
   0x565561e5 <+72>:	push   edx
   0x565561e6 <+73>:	mov    ebx,eax
   0x565561e8 <+75>:	call   0x56556050 <printf@plt>
   0x565561ed <+80>:	add    esp,0x10
   0x565561f0 <+83>:	mov    eax,0x0
   0x565561f5 <+88>:	lea    esp,[ebp-0x8]
   0x565561f8 <+91>:	pop    ecx
   0x565561f9 <+92>:	pop    ebx
   0x565561fa <+93>:	pop    ebp
   0x565561fb <+94>:	lea    esp,[ecx-0x4]
   0x565561fe <+97>:	ret
```
Corresponds to `printf("Sum: %d\n", sum);`

I learned about using GDB, which includes setting breakpoints and dissasembling a binary. I then learned about the various registers and operands, and how to map those back to a higher level langauge like C.
