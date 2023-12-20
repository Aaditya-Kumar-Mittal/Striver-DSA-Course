/*
Aaditya Mittal- When you make the same mistake twice, its not a mistake, its a decision.
*/

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void explainQueue()
{
    queue<int> q;

    q.push(1);
    q.push(10);
    q.push(100);
    q.push(10000);
    q.emplace(100000000);
    q.back() += 5;
    std::cout << q.back() << std::endl;

    q.front() += 15;
    std::cout << q.front() << std::endl;

    std::cout << q.size() << std::endl;
    q.pop();
    std::cout << q.size() << std::endl;
    std::cout << q.front() << std::endl;
}

int main()
{
    explainQueue();
    // Queue is fifo first in first out
    return 0;
}