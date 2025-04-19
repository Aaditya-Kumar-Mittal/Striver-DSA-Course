# My Calendar II

This problem involves implementing a calendar booking system where each event is represented as a half-open interval `[start, end)`. The goal is to allow double bookings (overlap of two events) but prevent triple bookings (overlap of three events).

## Problem Description

### Objective

- You are required to implement a program that allows event bookings with the condition that no triple booking (three overlapping events) occurs.

### Key Definitions

- A **double booking** is when two events overlap on a particular time.
- A **triple booking** is when three events overlap, and this should not be allowed.

The event is represented by a pair of integers `start` and `end`, which indicates the half-open interval `[start, end)`. This means that the event starts at time `start` and ends before time `end`.

## Class Definition

You need to implement the following class:

### `MyCalendarTwo`

- **Constructor**: `MyCalendarTwo()`  
  Initializes the calendar object.
- **Function**: `book(int start, int end) -> boolean`  
  This function attempts to add a new event represented by the interval `[start, end)`.
  - Returns `True` if the event can be added without causing a triple booking.
  - Returns `False` if adding the event would result in a triple booking, and the event is not added.

## Example

```python
Input:
["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]

Output:
[null, true, true, true, false, true, true]
```

### Explanation

1. **myCalendarTwo.book(10, 20)**

   - This booking can be made.
   - **Return**: `True`

2. **myCalendarTwo.book(50, 60)**

   - This booking can be made.
   - **Return**: `True`

3. **myCalendarTwo.book(10, 40)**

   - This booking can be made, resulting in a double booking in the time interval `[10, 20)`.
   - **Return**: `True`

4. **myCalendarTwo.book(5, 15)**

   - This booking cannot be made because it would result in a triple booking in the time interval `[10, 15)`.
   - **Return**: `False`

5. **myCalendarTwo.book(5, 10)**

   - This booking can be made, as it does not overlap with the time `[10, 20)` where there is already a double booking.
   - **Return**: `True`

6. **myCalendarTwo.book(25, 55)**
   - This booking can be made, as it will cause a double booking in intervals `[25, 40)` and `[50, 55)`.
   - **Return**: `True`

## Approach

### Data Structures

- Use two collections:
  1. **Single bookings**: Stores intervals where there is at least one booking.
  2. **Double bookings**: Stores intervals where two bookings overlap.

### Algorithm

1. For every new booking:

   - Check if it would cause a triple booking by comparing it against the existing double bookings.
   - If no triple booking is caused, add the interval to the list of single bookings and update double bookings where necessary.

2. The steps are as follows:
   - Iterate over the double bookings to check if the new event overlaps with any of the intervals. If so, return `False`.
   - If no triple booking occurs, iterate over the single bookings. For any overlap, add it to the list of double bookings.
   - Finally, add the new booking to the list of single bookings.

## Code Implementation

```cpp
class MyCalendarTwo {
public:
    vector<pair<int, int>> singleBook, doubleBook; // Vectors to store single and double bookings

    // Constructor: Reserve space for efficiency (optional)
    MyCalendarTwo() {
        singleBook.reserve(1000);
        doubleBook.reserve(1000);
    }

    /*
        Function to book a new event.
        It ensures no triple bookings are allowed. Events can overlap at most twice.
        - Parameters:
            - start: Start time of the new event.
            - end: End time of the new event.
        - Returns: true if the event can be booked, false otherwise.
    */
    bool book(int start, int end) {
        // Check for triple booking by verifying against double booked events
        for (const auto& event : doubleBook) {
            if (max(start, event.first) < min(end, event.second)) {
                return false; // If there's an overlap in double bookings, return false
            }
        }

        // Check for potential double bookings from existing single booked events
        for (const auto& event : singleBook) {
            int overlapStart = max(start, event.first);  // Overlapping start
            int overlapEnd = min(end, event.second);     // Overlapping end

            // If there is an overlap, this becomes a double booking
            if (overlapStart < overlapEnd) {
                doubleBook.emplace_back(overlapStart, overlapEnd); // Store the double booking
            }
        }

        // After all checks, book the event as a single booking
        singleBook.emplace_back(start, end);

        return true; // Booking is valid
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
```

## Explanation of Code

1. **book function**:
   - The function first checks if the new booking causes a triple booking by comparing it with existing double bookings.
   - If no triple booking is found, it checks for overlaps with the single bookings. For every overlap found, it is added to the double bookings.
   - Finally, the booking is added to the single bookings and `True` is returned.

## Time Complexity

- The time complexity for each booking is **O(n)**, where `n` is the number of existing bookings. This is because the algorithm checks every previous booking to find overlaps.

## Space Complexity

- The space complexity is **O(n)**, as the program needs to store all single and double bookings.

## Constraints

- \( 0 \leq start < end \leq 10^9 \)
- At most **1000** calls will be made to `book()`.

## Edge Cases

1. **No Overlap**:

   - If all events are non-overlapping, they will all be booked successfully.

2. **Complete Overlap**:

   - If an event overlaps completely with another event already booked twice, it will not be booked.

3. **Adjacent Events**:

   - Events that are adjacent but do not overlap will be booked successfully.

4. **Multiple Calls**:
   - The system should handle multiple calls to `book()` efficiently without causing memory overflow.

## Conclusion

- The **My Calendar II** problem is efficiently solved using two collections: one for single bookings and one for double bookings.
- The approach ensures that no triple booking occurs while allowing double bookings.
- This solution is optimal for up to **1000** calls to the `book()` function, as specified in the problem constraints.

## Difference Array Approach

### Background Knowledge

- **Difference Array Concept**:  
  The difference array helps efficiently track the number of ongoing events at each point in time. We use a **map** to store the changes in event counts at specific time points.

  - For an event booking from `start` to `end`, we increment the count at `start` and decrement it at `end`. This way, when we sweep through the timeline, we can calculate how many events are active at any given time.

- **Sweep Line Algorithm**:  
  This algorithm involves "sweeping" through the time points in sorted order, maintaining a running total of active events. This allows us to check if any time point has more than two active events, which would indicate a triple booking.

### Diff Array Approach

#### 1. Initialize the Difference Array

- We use a `map<int, int>` called `bookings` to store the changes in the number of events at each time point:
  - **`+1`** at the `start` of an event (indicating a new event starts here).
  - **`-1`** at the `end` of an event (indicating an event ends just before this point).

#### 2. Book Method

For each new event:

- **Temporarily update the difference array**:  
  Increment the count at `start` and decrement the count at `end`.
- **Traverse the difference array**:  
  Perform a sweep line through the time points to calculate the total number of ongoing events at each time. This is done by iterating through the sorted keys of the map.

- **Check for triple bookings**:  
  If at any point the number of ongoing events exceeds **2**, revert the changes (undo the increment and decrement) and return `false` since a triple booking would occur.

- If no triple booking is found, keep the updates and return `true`.

---

### Code

```cpp
class MyCalendarTwo {
public:
    map<int, int> bookings;  // Difference array using a map

    MyCalendarTwo() {
    }

    bool book(int start, int end) {
        // Temporarily update the difference array
        bookings[start]++;
        bookings[end]--;

        int activeBookings = 0;  // Keeps track of the ongoing events

        // Sweep line: Traverse the sorted time points in the difference array
        for (const auto& [time, count] : bookings) {
            activeBookings += count;  // Update the count of active events
            if (activeBookings >= 3) {  // Triple booking detected
                // Revert the changes made to the difference array
                bookings[start]--;
                bookings[end]++;
                return false;  // Return false since triple booking is not allowed
            }
        }

        return true;  // Return true if no triple booking was found
    }
};
```

### Code Working

1. **Difference Array (bookings)**:

   - The `bookings` map is used to store changes in the event count at specific time points. For each booking from `[start, end)`, the value at `start` is incremented by `+1`, and the value at `end` is decremented by `-1`.

2. **Book Function**:
   - We first **temporarily update** the map by adding `+1` at `start` and `-1` at `end`.
   - Then, we **traverse the map** in sorted order (since `map` stores keys in ascending order) and keep track of the current number of active bookings using the `activeBookings` variable.
   - If at any point, the number of active bookings reaches **3 or more**, we revert the temporary updates (undo the increment and decrement) and return `false` because a triple booking would occur.
   - If no triple booking is found during the traversal, we keep the changes and return `true`, allowing the event to be booked.

### Time and Space Complexity

- **Time Complexity**:  
  The time complexity for each booking operation is **O(n log n)**, where `n` is the number of events, due to the traversal of the `map` and its logarithmic operations on insertions.
- **Space Complexity**:  
  The space complexity is **O(n)**, where `n` is the number of events stored in the difference array.

### Key Takeaways

- This solution efficiently handles event overlaps by using a difference array (implemented with a `map`) and a sweep line approach.
- The traversal through the `map` allows us to detect triple bookings by keeping track of the number of ongoing events at each time point.
- The use of a map ensures that we only store necessary time points, and its sorted traversal helps check for triple bookings in linear time relative to the number of time points.
