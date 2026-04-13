#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> mp;

    // Insert
    mp["apple"] = 3;
    mp["banana"] = 2;

    // Access
    cout << "Apple Count: " << mp["apple"] << endl;

    // Search
    if (mp.find("banana") != mp.end()) {
        cout << "Banana is found!" << endl;
    }

    // Delete
    mp.erase("banana");

    return 0;
}