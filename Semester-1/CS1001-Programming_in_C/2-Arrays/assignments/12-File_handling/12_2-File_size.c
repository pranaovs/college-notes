// C program to print the size of a file

#include <stdio.h>

int main(void) {
  FILE *f;
  char filename[100];

  printf("This program counts the number of lines in a file.\nEnter the "
         "filename: ");
  scanf("%s", filename);

  if ((f = fopen(filename, "r"))) {
    ;
  } else {
    printf("File %s does not exist\n", filename);
    return 1;
  }

  fseek(f, 0, SEEK_END);

  printf("File size on bytes: %ld\n", ftell(f));

  fclose(f);
  return 0;
}
