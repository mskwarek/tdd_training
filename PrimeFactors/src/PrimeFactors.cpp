#include "PrimeFactors.h"

std::vector<int> PrimeFactors::getPrimeFactors(int n)
{
    auto tmpList = std::vector<int>{};
    int divisor = 2;

    while(n > 1)
    {
        while(n % divisor == 0)
        {
            tmpList.emplace_back(divisor);
            n /= divisor;
        }
        ++divisor;
    }

    return tmpList;
}