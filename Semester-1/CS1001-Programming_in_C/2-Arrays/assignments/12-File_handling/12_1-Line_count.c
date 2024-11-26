// C program to count the lines of a file

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

  int lines = 0;

  while (!feof(f)) {
    if (fgetc(f) == '\n') {
      lines++;
    }
  }

  printf("The file %s has %d lines\n", filename, lines);

  fclose(f);
  return 0;
}
