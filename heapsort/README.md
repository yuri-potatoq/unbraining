# Heap Sort & Heaps

### Definition
* Array A repesents a heap when:
```
# Given a array A containing elements A[1..A.lenght]
Heap has elements from A[1..A.heap_size] are valid, where 0 <= A.heap_size <= A.lenght
```
* The heap root is always A[1]
* Given a index i of heap node, we can compute the A indices using node parent, left and right childs. Applying the following operations
```
# Given i, the A indice of given heap node

PARENT(i) = mod(i/2)

LEFT(i) = 2i

RIGHT(i) = 2i + 1
```

### Max Heap properties
* The largest element in the heap lives into root node
* For each node into the heap, it's children elements has values less than the parent.

### Max Heap Sorting
* **Steps**:
  * 1. Create a max heap from array, swapping the values when max-heap properties are not correct.
    * Now the largest value from array is at the heap root.
  * 2. Go down from A.lenght swapping the root with the heap leafs and decrementing heap size until heap position 2.
    * While decrementing heap size, we need to ensure the heap properties are preserved. 

_Unsorted Array_
```mermaid
graph LR
    A1[1<br/>16] --> A2[2<br/>14]
    A2 --> A3[3<br/>10]
    A3 --> A4[4<br/>8]
    A4 --> A5[5<br/>7]
    A5 --> A6[6<br/>9]
    A6 --> A7[7<br/>3]
    A7 --> A8[8<br/>2]
    A8 --> A9[9<br/>4]
    A9 --> A10[10<br/>1]
```

_Heap Structure_
```mermaid
graph TD
    16((16 <br/> i = 1)):::Node --> 14((14 <br/> i = 2)):::Node
    16 --> 10((10 <br/> i = 3)):::Node
    14 --> 8((8 <br/> i = 4)):::Node
    14 --> 7((7 <br/> i = 5)):::Node
    10 --> 9((9 <br/> i = 6)):::Node
    10 --> 3((3 <br/> i = 7)):::Node
    8 --> 2((2 <br/> i = 8)):::Node
    8 --> 4((4 <br/> i = 9)):::Node
    7 --> 1((1 <br/> i = 10)):::Node
    classDef Node font-size:14pt,color:green,stroke:gray;
```
