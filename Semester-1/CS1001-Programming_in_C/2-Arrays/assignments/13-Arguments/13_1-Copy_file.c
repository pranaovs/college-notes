// This code was forked from:
// https://github.com/pranaovs/college-notes/tree/main/Semester-1/CS1001-Programming_in_C/2-Arrays/assignments/12-File_handling/12_3-Copy_file.c

// C program to copy a file's content into another (write or append) using
// arguments

#include <stdio.h>

int main(int argc, char *argv[]) {

  if (argc == 1 || argc == 2) {
    printf("Usage: %s <source> <destination>\n", argv[0]);
    return 1;
  }

  FILE *source, *target;

  if ((source = fopen(argv[1], "r"))) {
    ;
  } else {
    printf("File %s does not exist\n", argv[1]);
    return 1;
  }

  target = fopen(argv[2], "w");

  int c;

  while ((c = fgetc(source)) != EOF) {
    fputc(c, target);
  }

  fclose(source);
  fclose(target);
}
