// C program to copy a file's content into another (write or append)

#include <stdio.h>

int main(void) {
  FILE *source, *target;

  char filename[100];

  printf("This program counts the number of lines in a file.\nEnter the "
         "filename: ");
  scanf("%s", filename);

  if ((source = fopen(filename, "r"))) {
    ;
  } else {
    printf("File %s does not exist\n", filename);
    return 1;
  }

  printf("Enter the destination filename: ");
  scanf("%s", filename);

  target = fopen(filename, "w");

  int c;

  while ((c = fgetc(source)) != EOF) {
    fputc(c, target);
  }

  fclose(source);
  fclose(target);
}
