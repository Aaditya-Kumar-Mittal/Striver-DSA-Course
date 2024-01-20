Number Hashing
1. Inside main the max array size one can declare is 10 raised to power 6.
2. For declaring an array bigger than this size, use global declaration of array
3. For 10to9, 10to10, 10to12, one cannot hash using arrays. Thus use STL in C++ and Collection in Java.
3. Use map and unordered map in STL
4. Use hashmap in Collections
5. map<int, int>
       key, value
6. Map stores all the values in sorted order.
7. mpp[key]if doesn't exist returns 0 and will not store in the map
8. ********* Time Complexity of Map - Storing and Fetching takes log(N) in average, worse, best cases *********
9. unordered map will also work in a similar fashion iteration will be unsorted order
10. ********* Advantage of using Unordered Map Time Complexity of Unordered Map - Storing and Fetching takes O(1) constant time complexity in average and best cases, takes O(N) linear time in worst cases *******
11. If using loop, most of the times use UNORDERED MAP, otherwise use map if Time Limit Exceeded
12. The worst case happens due to internal collisions.


Character Array Hashing
1. Map Code character-'a' for lowercase letters arr[26]={0}
2. Map Code character-'A' for uppercase letters arr[26]={0}
3. Map Code for all 256 characters use arr[256]=0;
4. The array declaration will never fail inside main for obvious reasons.
5. Use ASCII Mapping
