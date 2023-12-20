/*
Aaditya Mittal- When you make the same mistake twice, its not a mistake, its a decision.
*/

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void explainSet()
{

    set<int> st;

    st.insert(1);  //{1}
    st.emplace(2); //{1,2}
    st.insert(2);  //{1,2}
    st.insert(4);  //{1,2,4}
    st.insert(3);  //{1,2,3,}

    // Functionality of insert in vector can also be used that only increases efficiency
    // begin(), end(), rbegin(), rend(), size(), empty(), size() can also be used

    set<int> set1 = {1, 2, 3, 4, 5};
    auto it = set1.find(3); // returns an iterator which points to 3
    cout << *it << endl;
    auto it1 = set1.find(6); // since 6 is not there, ot will always return an iterator pointing to after the last element i.e. the end

    set1.erase(5);  //{1,2,3,4} //takes logarithmic time
    set1.erase(it); //{1,2,3,4} //takes logarithmic time

    int count = set1.count(1);
    int count3 = set1.count(3);

    std::cout << count << std::endl;
    std::cout << count3 << std::endl;

    set<int> set2 = {10, 20, 30, 40, 50, 60};
    auto it2 = st.find(20);
    auto it4 = st.find(50);
    set2.erase(it2, it4); // erases 20,30,40 {10,50,60}

    // lower_bound and upper_bound function works in the same way as in vector does

    auto lb = set2.lower_bound(10);
    auto ub = set2.upper_bound(60);
}

int main()
{
    explainSet();

    // Set stores everything in sorted order and only unique elements
    // In set, a tree order is maintained.

    return 0;
}