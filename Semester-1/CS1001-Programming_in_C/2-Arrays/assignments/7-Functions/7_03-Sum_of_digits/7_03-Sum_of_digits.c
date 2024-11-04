// Find the sum of digits of a number using call by value and call by reference

#include <stdbool.h>
#include <stdio.h>

int sumOfDigitsVal(long num) {
  // Sum of digits using call by value
  long tmpnum = num;
  int sum = 0;
  int r;
  while (tmpnum > 0) {

    r = tmpnum % 10;
    sum = sum + (r);
    tmpnum = tmpnum / 10;
  }
  // printf("%ld -> %d\n", num, sum);

  return sum;
}

int sumOfDigitsRef(long *numptr) {
  // Sum of digits using call by reference
  long tmpnum = *numptr;
  int sum = 0;
  int r;
  while (tmpnum > 0) {

    r = tmpnum % 10;
    sum = sum + (r);
    tmpnum = tmpnum / 10;
  }
  // printf("%ld -> %d\n", num, sum);

  return sum;
}

int main() {

  long userinp;
  printf("Enter a number to find its sum: ");
  scanf("%ld", &userinp);

  printf("Sum of digits of %ld using call by value is %d\n", userinp,
         sumOfDigitsVal(userinp));
  printf("Sum of digits of %ld using call by reference is %d\n", userinp,
         sumOfDigitsRef(&userinp));
}
