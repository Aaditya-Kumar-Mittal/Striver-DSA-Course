/*
Aaditya Mittal- When you make the same mistake twice, its not a mistake, its a decision.
*/

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void explainList()
{

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    std::cout << "List Container" << std::endl;

    list<int> ls;

    std::cout << "List size function: " << ls.size() << std::endl;

    std::cout << "List push_back function: " << std::endl;
    ls.push_back(2);
    std::cout << "List size function: " << ls.size() << std::endl;
    std::cout << "List elements: " << std::endl;
    for (auto i : ls)
    {
        cout << i << " ";
    }
    cout << endl
         << endl

        ;
    std::cout << "List push_front function: " << std::endl;
    ls.push_front(3985);
    std::cout << "List size function: " << ls.size() << std::endl;
    std::cout << "List elements: " << std::endl;
    for (auto i : ls)
    {
        cout << i << " ";
    }
    cout << endl
         << endl;

    std::cout << "List emplace_back function: " << std::endl;
    ls.emplace_back(4);
    std::cout << "List size function: " << ls.size() << std::endl;
    std::cout << "List elements: " << std::endl;
    for (auto i : ls)
    {
        cout << i << " ";
    }
    cout << endl
         << endl;
    std::cout << "List emplace_front function: " << std::endl;
    ls.emplace_front(4);
    std::cout << "List size function: " << ls.size() << std::endl;
    std::cout << "List elements: " << std::endl;
    for (auto i : ls)
    {
        cout << i << " ";
    }
    cout << endl
         << endl;

    // rest all functions copy, rend, rbegin, end, begin,clear,erase,insert,swap are same as vector

    cout << "------------------------------------------------------------------------------------------------" << endl;
}

void printlist(list<int> li)
{
    list<int>::iterator it;
    for (it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    explainList();

    /*
    Similar to vector
    Only difference is it gives us front operation as well.
    Push_front and back are easy as insert function in vector is very costly
    For a list, double linked list is maintained and for doubly linked list

    */

    list<int> li;
    li.push_back(10);
    li.push_back(20);
    li.push_front(30);
    li.push_front(40);
    li.push_front(50);

    cout << "The elements in the list are: ";
    printlist(li);
    cout << "Reversing the list: ";
    li.reverse();
    printlist(li);
    cout << "Sorting the list: ";
    li.sort();
    printlist(li);
    cout << "The size of the list is: " << li.size() << endl;
    cout << "The first element in the list: " << li.front() << endl;
    cout << "Deleting the first element" << endl;
    li.pop_front();
    printlist(li);
    cout << "The last element of the list: " << li.back() << endl;
    cout << "Deleting the last element" << endl;
    li.pop_back();
    printlist(li);

    return 0;
}