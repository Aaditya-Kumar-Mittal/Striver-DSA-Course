#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::cout << "next_permutation in STL is a built-in function which as the name suggests returns the next lexicographically greater permutation of the elements in the container passed to it as an argument." << std::endl;

    cout << endl;

    std::cout << "Yes, next_permutation() accepts two iterators (begin and end) of a container(example, an array or vector ) as parameters and modifies the container to store the next lexicographically greater permutation of elements within the range [begin, end)]" << std::endl;

    cout << endl;

    std::cout << "Does it return anything?\nYes,it returns true if a next lexicographically greater permutation is possible, otherwise, it returns false." << std::endl;

    int arr[] = {1, 3, 2};

    do
    {
        cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    } while (next_permutation(arr, arr + 3)); // using in-built function of C++

    return 0;
}