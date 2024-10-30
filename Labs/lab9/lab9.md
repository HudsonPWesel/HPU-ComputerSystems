```bash

# - L1 instruction cache read misses (`I1mr`) and LL cache instruction read misses (`ILmr`)

hwesel@linus:~$ valgrind --tool=cachegrind ./lab9 1000
==2710236== Cachegrind, a cache and branch-prediction profiler
==2710236== Copyright (C) 2002-2017, and GNU GPLd, by Nicholas Nethercote et al.
==2710236== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==2710236== Command: ./lab9 1000
==2710236==
--2710236-- warning: L3 cache found, using its data for the LL simulation.
v1 average is: 0.00; time is 0.014453
v2 average is: 50.43; time is 0.055279
==2710236==
==2710236== I   refs:      100,456,003
==2710236== I1  misses:          1,510
==2710236== LLi misses:          1,476
==2710236== I1  miss rate:        0.00%
==2710236== LLi miss rate:        0.00%
==2710236==
==2710236== D   refs:       46,222,678  (38,150,659 rd   + 8,072,019 wr)
==2710236== D1  misses:        524,541  (   460,903 rd   +    63,638 wr)
==2710236== LLd misses:         64,821  (     1,354 rd   +    63,467 wr)
==2710236== D1  miss rate:         1.1% (       1.2%     +       0.8%  )
==2710236== LLd miss rate:         0.1% (       0.0%     +       0.8%  )
==2710236==
==2710236== LL refs:           526,051  (   462,413 rd   +    63,638 wr)
==2710236== LL misses:          66,297  (     2,830 rd   +    63,467 wr)
==2710236== LL miss rate:          0.0% (       0.0%     +       0.8%  )
hwesel@linus:~$ cg_annotate cachegrind.out.2710236
--------------------------------------------------------------------------------
I1 cache:         65536 B, 64 B, 2-way associative
D1 cache:         65536 B, 64 B, 2-way associative
LL cache:         16777216 B, 64 B, 16-way associative
Command:          ./lab9 1000
Data file:        cachegrind.out.2710236
Events recorded:  Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
Events shown:     Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
Event sort order: Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
Thresholds:       0.1 100 100 100 100 100 100 100 100
Include dirs:
User annotated:
Auto-annotation:  on

--------------------------------------------------------------------------------
Ir                   I1mr           ILmr           Dr                  D1mr             DLmr           Dw                 D1mw            DLmw
--------------------------------------------------------------------------------
100,456,003 (100.0%) 1,510 (100.0%) 1,476 (100.0%) 38,150,659 (100.0%) 460,903 (100.0%) 1,354 (100.0%) 8,072,019 (100.0%) 63,638 (100.0%) 63,467 (100.0%)  PROGRAM TOTALS

--------------------------------------------------------------------------------
Ir                  I1mr        ILmr        Dr                 D1mr             DLmr         Dw                 D1mw            DLmw             file:function
--------------------------------------------------------------------------------
31,870,968 (31.73%)  2 ( 0.13%)  2 ( 0.14%) 8,000,000 (20.97%)       0            0          3,000,000 (37.17%)      0               0           ./stdlib/./stdlib/random_r.c:random_r
21,000,000 (20.90%)  3 ( 0.20%)  3 ( 0.20%) 8,000,000 (20.97%)      16 ( 0.00%)   0          2,000,000 (24.78%)      0               0           ./stdlib/./stdlib/random.c:random
20,020,022 (19.93%)  4 ( 0.26%)  4 ( 0.27%) 8,008,007 (20.99%)      17 ( 0.00%)   0          2,003,007 (24.81%) 61,890 (97.25%) 61,874 (97.49%)  ???:genRandomMatrix
16,009,020 (15.94%)  1 ( 0.07%)  1 ( 0.07%) 9,005,006 (23.60%) 458,353 (99.45%)   0              1,005 ( 0.01%)      0               0           ???:averageMat_v2
 5,000,000 ( 4.98%)  1 ( 0.07%)  1 ( 0.07%) 1,000,000 ( 2.62%)       0            0          1,000,000 (12.39%)      0               0           ./stdlib/./stdlib/rand.c:rand
 4,009,020 ( 3.99%)  1 ( 0.07%)  1 ( 0.07%) 3,005,006 ( 7.88%)       0            0              1,005 ( 0.01%)      0               0           ???:averageMat_v1
 2,004,252 ( 2.00%) 33 ( 2.19%) 32 ( 2.17%) 1,002,092 ( 2.63%)      23 ( 0.00%)   0                 20 ( 0.00%)      2 ( 0.00%)      1 ( 0.00%)  ???:???
   142,329 ( 0.14%) 24 ( 1.59%) 24 ( 1.63%)    22,096 ( 0.06%)       1 ( 0.00%)   0             25,072 ( 0.31%)    976 ( 1.53%)    973 ( 1.53%)  ./malloc/./malloc/malloc.c:_int_malloc
   128,938 ( 0.13%) 16 ( 1.06%) 16 ( 1.08%)    35,967 ( 0.09%)     525 ( 0.11%)   0             15,014 ( 0.19%)      1 ( 0.00%)      0           ./malloc/./malloc/malloc.c:_int_free

--------------------------------------------------------------------------------
The following files chosen for auto-annotation could not be found:
--------------------------------------------------------------------------------
  ./malloc/./malloc/malloc.c
  ./stdlib/./stdlib/rand.c
  ./stdlib/./stdlib/random.c
  ./stdlib/./stdlib/random_r.c

```

### Questions
4b.  *Analyze why  one traversal leads to more cache misses*
The column traversal leads to more cache misses becauset this program’s access patterns don't need to align well with the hardware’s memory arrangement (memory locality)
1. How did cache miss rates differ between row-major and column-major traversals?
	1. the first version of the code (v1) executes about four times faster than the second version (v2). ![[Pasted image 20241029133501.png]]
2. How did Cachegrind’s data reveal the effect of memory access patterns on cache   hits and misses?
	1. Notice the 9,005,006 misses of v2, versus the 3,005,006 million misses of v1
![[Pasted image 20241029133301.png]]
3. Which traversal method would you prioritize for applications where cache   performance is critical?
	1. Row major
4. How does knowledge of cache efficiency guide you in writing code for memory-   constrained systems?
	1. When designing an algorithm and using a specific data structure, it's important to think not only about the time complexity of an operation (serach, indexing, etc.), but also how your algorithm interacts with that data structure in memory. Are you using an array which is stored contiguously, or something like a linked list which is not. How you're accessing data is important to think about when considering the performance of your code.