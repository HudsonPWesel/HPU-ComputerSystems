**Circuit Output**

| R   | S   | Q   | Q'                 |
| --- | --- | --- | ------------------ |
| 0   | 0   | 0   | Memory (As Before) |
| 0   | 1   | 0   | 1                  |
| 1   | 0   | 1   | 0                  |
| 1   | 1   | N/A | N/A                |
 
 **A NOR B Truth Table**

| A   | B   | A NOR B |
| --- | --- | ------- |
| 0   | 0   | 1       |
| 0   | 1   | 0       |
| 1   | 0   | 0       |
| 1   | 1   | 0       |


 *Set **R=0** and **S=0**, and observe what happens to the outputs. What do you notice about the outputs when the inputs remain 0?*
 **Question**: Explain why the output remains stable (doesn’t change) when **R=0** and **S=0**, and how this behavior allows the RS latch to “remember” the last state.
 It's the same output as the previous output
 Initial State
 S = 0, R = 1, Q = 0, Q' = 1
 *Removing the originial inputs* S=0, R = 0, (Q' (prev state) = 1 NOR R= 0) = Q = **0** | (Q = 0 NOR S= 0)  = Q' = **1**. Stored data (outputs are the same even though the inputs are different)		 
**Case 2 – R=1, S=1 (Invalid State)**:
 **Question**: Why is this considered an invalid state? How does this impact the reliability of the RS latch?
S = 1, R = 1, Q = 0, Q = 0' 
Q can't = Q'

![[Pasted image 20240925093847.png]] (Image of transition table)

| Sequence | A   | B   | C   | D   | JA  | KA  | JB  | KB  | JC  | KC  | JD  | KD  |
| -------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0        | 0   | 0   | 0   | 0   | 0   | X   | 0   | X   | 0   | X   | 1   | X   |
| 1        | 0   | 0   | 0   | 1   | 0   | X   | 0   | X   | 1   | X   | X   | 1   |
| 2        | 0   | 0   | 1   | 0   | 0   | X   | 0   | X   | X   | 0   | 1   | X   |
| 3        | 0   | 0   | 1   | 1   | 0   | X   | 1   | X   | X   | 1   | X   | 1   |
| 4        | 0   | 1   | 0   | 0   | 0   | X   | X   | 0   | 0   | X   | 1   | X   |
| 5        | 0   | 1   | 0   | 1   | 0   | X   | X   | 0   | 1   | X   | X   | 1   |
| 6        | 0   | 1   | 1   | 0   | 0   | X   | X   | 0   | X   | 0   | 1   | X   |
| 7        | 0   | 1   | 1   | 1   | 1   | X   | X   | 1   | X   | 1   | X   | 1   |
| 8        | 1   | 0   | 0   | 0   | X   | 0   | 0   | X   | 0   | X   | 1   | X   |
| 9        | 1   | 0   | 0   | 1   | X   | 0   | 0   | X   | 1   | X   | X   | 1   |
| 10       | 1   | 0   | 1   | 0   | X   | 1   | 0   | X   | X   | 1   | 0   | X   |

### JA

| CD AB | A'B' | A'B | AB  | AB' |
| ----- | ---- | --- | --- | --- |
| C'D'  | 0    | 0   | 0   | 0   |
| C'D   | 0    | 0   | 1   | 0   |
| CD    | 0    | 0   | 0   | 0   |
| CD'   | X    | X   | 0   | X   |

A'BCD

### KA

| CD AB | A'B' | A'B | AB  | AB' |
| ----- | ---- | --- | --- | --- |
| C'D'  | X    | X   | X   | X   |
| C'D   | X    | X   | X   | X   |
| CD    | X    | X   | X   | X   |
| CD'   | 0    | 0   | X   | 1   |

CD'

### JB

| CD AB | A'B' | A'B | AB  | AB' |
| ----- | ---- | --- | --- | --- |
| C'D'  | 0    | 0   | 1   | 0   |
| C'D   | X    | X   | X   | X   |
| CD    | 0    | 0   | X   | 1   |
| CD'   | 0    | 0   | 0   | 0   |
|       |      |     |     |     |
BC + A'CD

### KB

| CD AB | A'B' | A'B | AB  | AB' |
| ----- | ---- | --- | --- | --- |
| C'D'  | X    | X   | X   | X   |
| C'D   | 0    | 0   | 1   | 0   |
| CD'   | X    | X   | 0   | X   |
| CD    | X    | X   | X   | X   |

A'CD
### JC

| CD AB | A'B' | A'B | AB  | AB' |
| ----- | ---- | --- | --- | --- |
| C'D'  | 0    | 1   | X   | X   |
| C'D   | 0    | 1   | X   | X   |
| CD'   | 1    | X   | 0   | X   |
| CD    | 0    | 1   | 0   | X   |
C'D + ABC'
### KC

| CD AB | A'B' | A'B | AB  | AB' |
| ----- | ---- | --- | --- | --- |
| C'D'  | X    | X   | 1   | 0   |
| C'D   | X    | X   | 1   | 0   |
| CD'   | X    | 0   | X   | 1   |
| CD    | X    | X   | X   | 1   |
AC + CD
### JD

| CD AB | A'B' | A'B | AB  | AB' |
| ----- | ---- | --- | --- | --- |
| C'D'  | 1    | X   | X   | 1   |
| C'D   | 1    | X   | X   | 1   |
| CD'   | X    | 1   | 1   | X   |
| CD    | 1    | X   | 1   | 0   |

CDA' + CAB
### KD

| CD AB | A'B' | A'B | AB  | AB' |
| ----- | ---- | --- | --- | --- |
| C'D'  | X    | 1   | 1   | X   |
| C'D   | X    | 1   | 1   | X   |
| CD'   | X    | 1   | 1   | X   |
| CD    | X    | 1   | 1   | X   |

1
### Python Code to generate truth table (not 100% working)
```Python
inputs = [
    [0, 0, 0, 0],
    [0, 0, 0, 1],
    [0, 0, 1, 0],
    [0, 0, 1, 1],
    [0, 1, 0, 0],
    [0, 1, 0, 1],
    [0, 1, 1, 0],
    [1, 1, 1, 1],
    [1, 0, 0, 0],
    [1, 0, 0, 1],
    [1, 0, 1, 0],
    [1, 0, 1, 1],
    [1, 1, 0, 0],
    [1, 1, 0, 1],
    [1, 1, 1, 0],
    [1, 1, 1, 1]
]

j_k_values = [[], []]
j_k_matrix = [[], [], [], [], [], [], [], []]
titles = [(i,j) for i in ['J','K'] for j in ['A','B','C','D']]


for i in range (len(j_k_matrix) - 1):
    for col in range(len(inputs[0])):
        for row in range(len(inputs) - 1):
            val, val_next = (inputs[row][col], inputs[row + 1][col])
            if val == 0 and val_next == 0:
                j_k_values[0].append(0)
                j_k_values[1].append('X')
    
            elif val == 0 and val_next == 1:
                j_k_values[0].append(1)
                j_k_values[1].append('X')
    
            elif val == 1 and val_next == 0:
                j_k_values[0].append('X')
                j_k_values[1].append(1)
    
            elif val == 1 and val_next == 1:
                j_k_values[0].append('X')
                j_k_values[1].append(0)
        j_k_matrix[i] = j_k_values[0] 
        j_k_matrix[i + 1] = j_k_values[1] 
        j_k_values = [[],[]]
for i in range(len(j_k_matrix)):
    print (titles[i])
    print(i);
    print()
```

1. **How does the register update the stored value based on the sum produced by the adder and the clock signal?**
The adder sums the inputs, the register has a clock input that controls when it can update its value. On the rising edge of the clock signal (when it transitions from low to high evenly), the register samples the current output of the adder.

2. **What role does the write enable play in controlling when the register stores new values?**
When write enable is active, he register is allowed to update its value on the clock edge.

3. **In what kind of real-world devices or applications might you see circuits like this being used?**
Calculators, scoreboards, and embedded devices
4. **Can you relate this circuit to any components in modern processors or memory systems?**
This circuit is a simplified version of the ALU, in that the 8-bit adder is used to execute various arithmetic operations within the ALU.