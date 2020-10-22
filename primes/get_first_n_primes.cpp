#include <mutex>
#include <list>
#include <vector>


#include "get_first_n_primes.hpp"

using namespace std;

namespace primes
{
    list<unsigned int> get_first_n_primes(list<unsigned int> alreadyCalculatedPrimes, const unsigned short& N)
    {
        if(N == 0)
        {
            return {};
        }
        else
        {
            list<unsigned int> primes(alreadyCalculatedPrimes.begin(), next(alreadyCalculatedPrimes.begin(), min(size_t(N), alreadyCalculatedPrimes.size())));
            for(auto idxN = N - primes.size(); idxN > 0; idxN--)
            {
                auto possiblePrime = primes.back() + 2;
                while(true)
                {
                    // check is prime
                    auto isPrime = true;
                    for(auto primeIt = next(primes.begin()); primeIt != primes.end(); primeIt++)
                    {
                        if(possiblePrime % *primeIt == 0)
                        {
                            isPrime = false;
                            break;
                        }
                    }
                    if (isPrime)
                    {
                        primes.push_back(possiblePrime);
                        break;
                    }
                    
                    possiblePrime += 2;
                }
            }
            return primes;
        }
    }

    list<unsigned int> get_first_n_primes(const unsigned short& N)
    {
        static mutex s_alreadyCalculatedPrimeNumbersMutex;
        static list<unsigned int> s_alreadyCalculatedPrimeNumbers;

        // initial initialization already calculated primes list
        list<unsigned int> alreadyCalculatedPrimeNumbers;
        {
            lock_guard<mutex> alreadyCalculatedPrimeNumbersMutexLock(s_alreadyCalculatedPrimeNumbersMutex);
            {
                if(s_alreadyCalculatedPrimeNumbers.size() == 0)
                {
                    s_alreadyCalculatedPrimeNumbers = {2, 3, 5, 7, 11, 13};
                }
                alreadyCalculatedPrimeNumbers = s_alreadyCalculatedPrimeNumbers;
            }
        }
        // get first N primes
        auto primes = get_first_n_primes(alreadyCalculatedPrimeNumbers, N);
        // if new primes were generated store them
        const int alreadyCalculatedPrimeNumbersMax = 10 * 1024;
        if(alreadyCalculatedPrimeNumbers.size() < alreadyCalculatedPrimeNumbersMax)
        {
            if(primes.size() > alreadyCalculatedPrimeNumbers.size())
            {
                lock_guard<mutex> alreadyCalculatedPrimeNumbersMutexLock(s_alreadyCalculatedPrimeNumbersMutex);
                {
                    if(primes.size() > s_alreadyCalculatedPrimeNumbers.size())
                    {
                        s_alreadyCalculatedPrimeNumbers = primes;
                    }
                }
            }
        }
        return primes;
    }
}