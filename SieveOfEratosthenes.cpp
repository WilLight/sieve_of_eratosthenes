// Example program
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

std::vector<int> sieve_of_eratosthenes(const int prime_count)
{
    //Populate vector
    std::vector<bool> numbers(prime_count + 1, true);

    //Sieve algorithm
    for (int i = 2; i <= prime_count; i++)
    {
        if (numbers[i] == true)
        {
            for (int j = pow(i, 2); j <= prime_count; j += i)
            {
                numbers[j] = false;
            }
        }
    }

    //Record primes
    std::vector<int> primes;
    for (int i = 1; i <= prime_count; i++)
    {
        if (numbers[i] == true)
        {
            primes.push_back(i);
        }
    }

    //Repeat a modified algorithm until reaching the required prime count
    for (int partition = 2; partition < prime_count; partition++)
    {
        //Repopulate vector
        numbers = std::move(std::vector<bool>(prime_count + 1, true));

        //Modified sieve algorithm
        int idx = 1;
        while (primes[idx] <= sqrt(prime_count * partition))
        {
            for (int j = pow(primes[idx], 2); j <= prime_count * partition; j += primes[idx])
            {
                if (j > prime_count * (partition - 1))
                {
                    numbers[j - prime_count * (partition - 1)] = false;
                }
            }
            idx += 1;
        }

        //Record primes
        for (int i = 1; i <= prime_count; i++)
        {
            if (numbers[i] == true)
            {
                primes.push_back(i + prime_count * partition);
                if (primes.size() == prime_count)
                {
                    return primes;
                }
            }
        }
    }

    return primes;
}

int main()
{
    auto vector = sieve_of_eratosthenes(1000);
    for (int i : vector)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    std::cout << vector.size();
}
