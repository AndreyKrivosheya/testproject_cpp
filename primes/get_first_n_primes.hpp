#include <list>

using namespace std;

namespace primes
{
    list<unsigned int> get_first_n_primes(list<unsigned int> alreadyCalculatedPrimes, const unsigned short& N);
    list<unsigned int> get_first_n_primes(const unsigned short& N);
}