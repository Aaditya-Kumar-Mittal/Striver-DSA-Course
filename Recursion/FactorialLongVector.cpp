#include <iostream>
#include <vector>

long long factorial(long long n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

std::vector<long long> factorialNumbers(long long n)
{
    std::vector<long long> result;

    for (int i = 1; i <= n; i++)
    {
        if (factorial(i) > n)
        {
            break;
        }
        result.push_back(factorial(i));
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
