#include <bits/stdc++.h>

using namespace std;

class Stack
{
  int size, *arr, top;

public:
  Stack()
  {
    top = -1;

    size = 1000;

    arr = new int[size];
  }

  void push(int x)
  {
    top++;

    arr[top] = x;
  }

  int pop()
  {

    int el = arr[top];

    top--;

    return el;
  }

  int Top()
  {
    return arr[top];
  }

  int Size()
  {
    return top + 1;
  }
};

int main()
{

  Stack s;

  s.push(10);
  s.push(11);
  s.push(12);
  s.push(13);

  std::cout << "Element at top of the stack is: " << s.Top() << std::endl;
  std::cout << "Size of the stack before popping: " << s.Size() << std::endl;
  std::cout << "Popped Element is: " << s.pop() << std::endl;
  std::cout << "Size of the stack after popping: " << s.Size() << std::endl;
  std::cout << "Element at top of the stack is: " << s.Top() << std::endl;

  return 0;
}