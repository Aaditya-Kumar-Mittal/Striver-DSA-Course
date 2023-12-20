/*
Aaditya Mittal- When you make the same mistake twice, its not a mistake, its a decision.
*/

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void explainPriorityQueue()
{

    // MAXIMUM HEAP
    std::cout << "Priority queue for Maximum element at top" << std::endl;
    priority_queue<int> pq;

    pq.push(10);
    pq.push(20);
    pq.push(40);
    pq.push(30);
    pq.push(800);

    std::cout << pq.top() << std::endl;
    pq.pop();
    std::cout << pq.top() << std::endl;

    // MINIMUM HEAP
    std::cout << "Priority queue for Minimum element at top" << std::endl;
    priority_queue<int, vector<int>, greater<int>> pmq;

    pmq.push(10);
    pmq.push(20);
    pmq.push(40);
    pmq.push(30);
    pmq.push(800);

    std::cout << pmq.top() << std::endl;
    pmq.pop();
    std::cout << pmq.top() << std::endl;
}

int main()
{
    explainPriorityQueue();
    // PriorityQueue is elements are stored in certain priority, inside it a tree structure is maintained

    /*

    Time Complexities:- 

    push - O(logn)
    pop - O(logn)
    top - O(1)

    */
    return 0;
}