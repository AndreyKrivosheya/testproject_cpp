#include <mutex>
#include <list>
#include <vector>


#include "get_first_n_primes.hpp"

using namespace std;

namespace primes
{
    list<unsigned int> get_first_n_primes(vector<unsigned int> alreadyCalculatedPrimes, const unsigned short& N)
    {
        if(N == 0)
        {
            return {};
        }
        else
        {
            list<unsigned int> primes;
            std::copy(alreadyCalculatedPrimes.begin(), next(alreadyCalculatedPrimes.begin(), min(size_t(N), alreadyCalculatedPrimes.size())), back_inserter(primes));
            for(auto leftToFindPrimes = N - primes.size(); leftToFindPrimes > 0; leftToFindPrimes--)
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

    mutex g_alreadyCalculatedPrimeNumbersMutex;
    vector<unsigned int> g_alreadyCalculatedPrimeNumbers;

    unsigned int get_first_n_primes_cache_capacity()
    {
        lock_guard<mutex> alreadyCalculatedPrimeNumbersMutexLock(g_alreadyCalculatedPrimeNumbersMutex);
        return g_alreadyCalculatedPrimeNumbers.capacity();
    }

    unsigned int get_first_n_primes_cache_size()
    {
        lock_guard<mutex> alreadyCalculatedPrimeNumbersMutexLock(g_alreadyCalculatedPrimeNumbersMutex);
        return g_alreadyCalculatedPrimeNumbers.size();
    }

    list<unsigned int> get_first_n_primes(const unsigned short& N)
    {
        // initial initialization already calculated primes list
        vector<unsigned int> alreadyCalculatedPrimeNumbers;
        {
            lock_guard<mutex> alreadyCalculatedPrimeNumbersMutexLock(g_alreadyCalculatedPrimeNumbersMutex);
            {
                if(g_alreadyCalculatedPrimeNumbers.size() == 0)
                {
                    g_alreadyCalculatedPrimeNumbers.reserve(10 * 1024);
                    g_alreadyCalculatedPrimeNumbers = {2u, 3u, 5u, 7u, 11u, 13u};
                }
                alreadyCalculatedPrimeNumbers = g_alreadyCalculatedPrimeNumbers;
            }
        }
        // get first N primes
        auto primes = get_first_n_primes(alreadyCalculatedPrimeNumbers, N);
        // if new primes were generated store them
        if(primes.size() > alreadyCalculatedPrimeNumbers.size())
        {
            lock_guard<mutex> alreadyCalculatedPrimeNumbersMutexLock(g_alreadyCalculatedPrimeNumbersMutex);
            {
                if(g_alreadyCalculatedPrimeNumbers.size() < g_alreadyCalculatedPrimeNumbers.capacity())
                {
                    if(primes.size() > g_alreadyCalculatedPrimeNumbers.size())
                    {
                        std::copy(
                            std::next(primes.begin(), g_alreadyCalculatedPrimeNumbers.size()),
                            std::prev(primes.end(), primes.size() - min(primes.size(), g_alreadyCalculatedPrimeNumbers.capacity())),
                            back_inserter(g_alreadyCalculatedPrimeNumbers));
                    }
                }
            }
        }
        return primes;
    }
}