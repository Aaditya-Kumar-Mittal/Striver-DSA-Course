#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (auto i : arr)
    {
        cin >> i;
    }

    return 0;
}
