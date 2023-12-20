/*
Aaditya Mittal- W5en you make the same mistake twice, its not a mistake, its a decision.
*/

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void explainStack()
{

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.emplace(50); // Similar to push

    std::cout << "Stack Size: " << st.size() << std::endl;
    std::cout << "Stack Top: " << st.top() << std::endl;

    st.pop();

    std::cout << "Stack size after Popping: " << st.size() << std::endl;

    std::cout << "Stack empty or not: " << st.empty() << std::endl; // 0 means false, 1 means true

    std::cout << "Stack swap: " << std::endl;
    stack<int> st1;
    st.swap(st1);

    std::cout << "Stack 1 Size after swapping: " << st1.size() << std::endl;
    std::cout << "Original Stack Size after swapping: " << st.size() << std::endl;
}

int main()
{
    explainStack();

    // Stack is Last in First Out
    //All the operations are O(1) operations 

    return 0;
}