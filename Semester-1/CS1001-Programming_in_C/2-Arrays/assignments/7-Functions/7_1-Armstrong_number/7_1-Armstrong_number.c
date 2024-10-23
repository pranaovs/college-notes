// Program to check if a number is armstrong number

#include <stdbool.h>
#include <stdio.h>

bool checkIfArmstrong(long num) {
  long tmpnum = num;
  long sum = 0;
  int r;
  while (tmpnum > 0) {

    r = tmpnum % 10;         // Get the units place
    sum = sum + (r * r * r); // Add the units place cube to a variable
    tmpnum = tmpnum / 10;    // Remove units place and save the number
  }
  // printf("%ld -> %ld\n", num, sum);
  if (sum == num) {
    return true;
  } else {
    return false;
  }
}

int main() {
  long userinp, num;
  printf("Enter a number to find armstrong numbers until it: ");
  scanf("%ld", &userinp);
  num = 1;

  printf("Trying to find armstrong numbers till %ld\n", userinp);

  // Use a while loop to check if armstrong from 1 to userinp
  while (num < userinp) {
    if (checkIfArmstrong(num)) {
      printf("%ld ", num);
    }
    num++;
  }
  printf("\n");
  return 0;
}
