#include <list>
#include <iostream>
using namespace std;

list<long> prime_divisor(long number);
bool is_prime(long number);

int main()
{
  list<long> prime_list;
  long large_number = 600851475143;

  prime_list = prime_divisor(large_number);

  while (!prime_list.empty())
  {
    cout << prime_list.front() << "\n";
    prime_list.pop_front();
  }

  return 0;
}

list<long> prime_divisor(long number)
{
  long divisor;
  list<long> prime_list;
  list<long> new_primes;

  for (long i = 2; i < number/2; i++)
  {
    if (number % i == 0)
      divisor = number/i;
    else
      continue;

    if (number % divisor == 0 && is_prime(divisor))
    {
      prime_list.push_front(divisor);

      if (!is_prime(i))
      {
        new_primes = prime_divisor(i);
        prime_list.merge(new_primes);
      }
      else
      {
        prime_list.push_front(i);
      }

      break;
    }
  }

  return prime_list;
}

bool is_prime(long number)
{
  bool prime = true;
  for (long i = 2; i < number/2; i++)
  {
    if (number % i == 0)
    {
      prime = false;
      break;
    }
  }
  return prime;
}
