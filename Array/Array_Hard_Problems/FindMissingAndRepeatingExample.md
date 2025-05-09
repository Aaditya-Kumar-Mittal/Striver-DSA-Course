# 🧠 Problem Setup

- One number is **missing**
- One number is **repeating**
- Numbers are from **1 to N**
- Here, `N = 6`

---

## 🔢 Step 1: XOR all array elements and numbers from 1 to N

### Code block

```cpp
for (int i = 0; i < n; i++) {
    xr = xr ^ a[i];
    xr = xr ^ (i + 1);
}
```

### Explanation

We're calculating:

```plaintext
xr = a[0] ^ a[1] ^ ... ^ a[n-1] ^ 1 ^ 2 ^ ... ^ n
```

This cancels all same numbers and gives:

```plaintext
xr = missing ^ repeating
```

### Iterations

```plaintext
Initial xr = 0

i = 0: xr = 0 ^ 4 = 4; then xr = 4 ^ 1 = 5
i = 1: xr = 5 ^ 6 = 3; then xr = 3 ^ 2 = 1
i = 2: xr = 1 ^ 3 = 2; then xr = 2 ^ 3 = 1
i = 3: xr = 1 ^ 2 = 3; then xr = 3 ^ 4 = 7
i = 4: xr = 7 ^ 1 = 6; then xr = 6 ^ 5 = 3
i = 5: xr = 3 ^ 1 = 2; then xr = 2 ^ 6 = 4
```

👉 Final `xr = 4` → means: `missing ^ repeating = 4`

---

## 🔎 Step 2: Find rightmost set bit in `xr = 4`

```cpp
while (1) {
    if ((xr & (1 << bitNo)) != 0) break;
    bitNo++;
}
```

### Breakdown

- Binary of 4 = `100`
- Rightmost set bit = at **bitNo = 2**

---

## 🎯 Step 3: Divide numbers into two groups based on bit 2

### Arrays

- Input: `[4, 6, 3, 2, 1, 1]`
- Numbers: `[1, 2, 3, 4, 5, 6]`

### Logic

For each `num`, if `num & (1 << 2)` is true → group 1; else group 0.

### Iteration for array

```plaintext
zero = 0, one = 0

a[0] = 4 → 100 → set → one = 0 ^ 4 = 4
a[1] = 6 → 110 → set → one = 4 ^ 6 = 2
a[2] = 3 → 011 → not set → zero = 0 ^ 3 = 3
a[3] = 2 → 010 → not set → zero = 3 ^ 2 = 1
a[4] = 1 → 001 → not set → zero = 1 ^ 1 = 0
a[5] = 1 → 001 → not set → zero = 0 ^ 1 = 1
```

→ `zero = 1`, `one = 2`

### Iteration for 1 to N

```plaintext
i = 1 → 001 → not set → zero = 1 ^ 1 = 0
i = 2 → 010 → not set → zero = 0 ^ 2 = 2
i = 3 → 011 → not set → zero = 2 ^ 3 = 1
i = 4 → 100 → set → one = 2 ^ 4 = 6
i = 5 → 101 → set → one = 6 ^ 5 = 3
i = 6 → 110 → set → one = 3 ^ 6 = 5
```

👉 Now:

- `zero = 1`
- `one = 5`

---

## 🔍 Step 4: Determine which is missing and which is repeating

Check if `zero` (1) is repeating:

```cpp
count = 0
for (i = 0; i < n; i++) {
    if (a[i] == zero) count++;
}
```

`1` appears twice → it is **repeating**

---

## ✅ Final Answer

```cpp
return {one, zero};  // {5, 1}
```

---

## 🧾 Output

```plaintext
Printing Array Elements:
4 6 3 2 1 1
Missing number: 5
Repeating number: 1
```

---

## 📌 Summary of Key Intermediate Values

| Step                       | Value |
| -------------------------- | ----- |
| Final XOR (xr)             | 4     |
| Rightmost set bit position | 2     |
| Group 0 XOR result (zero)  | 1     |
| Group 1 XOR result (one)   | 5     |
| Count of `1` in array      | 2     |
| Missing number             | **5** |
| Repeating number           | **1** |

---

Would you like a similar breakdown for a different input or the Sum Formula approach again with steps?
