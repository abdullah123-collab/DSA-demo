# 5 - Stack

A **Stack** is a linear data structure that follows the **LIFO** (Last In, First Out) principle. The element inserted last is the first one to be removed.

---

## What is a Stack?

Think of a stack like a pile of plates — you always add and remove from the top.

```
        |  50  |  ← TOP (last inserted, first removed)
        |  40  |
        |  30  |
        |  20  |
        |  10  |
        └──────┘
```

---

## Core Operations

| Operation  | Description                        | Time Complexity |
|------------|------------------------------------|-----------------|
| `push(x)`  | Insert element at top              | O(1)            |
| `pop()`    | Remove and return top element      | O(1)            |
| `peek()`   | View top element without removing  | O(1)            |
| `isEmpty()`| Check if stack has no elements     | O(1)            |
| `isFull()` | Check if stack is full (array only)| O(1)            |
| `size()`   | Return number of elements          | O(1)            |
| `display()`| Print all elements                 | O(n)            |

---

## Files in this Folder

| File | Description |
|------|-------------|
| `StackUsingArray.cpp` | Stack implemented with a fixed-size array |
| `StackUsingLinkedList.cpp` | Stack implemented using linked list nodes |

---

## Array vs Linked List

| Feature        | Array Stack         | Linked List Stack     |
|----------------|---------------------|-----------------------|
| Memory         | Fixed size (static) | Dynamic (grows freely)|
| Overflow       | Possible            | Not possible          |
| Extra memory   | None                | Pointer per node      |
| push / pop     | O(1)                | O(1)                  |
| Best for       | Known max size      | Unknown / large input |

---

## How Stack Works (Step by Step)

**Push Operations:**
```
push(10) → [10]
push(20) → [10, 20]
push(30) → [10, 20, 30]   ← top is 30
```

**Pop Operations:**
```
pop() → returns 30 → [10, 20]
pop() → returns 20 → [10]
```

---

## Real World Applications

- **Undo / Redo** in text editors
- **Browser back button** (history of pages)
- **Function call stack** in programming languages
- **Balanced parentheses** checking in compilers
- **Expression evaluation** (infix to postfix)
- **Depth First Search (DFS)** in graphs

---

## Common Interview Problems Using Stack

| Problem | Concept Used |
|---------|-------------|
| Balanced Parentheses `{[()]}` | Push open, pop on close |
| Next Greater Element | Monotonic stack |
| Reverse a string / linked list | Push all, pop all |
| Evaluate Postfix Expression | Push operands, pop on operator |
| Stock Span Problem | Monotonic stack |
| Min Stack (getMin in O(1)) | Two stacks trick |

---

## Example Output

```
10 pushed to stack.
20 pushed to stack.
30 pushed to stack.
40 pushed to stack.
50 pushed to stack.
Stack (top → bottom): 50 → 40 → 30 → 20 → 10
Top element : 50
Stack size  : 5
Popped: 50
Popped: 40
Stack (top → bottom): 30 → 20 → 10
```