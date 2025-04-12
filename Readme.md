# My Data Structures and Algorithms Journey

> This is important and one must never forget
>
> - _Level Sabke Niklenge, Par Niklenge Uske, Jo Khada Rahega - The Girl in the Video._
> - _When there is a will, there is a will._

---

## All Optimization Code Formats in C++

```cpp
ios_base::sync_with_stdio(0);
cin.tie(NULL);
cout.tie(NULL);
```

```cpp
#pragma GCC optimize("O3")
#pragma GCC target("avx2, bmi, bmi2, lzcnt, popcnt")
static const bool __boost = []()
{
  cin.tie(nullptr);
  cout.tie(nullptr);
  return ios_base::sync_with_stdio(false);
}();
```

```cpp
inline const auto optimize = []() {
    std::ios::sync_with_stdio(false); // 1. Disable C and C++ stream synchronization
    std::cin.tie(nullptr);            // 2. Untie cin from cout
    std::cout.tie(nullptr);           // 3. Untie cout from other output streams
    return 0;                         // 4. Return 0 from the lambda function
}();
```

```cpp
auto init = []() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   return '$';
}();
```

```cpp
//Some Optimization Libraries
#pragma GCC optimize("O3")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insnS2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-Pointer-checks")
#pragma GCC optimize("Ofast")
```

---

## Optimizing Input/Output Performance in C++

When working with performance-critical C++ code, especially in competitive programming, it’s important to optimize input and output operations to reduce execution time. The following line of code is often used to achieve this:

```cpp
ios_base::sync_with_stdio(0);
cin.tie(NULL);
cout.tie(NULL);
```

### Explanation

1. **`ios_base::sync_with_stdio(0);`**

   - **Purpose:** Disables synchronization between C++ standard streams (`cin`, `cout`, etc.) and C standard streams (`scanf`, `printf`, etc.).
   - **Reasoning:** By default, C++ streams are synchronized with C streams to ensure compatibility. However, this synchronization can slow down I/O operations. Disabling it makes `cin` and `cout` faster but means you should avoid mixing C and C++ I/O functions.

2. **`cin.tie(NULL);`**

   - **Purpose:** Unties `cin` from `cout`.
   - **Reasoning:** By default, `cin` is tied to `cout`, meaning `cout` is automatically flushed before every `cin` operation. Untying them prevents unnecessary flushing, which can enhance performance when alternating between input and output operations.

3. **`cout.tie(NULL);`**

   - **Purpose:** Ensures that `cout` is not tied to any other stream.
   - **Reasoning:** While this is not as commonly required, it guarantees that `cout` operates independently, avoiding any potential performance penalties from being tied to another stream.

### Summary

Using the above lines of code optimizes input and output operations by:

- Disabling synchronization between C and C++ streams.
- Untying `cin` and `cout` to prevent automatic flushing before input operations.

This approach is highly recommended in scenarios where efficient handling of large amounts of data is critical, such as in competitive programming.

## Optimization Technique - 2

### Code Breakdown

```cpp
inline const auto optimize = []() {
    std::ios::sync_with_stdio(false); // 1. Disable C and C++ stream synchronization
    std::cin.tie(nullptr);            // 2. Untie cin from cout
    std::cout.tie(nullptr);           // 3. Untie cout from other output streams
    return 0;                         // 4. Return 0 from the lambda function
}();
```

### Explanation Below

1. **`inline const auto optimize =`**:

   - This declares a constant (`const auto`) named `optimize` that will hold the result of the immediately invoked lambda function (`[]()`).
   - The keyword `inline` suggests that this definition should be optimized by the compiler for inlining, but in this context, it's used to ensure the lambda is executed only once in a translation unit.

2. **`[]() { ... }`**:

   - This is a **lambda function** in C++. The square brackets (`[]`) indicate that the lambda does not capture any variables. The parentheses (`()`) signify that the lambda takes no parameters.
   - The curly braces (`{ ... }`) contain the body of the lambda function, where the optimizations are performed.

3. **`std::ios::sync_with_stdio(false);`**:

   - This disables the synchronization between the C++ streams (`std::cin`, `std::cout`, etc.) and the C-style I/O functions (`scanf`, `printf`, etc.).
   - Disabling synchronization improves the performance of C++ I/O operations by avoiding the overhead of synchronizing with the C I/O functions. However, this means you cannot safely mix C-style I/O (like `scanf`, `printf`) with C++ I/O (like `std::cin`, `std::cout`).

4. **`std::cin.tie(nullptr);`**:

   - By default, `std::cin` is tied to `std::cout`, which means after every `std::cin` operation, `std::cout` is flushed to ensure output appears immediately before any input is taken.
   - Setting `std::cin.tie(nullptr)` unties `std::cin` from `std::cout`, which means input operations no longer cause an automatic flush of the output stream, resulting in faster I/O.

5. **`std::cout.tie(nullptr);`**:

   - Similar to `std::cin.tie(nullptr)`, this unties `std::cout` from any tied output streams. It’s generally done to optimize output performance by preventing unnecessary flushes.

6. **`return 0;`**:

   - The lambda returns `0`, which is assigned to the `optimize` variable. This is just to ensure the lambda function executes immediately when the program starts (since it's part of a global `const` variable initialization).

7. **`();` at the end**:
   - This immediately invokes the lambda function, so the optimizations are applied as soon as the program runs.

### Purpose

- This idiom is used to **optimize I/O performance** in competitive programming or situations where fast input/output is crucial. It disables unnecessary stream synchronizations and flushes, leading to a noticeable speedup in programs that heavily use I/O.

### When to Use

- This optimization is particularly useful in competitive programming or performance-critical code where you are using only C++ streams (`std::cin`, `std::cout`) and want to minimize the overhead. However, after using this, you **should avoid mixing C-style I/O** (`scanf`, `printf`) with C++ I/O.

The code snippet you've provided is an initialization block commonly used in competitive programming to optimize input/output performance. Let’s break it down step by step:

## Optimization Technique - 3

The code snippet you've provided is an initialization block commonly used in competitive programming to optimize input/output performance. Let’s break it down step by step:

### Code - 3

```cpp
auto init = []() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   return '$';
}();
```

### Explanation - 3

#### 1. **`auto init = []() { ... }();`**

- This part defines and immediately invokes a **lambda function** in C++.
- A **lambda function** is an anonymous function that can be defined and called in place.
- Here, the lambda function does not take any parameters (`[]()`), and it's executed immediately (`();`).
- The result of the lambda function is stored in the variable `init`, but the purpose of this block is mainly to set up the input/output optimizations, not to store `init`.

#### 2. **`ios::sync_with_stdio(false);`**

- This line disables the synchronization between the C++ standard streams (like `cin`/`cout`) and the C standard streams (like `scanf`/`printf`).
- By default, `cin` and `cout` are synchronized with `scanf` and `printf`, which ensures compatibility between C-style and C++-style I/O. However, this synchronization adds a performance overhead.
- **Disabling synchronization** allows for faster input/output operations when only using C++ streams (`cin`, `cout`), but it means you **should not mix C-style I/O (`scanf`/`printf`) with C++-style I/O** in the same program after this point.

#### 3. **`cin.tie(nullptr);`**

- This line unties the `cin` stream from `cout`.
- By default, `cin` and `cout` are **tied** together, which means every time you use `cin`, `cout` is automatically flushed (i.e., any pending output in `cout` is printed to the console). This ensures that the user sees the prompt before providing input.
- **Untying** `cin` from `cout` (by passing `nullptr`) means that `cout` will not automatically flush before `cin` reads input. This can improve performance by reducing unnecessary flushing of the output buffer.

#### 4. **`return '$';`**

- This is the return value of the lambda function, which is `'$',` but it doesn’t really have any significant role in the performance optimization.
- The return value is just a placeholder, often used in these types of lambda blocks, and doesn't affect input/output. It's mainly to satisfy the syntax of the lambda function, as every lambda function needs a return statement if it returns something.

#### 5. **The use of `init` variable**

- The variable `init` stores the return value of the lambda function (in this case, the character `'$',`), but this variable is **not typically used later in the code**. The main reason this block exists is to run the lambda function for I/O optimizations as soon as the program starts.
- This is a common idiom in competitive programming to reduce boilerplate code and keep the `main()` function cleaner.

### Purpose - 3

The main purpose of this code block is to **optimize the input/output operations** in C++ programs, particularly useful in competitive programming, where speed is critical. Specifically, it:

1. Disables synchronization between C and C++ I/O streams for faster input/output.
2. Unties `cin` from `cout` to prevent automatic flushing of the output buffer, further improving performance.

### Important Note

- After this block of code is run, **do not mix C++ I/O (`cin`/`cout`) with C I/O (`scanf`/`printf`)** because they are no longer synchronized, which can lead to unexpected behavior.

---

In summary, this snippet is a performance optimization for faster input/output in C++ programs, commonly used in scenarios where speed is essential, such as competitive programming.
