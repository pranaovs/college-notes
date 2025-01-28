#include <cmath>

class NumberFun {

private:
  /* Count the number of digits in a number
   * For internal use only
   *
   * Arguments:
   * int *n: the number to count the digits
   * int *count: saves the number of digits
   */
  void digitCount(int *n, int *count) {
    int *tmp = new int(*n);
    *count = 0;
    while (*tmp > 0) {
      (*count)++;
      *tmp /= 10;
    }
    delete tmp;
  }

public:
  /* A prime number is a number that is greater than 1 and divided by 1 or
   * itself only. For example, 2, 3, 5, 7, 11, 13, 17, etc.
   *
   * Arguments:
   * int *n: the number to check
   * int *result: saves the result of the check
   */
  void isPalindrome(int *n, bool *result) {
    int *reversed = new int();
    int *temp = new int(*n);
    int *rem = new int();

    while (*temp > 0) {
      *rem = *temp % 10;
      *reversed = *reversed * 10 + *rem;
      *temp /= 10;
    }

    delete temp;
    delete rem;

    (*result) = (*n == *reversed);
    delete reversed;
  }

  /* An Armstrong number is a number that is equal to the sum of its own digits
   * raised to the power of the number of digits. For example, 153 is an
   * Armstrong number because 1^3 + 5^3 + 3^3 = 153.
   *
   * Arguments:
   * int *n: the number to check
   * bool *result: saves the result of the check
   */
  void isArmstrong(int *n, bool *result) {
    int *sum = new int();
    int *temp = new int(*n);
    int *digits = new int();
    digitCount(temp, digits);
    int *rem = new int();

    while (*temp > 0) {
      *rem = *temp % 10;
      *sum += pow(*rem, *digits);
      *temp /= 10;
    }

    delete temp;
    delete digits;
    delete rem;

    *result = (*n == *sum);
    delete sum;
  }

  /* A perfect number is a positive integer that is equal to the sum of its
   * proper divisors excluding itself. For example, 28 is a perfect number
   * because its proper divisors are 1, 2, 4, 7, 14 and 1 + 2 + 4 + 7 + 14 = 28.
   *
   * Arguments:
   * int *n: the number to check
   * bool *result: saves the result of the check
   */
  void isPerfect(int *n, bool *result) {
    int *sum = new int();

    int *i = new int;
    for (*i = 1; *i < *n; (*i)++) {
      if (*n % *i == 0) {
        *sum += *i;
      }
    }
    delete i;

    *result = (*n == *sum);
    delete sum;
  }
};
