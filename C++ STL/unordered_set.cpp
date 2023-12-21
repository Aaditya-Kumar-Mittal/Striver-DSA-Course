/*
Aaditya Mittal- When you make the same mistake twice, its not a mistake, its a decision.
*/

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void explainUnorderedSet()
{

    unordered_set<int> variable_name;
    unordered_set<int> s;
    unordered_set<string> str;

    s.begin(); // begin() – return an iterator pointing to the first element in the unordered set.
    s.end();   // end() – returns an iterator to the theoretical element after the last element.
    s.insert(1);
    s.insert(2);
    s.count(2); // returns true // count() – it returns 1 if the element is present in the container otherwise 0.
    s.clear();  // clear() – deletes all the elements in unordered set.
    s.erase(1); // erase() – to delete a single element or elements between a particular range.
}

int main()
{
    explainUnorderedSet();

    // An unordered set in STL is a container that stores unique elements in no particular order. Every operation on an unordered set takes O(1) complexity in the average case and takes O(n) in the worst case.

    unordered_set<int> s;
    for (int i = 1; i <= 10; i++)
    {
        s.insert(i);
    }

    cout << "Elements present in the unordered set: ";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    int n = 2;
    if (s.find(2) != s.end())
        cout << n << " is present in unordered set" << endl;

    s.erase(s.begin());
    cout << "Elements after deleting the first element: ";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "The size of the unordered set is: " << s.size() << endl;

    if (s.empty() == false)
        cout << "The unordered set is not empty " << endl;
    else
        cout << "The unordered set is empty" << endl;
    s.clear();
    cout << "Size of the unordered set after clearing all the elements: " << s.size();

    return 0;
}