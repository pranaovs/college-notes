#include <stdbool.h>
#include <stdio.h>

int sumOfDigits(long num) {
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

int main() {

  long userinp;
  printf("Enter a number to find its sum: ");
  scanf("%ld", &userinp);

  printf("Sum of digits of %ld is %d\n", userinp, sumOfDigits(userinp));
}
