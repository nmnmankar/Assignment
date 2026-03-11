# LRU Cache & Event Scheduler (C++)

This repository contains solutions for two algorithmic problems implemented in C++.

## Problem 1: LRU Cache

The **Least Recently Used (LRU) Cache** stores a limited number of key-value pairs.
When the cache reaches its capacity, the **least recently used item is removed** before inserting a new one.

### Operations

* **get(key)** – Returns the value if the key exists, otherwise `-1`. Accessing a key marks it as recently used.
* **put(key, value)** – Inserts or updates a key-value pair. If the cache is full, the least recently used element is removed.

The implementation uses:

* **unordered_map (Hash Map)** for fast lookup
* **Doubly Linked List** to maintain usage order

---

## Problem 2: Event Scheduler

Events are represented as `(start_time, end_time)`.

Example:

```
[(9,10), (10,11), (11,12)]
```

### Functions

**can_attend_all(events)**
Checks if a person can attend all events without overlapping.
Events are sorted and compared to detect conflicts.

**min_rooms_required(events)**
Calculates the minimum number of meeting rooms required to schedule all events.
This is done by comparing sorted start times and end times.

---

# Final Discussion & Analysis

### Time & Space Complexity

**LRU Cache**

* `get()` → O(1)
* `put()` → O(1)
  Space Complexity: **O(capacity)**

**Event Scheduler**

* `can_attend_all()` → O(n log n)
* `min_rooms_required()` → O(n log n)
  Space Complexity: **O(n)**

---

### Trade-offs

A **hash map + doubly linked list** is used in LRU Cache because:

* Hash map provides **O(1) access**
* Doubly linked list maintains **recent usage order**
* Both insertion and deletion occur in **O(1)** time.

---

### Future Proofing

To assign specific rooms (e.g., *Room A, Room B*), events can include a room field:

```
struct Event {
    int start;
    int end;
    string room;
};
```

The scheduler can track available rooms and assign them dynamically.

---

### Concurrency

To make the LRU Cache **thread-safe**, synchronization such as **mutex locks** can be used so that only one thread modifies the cache at a time.
