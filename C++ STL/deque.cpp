/*
Aaditya Mittal- When you make the same mistake twice, its not a mistake, its a decision.
*/

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void explainDeque()
{

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;

    std::cout << "Deque Container" << std::endl;

    deque<int> dq;

    std::cout << "Deque size function: " << dq.size() << std::endl;

    std::cout << "Deque push_back function: " << std::endl;
    dq.push_back(2);
    std::cout << "Deque size function: " << dq.size() << std::endl;
    std::cout << "Deque elements: " << std::endl;
    for (auto i : dq)
    {
        cout << i << " ";
    }
    cout << endl
         << endl

        ;
    std::cout << "Deque push_front function: " << std::endl;
    dq.push_front(3985);
    std::cout << "Deque size function: " << dq.size() << std::endl;
    std::cout << "Deque elements: " << std::endl;
    for (auto i : dq)
    {
        cout << i << " ";
    }
    cout << endl
         << endl;

    std::cout << "Deque emplace_back function: " << std::endl;
    dq.emplace_back(4);
    std::cout << "Deque size function: " << dq.size() << std::endl;
    std::cout << "Deque elements: " << std::endl;
    for (auto i : dq)
    {
        cout << i << " ";
    }
    cout << endl
         << endl;

    std::cout << "Deque emplace_front function: " << std::endl;
    dq.emplace_front(4);
    std::cout << "Deque size function: " << dq.size() << std::endl;
    std::cout << "Deque elements: " << std::endl;
    for (auto i : dq)
    {
        cout << i << " ";
    }
    cout << endl
         << endl;

    std::cout << "Deque pop_front function: " << std::endl;
    dq.pop_front();
    std::cout << "Deque size function: " << dq.size() << std::endl;
    std::cout << "Deque elements: " << std::endl;
    for (auto i : dq)
    {
        cout << i << " ";
    }
    cout << endl
         << endl;

    std::cout << "Deque pop_back function: " << std::endl;
    dq.pop_back();
    std::cout << "Deque size function: " << dq.size() << std::endl;
    std::cout << "Deque elements: " << std::endl;
    for (auto i : dq)
    {
        cout << i << " ";
    }
    cout << endl
         << endl;

    cout << dq.front() << endl;
    cout << dq.back() << endl;

    // rest all functions copy, rend, rbegin, end, begin,clear,erase,insert,swap are same as vector

    cout << "------------------------------------------------------------------------------------------------" << endl;
}

int main()
{
    explainDeque();

    /*
    Similar to vector
    Only difference is it gives us front operation as well.
    Push_front and back are easy as insert function in vector is very costly
    For a Deque, double linked Deque is maintained and for doubly linked Deque

    */

    return 0;
}