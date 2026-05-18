# Doubly Linked List - C++ Implementation

A fully featured doubly linked list implementation in C++ with six core operations, complete edge-case handling, and both forward and reverse traversal.

---

## Overview

This project implements a generic doubly linked list from scratch - no STL containers. Every node holds a value and two pointers (`next` and `prev`), enabling O(1) access to both ends and bidirectional traversal. The implementation handles all boundary conditions: empty lists, single-node lists, head insertions/removals, tail insertions/removals, and mid-list operations.

---

## Data Structure

```
         head                              tail
          │                                │
          ▼                                ▼
    ┌──────────┐     ┌──────────┐     ┌──────────┐
    │  nullptr │◄────│   prev   │◄────│   prev   │
    │  value   │     │  value   │     │  value   │
    │   next   │────►│   next   │────►│  nullptr │
    └──────────┘     └──────────┘     └──────────┘
```

The `LinkedList` class tracks both `head` and `tail` pointers plus a `size` counter. Every operation keeps all three consistent.

---

## Class Interface

```cpp
class LinkedList {
public:
    LinkedList();           // initialize empty list (head=tail=nullptr, size=0)
    ~LinkedList();          // walk list and delete all nodes

    void display();         // print all values front to back
    void reverseDisplay();  // print all values back to front

    void append(int number);                // add to end
    void pop();                             // remove from end
    void insert(int number, int position);  // insert at any index
    void remove(int position);              // remove at any index
    void removeValue(int number);           // remove all nodes matching a value
};
```

---

## Operations

### `append(int number)`
Adds a new node to the end of the list. If the list is empty, the new node becomes both head and tail. Otherwise, the current tail's `next` pointer and the new node's `prev` pointer are linked before reassigning `tail`.

### `pop()`
Removes the tail node. Handles three cases: empty list (error message), single-node list (both `head` and `tail` set to `nullptr`), and multi-node list (second-to-last node becomes the new tail with its `next` cleared).

### `insert(int number, int position)`
Inserts a new node at a given zero-based index. Handles:
- **Position 0** - new node becomes the new head; existing head's `prev` is updated
- **Middle** - traverses to the node before the target position and relinks four pointers
- **End** - tail is updated when the new node has no `next`
- **Out of range** - prints error and returns without modifying the list

### `remove(int position)`
Removes the node at a given index. Handles:
- **Position 0** - head advanced, new head's `prev` cleared
- **Middle/End** - traverses to position, bypasses the node, updates `tail` if needed
- **Out of range** - prints error and returns

### `removeValue(int number)`
Traverses the entire list and removes every node whose value matches the target. Uses a `count` variable to detect when no match is found. Safe to call on an empty list. Correctly updates `head`, `tail`, `prev`, and `next` for each removed node without losing the traversal pointer.

### `display()` / `reverseDisplay()`
`display()` walks from `head` to `tail` using `next` pointers. `reverseDisplay()` walks from `tail` to `head` using `prev` pointers. Both print index and value for each node.

---

## Edge Cases Handled

| Scenario | Operations Affected |
|----------|-------------------|
| Empty list | `pop`, `remove`, `removeValue`, `display`, `reverseDisplay` |
| Single-node list | `pop`, `remove`, `removeValue` |
| Insert/remove at head (position 0) | `insert`, `remove` |
| Insert/remove at tail | `insert`, `remove`, `pop` |
| Out-of-range position | `insert`, `remove` |
| Value not present | `removeValue` |
| Multiple copies of same value | `removeValue` |

---

## Pointer Invariants

Every operation maintains these invariants after completion:
- `head->prev == nullptr`
- `tail->next == nullptr`
- For every interior node: `node->next->prev == node`
- `size` equals the actual number of nodes in the chain

---

## Build & Run

```bash
g++ -o linkedlist Lab7linkedlist.cpp
./linkedlist
```

> Requires `linkedlist.h` and `node.h` in the same directory (defines the `LinkedList` and `Node` classes/structs).

---

## Files

| File | Description |
|------|-------------|
| `Lab7linkedlist.cpp` | Full implementation of all six LinkedList methods |
| `linkedlist.h` | Class declaration (not included - define `LinkedList` with `head`, `tail`, `size`) |
| `node.h` | Node struct (not included - define `Node` with `number`, `next`, `prev`) |

---

## Author

**Christina Barefoot**
B.S. Cybersecurity and Operations | Mississippi State University
