#include <iostream>
#include <sstream>
using namespace std;

bool has_divisors(int number);
bool is_palindrome(int number);

int main() {
  int largest_number = 999 * 999;
  int smallest_number = 100 * 100;

  for (int i = largest_number; i >= smallest_number; i--) {
    if (is_palindrome(i)) {

      if (has_divisors(i)) {
        cout << i << "\n";
        break;
      }
    } 
  }
  return 0;
}

bool is_palindrome(int number) {
  bool palindrome = true;
  string num = static_cast<ostringstream*>( &(ostringstream() << number) )->str();
  int first = 0;
  int last = num.length() - 1;

  while (first < last) {
    if (num[first] != num[last]) {
      palindrome = false;
      break;
    }

    first++;
    last--;
  }

  return palindrome;
}

bool has_divisors(int number) {
  bool has = false;
  int divisor = 999;

  while (divisor >= 100) {
    if (number % divisor == 0 and number / divisor >= 100 and number / divisor < 1000) {
      has = true;
      break;
    }
    divisor--;
  }

  return has;
}
