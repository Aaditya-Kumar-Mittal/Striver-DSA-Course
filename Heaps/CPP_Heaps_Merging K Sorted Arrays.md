# Merging K Sorted Arrays

This solution merges `k` sorted arrays, each of size `k`, into one sorted array using a min-heap (priority queue). It is implemented in C++ and makes use of custom data structures to efficiently merge the arrays.

---

## Problem Statement

Given `k` sorted arrays arranged in the form of a matrix of size `k * k`, merge them into one sorted array. The output should be a sorted list containing all elements from the arrays.

**Input:**

- `k`: The number of sorted arrays.
- `arr[][]`: A 2D vector where each row represents a sorted array of integers.

**Output:**

- A sorted array containing all `k * k` elements.

---

### Examples

**Example 1:**

```cpp
Input:
k = 3
arr[][] = {{1, 2, 3},
           {4, 5, 6},
           {7, 8, 9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation:
The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
```

**Example 2:**

```cpp
Input:
k = 4
arr[][] = {{1, 2, 3, 4},
           {2, 2, 3, 4},
           {5, 5, 6, 6},
           {7, 8, 9, 9}}
Output: 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9
Explanation:
The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9].
```

---

### Approach

1. **Custom Data Structure - Triplet:**

   - `Triplet` class is used to store each element along with its originating array's index and the element's index within that array.
   - Attributes:
     - `value`: The element's value.
     - `positionArr`: The index of the array the element came from.
     - `positionEle`: The index of the element within its array.

2. **Priority Queue with Comparator:**

   - Use a min-heap (priority queue) to maintain the order of elements.
   - Define a custom comparator to ensure that the heap is sorted based on the element values.

3. **Initialize the Min-Heap:**

   - Push the first element of each of the `k` arrays into the heap.

4. **Merge Process:**

   - Extract the smallest element from the heap and add it to the result array.
   - Push the next element from the same array (if it exists) into the heap.
   - Repeat this process until all elements are extracted.

5. **Return the Result:**
   - Return the merged array containing all `k * k` elements in sorted order.

---

### Code

```cpp
// { Driver Code Starts
#include <bits/stdc++.h>
#define N 105
using namespace std;

// Function to print a vector.
void printArray(vector<int> arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
// } Driver Code Ends

/**
 * @brief A Triplet class to store value and its array positions.
 */
class Triplet {
public:
    int value;          ///< The value of the element.
    int positionArr;    ///< The index of the array the element came from.
    int positionEle;    ///< The index of the element within its array.

    /**
     * @brief Constructor for the Triplet class.
     * @param v The value of the element.
     * @param pA The index of the array.
     * @param pE The index of the element within the array.
     */
    Triplet(int v, int pA, int pE) : value(v), positionArr(pA), positionEle(pE) {}
};

/**
 * @brief Custom comparator for the priority queue to maintain a min-heap.
 */
struct myComparator {
    bool operator()(Triplet t1, Triplet t2) {
        return t1.value > t2.value; // Min-heap based on the element value.
    }
};

/**
 * @brief Solution class containing the method to merge K sorted arrays.
 */
class Solution {
public:
    /**
     * @brief Function to merge K sorted arrays.
     * @param arr A 2D vector containing the sorted arrays.
     * @param K The number of sorted arrays.
     * @return A sorted vector containing all elements.
     */
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        vector<int> ans; // To store the merged sorted elements.

        // Priority queue (min-heap) to store Triplet objects.
        priority_queue<Triplet, vector<Triplet>, myComparator> pq;

        // Push the first element of each array into the heap.
        for (int i = 0; i < K; i++) {
            Triplet t(arr[i][0], i, 0);
            pq.push(t);
        }

        // Extract elements from the heap and add to the result.
        while (!pq.empty()) {
            Triplet current = pq.top();
            pq.pop();
            ans.push_back(current.value);

            int arrP = current.positionArr;  // Array index.
            int eleP = current.positionEle;  // Element index in the array.

            // Push the next element of the same array into the heap.
            if (eleP + 1 < arr[arrP].size()) {
                Triplet t(arr[arrP][eleP + 1], arrP, eleP + 1);
                pq.push(t);
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<vector<int>> arr(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
```

---

### Explanation of the Code

- **Triplet Class**: Stores the value, the array index (`positionArr`), and the element index (`positionEle`) in the array.
- **Priority Queue Initialization**: The min-heap is used to always extract the smallest element.
- **Merging Logic**:
  - Insert the smallest element into `ans`.
  - Push the next element from the same array into the heap if it exists.
- **Time Complexity**: `O(k^2 * log(k))` due to heap operations.
- **Space Complexity**: `O(k^2)` for storing the result array and `O(k)` for the heap.

---

### Usage and Edge Cases

- This solution is optimal for merging multiple sorted lists with minimal comparisons.
- Handles edge cases like arrays with identical elements and arrays of varying lengths.
- Assumes that the input arrays are sorted as required.

This solution provides a clean and efficient way to merge `k` sorted arrays using a priority queue, ensuring that the merged output is sorted with optimal time complexity.

## Other Solution

### Solution - 1

```cpp
vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int> resp;
        int i = 0;
        int j = 0;
        while(i < k) {
            resp.push_back(arr[i][j]);
            j++;
            if(j == k){
                j = 0;
                i++;
            }
        }
        sort(resp.begin(), resp.end());
        return resp;

    }
```

### Solution - 2

```java
class Solution
{
    //Function to merge k sorted arrays.
    public static ArrayList<Integer> mergeKArrays(int[][] arr,int k)
    {

        TreeMap<Integer, Integer> map =  new TreeMap<>();

        for(int i=0; i<k; i++)
        {
            for(int j=0; j<k; j++)
            {
                map.put(arr[i][j], map.getOrDefault(arr[i][j],0)+1);
            }
        }

        ArrayList<Integer> al = new ArrayList<>();

        for(Map.Entry<Integer, Integer> entry: map.entrySet())
        {
            int key = entry.getKey();
            int val = entry.getValue();
            while(val != 0)
            {
                al.add(key);
                val--;
            }
        }
        return al;

    }
}
```

### Solution - 3

```cpp
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        vector<pair<int,pair<int,int>>> v;
        for(int i = 0;i<k;i++){
            v.push_back(make_pair(arr[i][0] ,make_pair(i,0)));
        }
        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q(v.begin(),v.end());

        vector<int> ans;
        while(!q.empty()){
            auto elem = q.top();
            q.pop();
            ans.push_back(elem.first);
            int row = elem.second.first;
            int col = elem.second.second;
            if(col +1 < k){
                q.push(make_pair(arr[row][col+1],make_pair(row,col+1)));
            }
        }
        return ans;
    }
};
```

### Solution - 4 (Merge Sort)

````cpp
 void merge(vector<int> &arr,int start ,int mid ,int end){
        int left = start;
        int right = mid +1;
        int index = 0;
        vector<int> temp(end - start +1);
        while(left <=mid && right <= end){
            if(arr[left] <= arr[right]){
                temp[index++]= arr[left];
                left++;
            }
            else{
                temp[index++]= arr[right];
                right++;
            }
        }

        while(left <=mid){
             temp[index++]= arr[left];
                left++;
        }

        while(right  <= end){
             temp[index++]= arr[right];
                right++;
        }

       for (int i = 0; i < temp.size(); i++) {
        arr[start + i] = temp[i];
    }
    }

    void mergeSort(vector<int> &arr,int start,int end,int portion,int k){
        if(portion == 1 ) return;

        int mid = start + (portion)/2 *k -1;
        mergeSort(arr,start,mid,portion/2,k);
        mergeSort(arr,mid+1,end,(portion - (portion/2)),k);
        merge(arr,start,mid,end);
    }

    vector<int> mergeKArrays(vector<vector<int>> srr, int k){

        vector<int> arr;
        for(int i = 0;i<k;i++){
            for(int j = 0;j<k;j++){
                arr.push_back(srr[i][j]);
            }
        }

        mergeSort(arr,0,arr.size()-1,k,k);
        return arr;
    }
````
