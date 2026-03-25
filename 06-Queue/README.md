# 6 - Queue

A **Queue** is a linear data structure that follows the **FIFO** (First In, First Out) principle. The element inserted first is the first one to be removed.

---

## What is a Queue?

Think of a queue like a line of people at a ticket counter — the first person to join is the first to be served.

```
  FRONT                          REAR
    |                              |
  [ 10 ] → [ 20 ] → [ 30 ] → [ 40 ] → [ 50 ]
    ↑                                    ↑
 dequeue()                           enqueue()
```

---

## Core Operations

| Operation    | Description                          | Time Complexity |
|--------------|--------------------------------------|-----------------|
| `enqueue(x)` | Insert element at rear               | O(1)            |
| `dequeue()`  | Remove and return front element      | O(1)            |
| `front()`    | View front element without removing  | O(1)            |
| `rear()`     | View rear element without removing   | O(1)            |
| `isEmpty()`  | Check if queue has no elements       | O(1)            |
| `isFull()`   | Check if queue is full (array only)  | O(1)            |
| `size()`     | Return number of elements            | O(1)            |
| `display()`  | Print all elements                   | O(n)            |

---

## Files in this Folder

| File | Description |
|------|-------------|
| `QueueUsingArray.cpp` | Queue implemented with a fixed-size array |
| `QueueUsingLinkedList.cpp` | Queue implemented using linked list nodes |
| `CircularQueue.cpp` | Circular Queue using array with wrap-around |

---

## Types of Queues

| Type | Description |
|------|-------------|
| **Simple Queue** | Basic FIFO, insert at rear, remove from front |
| **Circular Queue** | Rear wraps around to front to reuse empty slots |
| **Double Ended Queue (Deque)** | Insert and remove from both front and rear |
| **Priority Queue** | Element with highest priority is removed first |

---

## Array vs Linked List Queue

| Feature      | Array Queue         | Linked List Queue     |
|--------------|---------------------|-----------------------|
| Memory       | Fixed size (static) | Dynamic (grows freely)|
| Overflow     | Possible            | Not possible          |
| Wasted space | Yes (normal array)  | No                    |
| Extra memory | None                | Pointer per node      |
| enqueue / dequeue | O(1)           | O(1)                  |

---

## Why Circular Queue over Normal Array Queue?

In a normal array queue, once `rear` reaches the end, no more inserts are allowed — **even if front slots are empty** after dequeuing.

```
Normal Queue:
  [ _ | _ | 30 | 40 | 50 ]
         ↑              ↑
       front           rear  ← can't insert, space wasted!

Circular Queue:
  [ 60 | 70 | 30 | 40 | 50 ]
              ↑           ↑
            front        rear  ← 60 & 70 reuse freed slots!
```

Circular Queue solves this by wrapping around using % (modulo):
```cpp
rearIndex  = (rearIndex  + 1) % capacity;
frontIndex = (frontIndex + 1) % capacity;
```

---

## Stack vs Queue

| Feature   | Stack                    | Queue                     |
|-----------|--------------------------|---------------------------|
| Principle | LIFO (Last In First Out) | FIFO (First In First Out) |
| Insert    | `push` at top            | `enqueue` at rear         |
| Remove    | `pop` from top           | `dequeue` from front      |
| View      | `peek` (top only)        | `front` and `rear`        |

---

## How Queue Works (Step by Step)

**Enqueue Operations:**
```
enqueue(10) → [ 10 ]
enqueue(20) → [ 10, 20 ]
enqueue(30) → [ 10, 20, 30 ]   ← rear is 30, front is 10
```

**Dequeue Operations:**
```
dequeue() → returns 10 → [ 20, 30 ]
dequeue() → returns 20 → [ 30 ]
```

---

## Real World Applications

- **CPU Scheduling** (process management in OS)
- **Printer spooler** (print jobs handled in order)
- **Keyboard buffer** (keystrokes processed in order)
- **BFS in Graphs** (level-by-level traversal)
- **Ticket booking systems** (first come first served)
- **Call center systems** (customers wait in queue)

---

## Common Interview Problems Using Queue

| Problem | Concept Used |
|---------|-------------|
| BFS of a Graph / Tree | Simple Queue |
| Level Order Traversal | Simple Queue |
| First Non-Repeating Character in Stream | Queue + HashMap |
| Sliding Window Maximum | Deque (monotonic) |
| Rotten Oranges (LeetCode) | BFS with Queue |
| Implement Queue using two Stacks | Stack + Queue |

---

## Example Output

```
10 enqueued to queue.
20 enqueued to queue.
30 enqueued to queue.
40 enqueued to queue.
50 enqueued to queue.
Queue (front → rear): 10 → 20 → 30 → 40 → 50
Front element : 10
Rear element  : 50
Queue size    : 5
Dequeued: 10
Dequeued: 20
Queue (front → rear): 30 → 40 → 50
```