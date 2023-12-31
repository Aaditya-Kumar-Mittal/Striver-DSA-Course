#include <bits/stdc++.h>
#include <math.h>
#include <vector>
using namespace std;

void explainVectors()
{

    cout << "------------------------------------------------------------------------------------------------" << endl;
    vector<int> v; // Creates an empty container

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    std::cout << "Printing Vector's v size: " << v.size() << std::endl;

    std::cout << "Printing Vector's v elements: ";

    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "------------------------------------------------------------------------------------------------" << endl;

    // Emplace_Back

    v.emplace_back(2); // It dynamically increases its size and inserts 2 at back. Emplace_back is faster than push_back;

    std::cout << "Printing Vector's v size after emplace_back: " << v.size() << std::endl;

    std::cout << "Printing Vector's v elements after emplace_back: ";
    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "------------------------------------------------------------------------------------------------" << endl;

    // For pair data type

    vector<pair<int, int>> Pair;

    Pair.push_back({1, 5});

    std::cout << "Printing Pair Vector Size:" << Pair.size() << std::endl;

    std::cout << "Printing Pair Vector Elements:" << Pair[0].first << "," << Pair[0].second << std::endl;

    Pair.emplace_back(24, 2); // automatically assumes (1,2) to be a pair

    std::cout << "Printing Pair Vector Size after emplace back:" << Pair.size() << std::endl;

    std::cout << "Printing Pair Vector Elements after emplace back:" << Pair[1].first << "," << Pair[1].second << std::endl;

    cout << "------------------------------------------------------------------------------------------------" << endl;

    // Vector with instances

    vector<int> vec1(5, 100); // Creates a vector of size 5 with each element as 100

    std::cout << "Printing Vector's vec1 size: " << vec1.size() << std::endl;

    std::cout << "Printing Vector's vec1 elements: ";

    for (auto &i : vec1)
    {
        cout << i << " ";
    }

    cout << endl;
    cout << endl;

    vector<int> vec2(5); // Creates a vector of size 5 with each element as 0

    std::cout << "Printing Vector's vec2 size: " << vec2.size() << std::endl;

    std::cout << "Printing Vector's vec2 elements: ";

    for (auto &i : vec2)
    {
        cout << i << " ";
    }

    cout << endl;
    cout << endl;

    cout << "------------------------------------------------------------------------------------------------" << endl;

    std::cout << "*****************Creating copies of a vector*************" << std::endl;

    vector<int> v1(5, 20);

    std::cout << "Printing Vector's v1 size: " << v1.size() << std::endl;

    std::cout << "Printing Vector's v1 elements: ";

    for (auto &i : v1)
    {
        cout << i << " ";
    }

    cout << endl;

    vector<int> v2(v1);

    std::cout << "Printing Copy Vector's v2 size: " << v2.size() << std::endl;

    std::cout << "Printing Copy Vector's v2 elements: ";

    for (auto &i : v2)
    {
        cout << i << " ";
    }

    cout << endl;

    cout << "------------------------------------------------------------------------------------------------" << endl;

    std::cout << "***************Iterations in a Vector***********" << std::endl;

    vector<int> vec3 = {1, 2, 3, 4, 5};
    vector<int>::iterator it = vec3.begin();

    // vec3.begin() points to memory where 1 is stored

    cout << *(it) << endl;
    it++;
    cout << *(it) << endl;

    it += 2;

    cout << *(it) << endl;

    std::cout << "Accessing using vec3.at(0): " << vec3.at(0) << std::endl;

    vector<int>::iterator endit = vec3.end();
    cout << *(endit) << endl; // Points to a location at the end of vector container i.e after 5;
    endit--;
    cout << *(endit) << endl;

    vector<int>::reverse_iterator rendit = --vec3.rend();
    std::cout << *(rendit) << std::endl;
    vector<int>::reverse_iterator rbeginit = vec3.rbegin()--;
    std::cout << *(rbeginit) << std::endl;

    cout << vec3[0] << " " << vec3.at(0) << endl;

    cout << vec3.back() << endl;

    cout << "Printing all elements using iterator: ";
    for (vector<int>::iterator i = vec3.begin(); i != vec3.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    cout << endl;

    cout << "Printing all elements using auto iterator: ";
    for (auto i = vec3.begin(); i != vec3.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    cout << endl;

    cout << "Printing all elements using for each loop: ";
    for (auto i : vec3)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;

    cout << "------------------------------------------------------------------------------------------------" << endl;

    std::cout << "****************Deletion in a vector: **********************" << std::endl
              << endl
              << endl;

    vector<int> vec4 = {1, 2, 3, 4, 5};

    std::cout << "Before Deletion: " << std::endl;
    std::cout << "Vector4 Size:" << vec4.size() << std::endl;
    std::cout << "Vector4's elements: " << std::endl;
    for (auto i : vec4)
    {
        cout << i << " ";
    }

    cout << endl;
    cout << endl;

    std::cout << "After Deletion: " << std::endl;
    vec4.erase(vec4.begin() + 1);
    vec4.erase(vec4.begin() + 1);
    vec4.erase(vec4.begin() + 1);
    std::cout << "Vector4 Size:" << vec4.size() << std::endl;
    std::cout << "Vector4's elements: " << std::endl;
    for (auto i : vec4)
    {
        cout << i << " ";
    }

    cout << endl;
    cout << endl;

    vector<int> vec5 = {10, 20, 30, 40, 50};

    std::cout << "Before Deletion of range: " << std::endl;
    std::cout << "Vector5 Size:" << vec5.size() << std::endl;
    std::cout << "Vector5's elements: " << std::endl;
    for (auto i : vec5)
    {
        cout << i << " ";
    }

    cout << endl;
    cout << endl;

    std::cout << "After Deletion of range: " << std::endl;
    vec5.erase(vec5.begin() + 2, vec5.begin() + 4); //{start, to toll which want to delete +1}
    std::cout << "Vector5 Size:" << vec5.size() << std::endl;
    std::cout << "Vector5's elements: " << std::endl;
    for (auto i : vec5)
    {
        cout << i << " ";
    }

    cout << endl;
    cout << endl;

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;

    std::cout << "***************** Insertion in a vector **********************" << std::endl;

    std::cout << "After Insertion: " << std::endl;
    vec5.insert(vec5.begin() + 2, 3555);
    std::cout << "Vector5 Size:" << vec5.size() << std::endl;
    std::cout << "Vector5's elements: " << std::endl;
    for (auto i : vec5)
    {
        cout << i << " ";
    }

    cout << endl;
    cout << endl;

    std::cout << "After Insertion Many Elements Identical: " << std::endl;
    vec5.insert(vec5.begin() + 2, 5, 3555);
    std::cout << "Vector5 Size: " << vec5.size() << std::endl;
    std::cout << "Vector5's elements: " << std::endl;
    for (auto i : vec5)
    {
        cout << i << " ";
    }

    cout << endl;
    cout << endl;

    std::cout << "Pop_Back Function: " << std::endl;
    vec5.pop_back();
    std::cout << "Vector5 Size: " << vec5.size() << std::endl;
    std::cout << "Vector5's elements: " << std::endl;
    for (auto i : vec5)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;

    std::cout << "Clear Function: " << std::endl;
    vec5.clear();
    std::cout << "Vector5 Size: " << vec5.size() << std::endl;
    std::cout << "Vector5's elements: " << std::endl;
    for (auto i : vec5)
    {
        cout << i << " ";
    }

    cout << "------------------------------------------------------------------------------------------------" << endl;
}

int main()
{
    explainVectors();

    // Vector is a container.
    // Vector is dynamic in nature, can modify its size.

    return 0;
}