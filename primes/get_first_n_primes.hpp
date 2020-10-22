#include <list>

using namespace std;

namespace primes
{
    list<unsigned int> get_first_n_primes(const unsigned short& N);

    unsigned int get_first_n_primes_cache_size();
    unsigned int get_first_n_primes_cache_capacity();
}