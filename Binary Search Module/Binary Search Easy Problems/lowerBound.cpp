#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lowerBoundFunction(vector<int> &a, int n, int x) {
    int low = 0, high = n, mid, ans = n;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (a[mid] >= x) {
            ans = mid;
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    // Input size of the array
    int n;
    cin >> n;

    // Input elements of the array
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    // Print the array elements
    cout << "Printing Array Elements: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Input the target element to search for
    int target;
    cin >> target;

    // Perform binary search using lowerBoundFunction
    int lowerbound = lowerBoundFunction(array, n, target);
    cout << "Lower bound of " << target << " is : " << lowerbound << " using function" << endl;

    // Perform binary search using lower_bound function from STL
    vector<int>::iterator it = lower_bound(array.begin(), array.end(), target);
    cout << "Lower bound of " << target << " is : " << distance(array.begin(), it) << " using STL" << endl;

    return 0;
}
