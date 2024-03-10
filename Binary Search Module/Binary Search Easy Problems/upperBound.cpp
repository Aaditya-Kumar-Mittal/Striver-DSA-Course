#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int upperBoundFunction(vector<int> &a, int n, int x) {
    int low = 0, high = n, mid, ans = n;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (a[mid] > x) {
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

    // Perform binary search using upperBoundFunction
    int upperbound = upperBoundFunction(array, n, target);
    cout << "Upper bound of " << target << " is : " << upperbound << " using function" << endl;

    // Perform binary search using upper_bound function from STL
    vector<int>::iterator it = upper_bound(array.begin(), array.end(), target);
    cout << "Upper bound of " << target << " is : " << distance(array.begin(), it) << " using STL" << endl;

    return 0;
}
