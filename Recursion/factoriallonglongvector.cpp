#include <iostream>
#include <vector>

std::vector<long long> factorialNumbers(long long n)
{
    std::vector<long long> result;
    long long fact = 1;
    int i = 1;

    while (fact <= n)
    {
        result.push_back(fact);
        ++i;
        fact *= i;
    }

    return result;
}

int main()
{
    long long limit;
    std::cout << "Enter the limit: ";
    std::cin >> limit;

    std::vector<long long> result = factorialNumbers(limit);

    std::cout << "Factorial numbers less than or equal to " << limit << ": ";
    for (long long num : result)
    {
        std::cout << num << " ";
    }

    return 0;
}
