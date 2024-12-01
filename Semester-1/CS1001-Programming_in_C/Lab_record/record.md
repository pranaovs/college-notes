---
title: "CS1801 - Programming in C Lab Record"
author: "Pranaov (24110409)"
toc: true
numbersections: true
---

# Print Statements and Operators in C

## Employee Salary Calculation

### Algorithm

1. START
2. Initialize:
    * base = 15000
    * bonus_rate = 0.02
    * commission_rate = 0.02
    * cost = 45000
3. Input quantity (number of items sold).
4. Calculate bonus = quantity * bonus_rate.
5. Calculate commission = quantity *cost* commission_rate.
6. Compute salary = base + bonus + commission.
7. Output salary.
8. END

### Code

```c
/*
This code is licensed under the MIT License
Copyright 2024 Pranaov S
https://opensource.org/license/MIT
*/

#include <stdio.h>

int main() {

  // Base values

  int base = 15000;
  float bonus = 0.02;
  float commision = 0.02;
  int cost = 45000;

  int quantity;
  int salary;

  // Ask user for input on quantities sold
  printf("Enter quantities sold: ");
  scanf("%d", &quantity);
  printf("\n");

  // Calculate gross salary based on client's formula
  salary = base + (quantity * bonus) + (quantity * cost) * commision;

  // Send the gross salary to stdout
  printf("Gross salary is %d\n", salary);

  return 0;
}
```

### Output

```sh
$ gcc -o output 1-Employee_Salary.c && ./output
Enter quantities sold: 43

Gross salary is 53700
```

## Make in India Logo

### Algorithm

1. START
2. Initialize:
    * ANSI color codes for black and white backgrounds and reset codes
    * termChoice (char)
    * colorTerm (bool)
    * coloredString (char array)
3. Define the `colorize` function to add ANSI color codes to the input string:
    1. Initialize an empty string `coloredString`.
    2. Iterate through each character in the input string `inp`.
    3. For each character, use a switch case to determine the corresponding ANSI color code:
        * If the character is 'B', append the ANSI Black background code and a space, then reset the background.
        * If the character is 'W', append the ANSI white background code and a space, then reset the background.
        * If the character does not match any of the above, append the ANSI black background and a space, then reset the background.
    4. Return the `coloredString` with the injected ANSI codes.
4. Prompt the user to ensure their terminal supports at least 4-bit colors.
5. Input the user's response for terminal support.
6. Set `colorTerm` to true if the user confirms terminal support, otherwise set it to false.
7. Define the "Make in India" logo as a string.
8. If `colorTerm` is true, call the `colorize` function and print the colorized logo.
9. If `colorTerm` is false, print the logo without colorization.
10. END

### Code

```c

/*
This code is licensed under the MIT License
Copyright 2024 Pranaov S
https://opensource.org/license/MIT
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define ANSI_BLACK_FG "\x1b[30m"
#define ANSI_BLACK_BG "\x1b[40m"
#define ANSI_WHITE_FG "\x1b[37m"
#define ANSI_WHITE_BG "\x1b[47m"
#define ANSI_RESET_FG "\x1b[0m"
#define ANSI_RESET_BG "\x1b[0m"

char termChoice;
bool colorTerm;

char coloredString[32768];

// Function from:
// https://github.com/pranaovs/college-notes/tree/main/Semester-1/CS1001-Programming_in_C/assignments/2-Print_Statement_and_Operators_in_C/3-Country_Flag/3-Country_Flag.c
// Follows MIT License
char *colorize(char *inp) {

  // iterate through all the characters in the string
  for (int i = 0; i < strlen(inp); i++) {

    // use switch case to append final string embedded with ANSI color codes
    switch (inp[i]) {

    case 'B':
      strcat(coloredString, ANSI_BLACK_BG " " ANSI_RESET_BG);
      break;

    case 'W':
      strcat(coloredString, ANSI_WHITE_BG " " ANSI_RESET_BG);
      break;

    case ' ':
      strcat(coloredString, ANSI_BLACK_BG " " ANSI_RESET_BG);
      break;

    default:
      // Return the char if color code is not found
      // Convert the char to a string for concat
      char letter[2]; // https://stackoverflow.com/a/22429675
      letter[1] = '\0';
      letter[0] = inp[i];
      strcat(coloredString, letter);
    }
  }

  return coloredString; // return the string with injected ANSI codes
}

int main() {

  // Logic from:
  // https://github.com/pranaovs/college-notes/tree/main/Semester-1/CS1001-Programming_in_C/assignments/2-Print_Statement_and_Operators_in_C/3-Country_Flag/3-Country_Flag.c
  // Follows MIT License
  printf("Make sure your terminal (emulator) supports atleast 4-bit colors\n");
  printf("If you don't know what that means, just use one of these:\n");
  printf("    Linux: alacritty, foot, kitty\n");
  printf("    Windows: cmd, Windows Terminal, ConHost, ComEmu, mintty\n");
  printf("    MacOS: MacTerm, Warp, Terminal.app, iTerm2\n");

  printf("\nAre you using a terminal (emulator) that supports atleast 4-bit "
         "colors? [y/N]: ");

  scanf("%c", &termChoice);

  if (termChoice == ('Y' | 'y' | '1')) {
    colorTerm = true;
  } else {
    colorTerm = false;
  }

  // Define Make in India logo

  // clang-format off
  char logo[8192] =  ""
"                                                                                                      \n"
"                                                                              WWWWWWWWWWWW            \n"
"                                                                      WWWWWWWWWWWWWWWWWWWWWW          \n"
"                                                                    WWWWWWWWWWWWWWWWWWWWWWWWW  W      \n"
"                                   WWWWW                 WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW      \n"
"                            WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW      \n"
"            WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW     \n"
"      WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW   \n"
"   WWWWWWWWWWWW         WWWW                                                     WWWWWWWWWWWWWWWWWWWW \n"
"  WWWWW                WWWWW WW WW WWW W  W WWW  WWW W  W  WWW W  W WW  WWW WWWW WWWWWWWWWWWWWWWWWWWW \n"
" WWWW                 WWWWWW W W W W W WWW  WWW   W  WW W   W  WW W W W  W  W  W WWWWWWWWWWWWWWWWWWW  \n"
" WWW                WWWWWWWW W   W WWW W  W W     W  W WW   W  W WW W W  W  WWWW WWWWWWWWWWWWWWW      \n"
" WWW               WWWWWWWWW W   W W W W  W WWW  WWW W  W  WWW W  W WW  WWW W  W WWWWWWWWWWWWWWW      \n"
" WWWW              WWWWWWWWW                                                     WWWWWWWWWWWWWWW      \n"
"  WWWWWWWW        WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW WW       \n"
"    WWWWWWWWW    WWWWWWWWWWWWWWWWWWWWWWWWWWW     WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW  W            \n"
"      WWWWWWWWW WWWWWWWWWWWWWWW WWWWWWWWWWW              WWWWWWWWWWWWWWWWWWWWWWWWWWW                  \n"
"         WWWWWWWWWWWWWWWWWW      WWWWWWWWWW             WWWWWWWWW    WWWWWWWWWWWWW                    \n"
"               WWWWWWWWW        WWWWWWWWWW              WWWWWWWW         WWWWWWWWWW                   \n"
"               WWWWWWW          WWWWWWWWW              WWWWWWWW           WWWWWWWWW                   \n"
"               WWWWWW            WWWWWWWWWW            WWWWWW               WWWWWWWW                  \n"
"               WWWWWWWWW           WWWWWWWWWWWWWW     WWWWWWW                WWWWWWWWWWW              \n"
"                WWWWWWWWW             WWWWWWWWWWW      WWWWWWWWW                WWWWWWWWW             \n"
"                                                                                                      \n";
  // clang-format on

  // Only try colorizing the logo if user claims terminal supports 4-bit colors
  if (colorTerm) {
    printf("%s", colorize(logo));
  } else {
    printf("%s", logo);
  }

  return 0;
}
```

### Output

```sh
$ gcc -o output 2-Make_in_India_Pattern.c && ./output
Make sure your terminal (emulator) supports atleast 4-bit colors
If you don't know what that means, just use one of these:
    Linux: alacritty, foot, kitty
    Windows: cmd, Windows Terminal, ConHost, ComEmu, mintty
    MacOS: MacTerm, Warp, Terminal.app, iTerm2

Are you using a terminal (emulator) that supports atleast 4-bit colors? [y/N]:                                                                                                       
                                                                              WWWWWWWWWWWW            
                                                                      WWWWWWWWWWWWWWWWWWWWWW          
                                                                    WWWWWWWWWWWWWWWWWWWWWWWWW  W      
                                   WWWWW                 WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW      
                            WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW      
            WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW     
      WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW   
   WWWWWWWWWWWW         WWWW                                                     WWWWWWWWWWWWWWWWWWWW 
  WWWWW                WWWWW WW WW WWW W  W WWW  WWW W  W  WWW W  W WW  WWW WWWW WWWWWWWWWWWWWWWWWWWW 
 WWWW                 WWWWWW W W W W W WWW  WWW   W  WW W   W  WW W W W  W  W  W WWWWWWWWWWWWWWWWWWW  
 WWW                WWWWWWWW W   W WWW W  W W     W  W WW   W  W WW W W  W  WWWW WWWWWWWWWWWWWWW      
 WWW               WWWWWWWWW W   W W W W  W WWW  WWW W  W  WWW W  W WW  WWW W  W WWWWWWWWWWWWWWW      
 WWWW              WWWWWWWWW                                                     WWWWWWWWWWWWWWW      
  WWWWWWWW        WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW WW       
    WWWWWWWWW    WWWWWWWWWWWWWWWWWWWWWWWWWWW     WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW  W            
      WWWWWWWWW WWWWWWWWWWWWWWW WWWWWWWWWWW              WWWWWWWWWWWWWWWWWWWWWWWWWWW                  
         WWWWWWWWWWWWWWWWWW      WWWWWWWWWW             WWWWWWWWW    WWWWWWWWWWWWW                    
               WWWWWWWWW        WWWWWWWWWW              WWWWWWWW         WWWWWWWWWW                   
               WWWWWWW          WWWWWWWWW              WWWWWWWW           WWWWWWWWW                   
               WWWWWW            WWWWWWWWWW            WWWWWW               WWWWWWWW                  
               WWWWWWWWW           WWWWWWWWWWWWWW     WWWWWWW                WWWWWWWWWWW              
                WWWWWWWWW             WWWWWWWWWWW      WWWWWWWWW                WWWWWWWWW             
                                                                                                      

```

<!--TODO: attach image of output-->

## Country Flag

### Algorithm

1. START
2. Initialize:
    * ANSI color codes for red, green, yellow, blue, magenta, cyan, white backgrounds, and reset codes
    * termChoice (char)
    * colorTerm (bool)
    * coloredString (char array)
3. Define the `colorize` function to add ANSI color codes to the input string:
    1. Initialize an empty string `coloredString`.
    2. Iterate through each character in the input string `inp`.
    3. For each character, use a switch case to determine the corresponding ANSI color code:
        * If the character is 'R', append the ANSI red background code and a space, then reset the background.
        * If the character is 'G', append the ANSI green background code and a space, then reset the background.
        * If the character is 'Y', append the ANSI yellow background code and a space, then reset the background.
        * If the character is 'B', append the ANSI blue background code and a space, then reset the background.
        * If the character is 'M', append the ANSI magenta background code and a space, then reset the background.
        * If the character is 'C', append the ANSI cyan background code and a space, then reset the background.
        * If the character is 'W', append the ANSI white background code and a space, then reset the background.
        * If the character does not match any of the above, append the character itself to `coloredString`.
    4. Return the `coloredString` with the injected ANSI codes.
4. Prompt the user to ensure their terminal supports at least 4-bit colors.
5. Input the user's response for terminal support.
6. Set `colorTerm` to true if the user confirms terminal support, otherwise set it to false.
7. Define the Denmark flag as a string.
8. If `colorTerm` is true, call the `colorize` function and print the colorized flag.
9. If `colorTerm` is false, print the flag without colorization.
10. END

### Code

```c

/*
This code is licensed under the MIT License
Copyright 2024 Pranaov S
https://opensource.org/license/MIT
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Define ANSI codes for common colors. Can be extended.
// Thanks https://stackoverflow.com/a/3219471 and
// https://stackoverflow.com/a/33206814
#define ANSI_RED_FG "\x1b[31m"
#define ANSI_RED_BG "\x1b[41m"
#define ANSI_GREEN_FG "\x1b[32m"
#define ANSI_GREEN_BG "\x1b[42m"
#define ANSI_YELLOW_FG "\x1b[33m"
#define ANSI_YELLOW_BG "\x1b[43m"
#define ANSI_BLUE_FG "\x1b[34m"
#define ANSI_BLUE_BG "\x1b[44m"
#define ANSI_MAGENTA_FG "\x1b[35m"
#define ANSI_MAGENTA_BG "\x1b[45m"
#define ANSI_CYAN_FG "\x1b[36m"
#define ANSI_CYAN_BG "\x1b[46m"
#define ANSI_WHITE_FG "\x1b[37m"
#define ANSI_WHITE_BG "\x1b[47m"
#define ANSI_RESET_FG "\x1b[0m"
#define ANSI_RESET_BG "\x1b[0m"

char termChoice;
bool colorTerm;

char coloredString[1024];

char *colorize(char *inp) {

  // iterate through all the characters in the string
  for (int i = 0; i < strlen(inp); i++) {

    // use switch case to append final string embedded with ANSI color codes
    switch (inp[i]) {

    case 'R':
      strcat(coloredString, ANSI_RED_BG " " ANSI_RESET_BG);
      break;

    case 'G':
      strcat(coloredString, ANSI_GREEN_BG " " ANSI_RESET_BG);
      break;

    case 'Y':
      strcat(coloredString, ANSI_YELLOW_BG " " ANSI_RESET_BG);
      break;

    case 'B':
      strcat(coloredString, ANSI_BLUE_BG " " ANSI_RESET_BG);
      break;

    case 'M':
      strcat(coloredString, ANSI_MAGENTA_BG " " ANSI_RESET_BG);
      break;

    case 'C':
      strcat(coloredString, ANSI_CYAN_BG " " ANSI_RESET_BG);
      break;

    case 'W':
      strcat(coloredString, ANSI_WHITE_BG " " ANSI_RESET_BG);
      break;

    default:
      // Return the char if color code is not found
      // Convert the char to a string for concat
      char letter[2]; // https://stackoverflow.com/a/22429675
      letter[1] = '\0';
      letter[0] = inp[i];
      strcat(coloredString, letter);
    }
  }

  return coloredString; // return the string with injected ANSI codes
}

int main() {
  printf("Make sure your terminal (emulator) supports atleast 4-bit colors\n");
  printf("If you don't know what that means, just use one of these:\n");
  printf("    Linux: alacritty, foot, kitty\n");
  printf("    Windows: cmd, Windows Terminal, ConHost, ComEmu, mintty\n");
  printf("    MacOS: MacTerm, Warp, Terminal.app, iTerm2\n");

  printf("\nAre you using a terminal (emulator) that supports atleast 4-bit "
         "colors? [y/N]: ");

  scanf("%c", &termChoice);

  if (termChoice == ('Y' | 'y' | '1')) {
    colorTerm = true;
  } else {
    colorTerm = false;
  }

  // Define Denmark flag

  // clang-format off
  char flag[255] = "RRRRRRRRWWRRRRRRRRRRRRRR\n"
                   "RRRRRRRRWWRRRRRRRRRRRRRR\n"
                   "RRRRRRRRWWRRRRRRRRRRRRRR\n"
                   "RRRRRRRRWWRRRRRRRRRRRRRR\n"
                   "WWWWWWWWWWWWWWWWWWWWWWWW\n"
                   "RRRRRRRRWWRRRRRRRRRRRRRR\n"
                   "RRRRRRRRWWRRRRRRRRRRRRRR\n"
                   "RRRRRRRRWWRRRRRRRRRRRRRR\n"
                   "RRRRRRRRWWRRRRRRRRRRRRRR\n";

  // clang-format on

  // Only try colorizing the flag if user claims terminal supports 4-bit colors
  if (colorTerm) {
    printf("%s", colorize(flag));
  } else {
    printf("%s", flag);
  }

  return 0;
}

```

### Output

```sh
$ gcc -o output 3-Country_Flag.c && ./output
Make sure your terminal (emulator) supports atleast 4-bit colors
If you don't know what that means, just use one of these:
    Linux: alacritty, foot, kitty
    Windows: cmd, Windows Terminal, ConHost, ComEmu, mintty
    MacOS: MacTerm, Warp, Terminal.app, iTerm2

Are you using a terminal (emulator) that supports atleast 4-bit colors? [y/N]: n
RRRRRRRRWWRRRRRRRRRRRRRR
RRRRRRRRWWRRRRRRRRRRRRRR
RRRRRRRRWWRRRRRRRRRRRRRR
RRRRRRRRWWRRRRRRRRRRRRRR
WWWWWWWWWWWWWWWWWWWWWWWW
RRRRRRRRWWRRRRRRRRRRRRRR
RRRRRRRRWWRRRRRRRRRRRRRR
RRRRRRRRWWRRRRRRRRRRRRRR
RRRRRRRRWWRRRRRRRRRRRRRR
```

# Selection - Decision Making and Branching (Part 1)

## Student Grade Calculation

### Algorithm

1. START
2. Initialize:
    * mark (integer)
3. Print "SNU Chennai grade calculator"
4. Print "Enter the student mark and the grade will be calculated according to SNU Chennai B.Tech regulations (2021)"
5. Print "Enter the student's mark (out of 100): "
6. Input mark
7. Print "Grade for [mark] marks is: "
8. Check the value of mark and determine the grade:
    * If mark is between 91 and 100, print "O"
    * If mark is between 81 and 90, print "A+"
    * If mark is between 71 and 80, print "A"
    * If mark is between 61 and 70, print "B+"
    * If mark is between 51 and 60, print "B"
    * If mark is between 41 and 50, print "P"
    * If mark is between 0 and 40, print "RA"
9. Print a newline
10. END

### Code

```c
#include <stdio.h>

int mark;

int main() {

  printf("SNU Chennai grade calculator\n");
  printf("Enter the student mark and the grade will be calculated according to "
         "SNU Chennai B.Tech regulations (2021)\n\n");
  // https://www.snuchennai.edu.in/wp-content/uploads/2024/01/Regulations_B.Tech-2.pdf

  printf("Enter the student's mark (out of 100): ");
  scanf("%d", &mark);
  printf("\n");

  printf("Grade for %d marks is: ", mark);

  if (mark <= 100 && mark >= 91) {
    printf("O");
  }
  if (mark <= 90 && mark >= 81) {
    printf("A+");
  }
  if (mark <= 80 && mark >= 71) {
    printf("A");
  }
  if (mark <= 70 && mark >= 61) {
    printf("B+");
  }
  if (mark <= 60 && mark >= 51) {
    printf("B");
  }
  if (mark <= 50 && mark >= 41) {
    printf("P");
  }
  if (mark < 40 && mark >= 0) {
    printf("RA");
  }

  printf("\n");

  return 0;
}
```

```sh
$ gcc -o output 1-Student_Grade.c && ./output
SNU Chennai grade calculator
Enter the student mark and the grade will be calculated according to SNU Chennai B.Tech regulations (2021)

Enter the student's mark (out of 100): 89

Grade for 89 marks is: A+
```

## Divisibility Check

### Using `if` statement only

#### Algorithm

1. START
2. Initialize:
    * num1 = 2
    * num2 = 3
    * inp (integer)
    * result (integer)
3. Define function `checkDiv(int inp)`:
    * If inp is 0, return 0
    * If inp is divisible by both num1 and num2, return (num1 * num2)
    * If inp is divisible by num1, return num1
    * If inp is divisible by num2, return num2
    * Otherwise, return 1
4. Print "This program checks if the given number is divisible by 2 or 3 or both, using if statements"
5. Print "Enter the number to check for divisibility: "
6. Input inp
7. Call `checkDiv(inp)` and store the result in result
8. Check the value of result and print the appropriate message:
    * If result is 0, print "0 is not an option"
    * If result is 1, print "[inp] is not divisible by neither 2, 3 nor both"
    * If result is 6 (num1 * num2), print "[inp] is divisible by both 2 and 3 (6)"
    * If result is 2 or 3, print "[inp] is divisible by [result]"
9. Print a newline
10. END

#### Code

```c
#include <stdio.h>

// Define the numbers to check for divisibility
int num1 = 2;
int num2 = 3;
int inp, result;

// Use a function to check divisibility and return the divisor. Also returns the
// multiple if both numbers are divisible. Returns 0 if input is zero.
int checkDiv(int inp) {
  if (inp == 0) {
    return 0;
  }
  if (inp % (num1 * num2) == 0) {
    return (num1 * num2);
  }
  if (inp % (num1) == 0) {
    return (num1);
  }
  if (inp % (num2) == 0) {
    return (num2);
  }
  return 1;
}

int main() {

  printf("This program checks if the given number is divisible by %d or %d or "
         "both\n\n, using if statements",
         num1, num2);
  printf("Enter the number to check for divisibility: ");

  scanf("%d", &inp);
  printf("\n");

  result = checkDiv(inp);

  if (result == 0) {
    printf("0 is not an option");
  }
  if (result == 1) {
    printf("%d is not divisible by neither %d, %d nor both", inp, num1, num2);
  }
  if (result == (num1 * num2)) {
    printf("%d is divisible by both %d and %d (%d)", inp, num1, num2, (result));
  }
  if (result == num1 || result == num2) {
    printf("%d is divisible by %d", inp, result);
  }

  printf("\n");

  return 0;
}
```

#### Output

```sh
$ gcc -o output 2_1-Divisibility_Check.c && ./output
This program checks if the given number is divisible by 2 or 3 or both

, using if statementsEnter the number to check for divisibility: 46

46 is divisible by 2
```

### Using `if-else` statements

#### Algorithm

1. START
2. Initialize:
    * num1 = 2
    * num2 = 3
    * inp (integer)
    * result (integer)
3. Define function `checkDiv(int inp)`:
    * If inp is 0, return 0
    * Else if inp is divisible by both num1 and num2, return (num1 * num2)
    * Else if inp is divisible by num1, return num1
    * Else if inp is divisible by num2, return num2
    * Else, return 1
4. Print "This program checks if the given number is divisible by 2 or 3 or both, using if-else statements"
5. Print "Enter the number to check for divisibility: "
6. Input inp
7. Call `checkDiv(inp)` and store the result in result
8. Check the value of result and print the appropriate message:
    * If result is 0, print "0 is not an option"
    * Else if result is 1, print "[inp] is not divisible by neither 2, 3 nor both"
    * Else if result is 6 (num1 * num2), print "[inp] is divisible by both 2 and 3 (6)"
    * Else, print "[inp] is divisible by [result]"
9. Print a newline
10. END

#### Code

```c
#include <stdio.h>

// Define the numbers to check for divisibility
int num1 = 2;
int num2 = 3;
int inp, result;

// Use a function to check divisibility and return the divisor. Also returns the
// multiple if both numbers are divisible. Returns 0 if input is zero
int checkDiv(int inp) {
  if (inp == 0) {
    return 0;
  }

  else if (inp % (num1 * num2) == 0) {
    return (num1 * num2);
  }

  else if (inp % (num1) == 0) {
    return (num1);
  }

  else if (inp % (num2) == 0) {
    return (num2);
  }

  else {
    return 1;
  }
}

int main() {

  printf("This program checks if the given number is divisible by %d or %d or "
         "both\n\n, using if-else statements",
         num1, num2);
  printf("Enter the number to check for divisibility: ");

  scanf("%d", &inp);
  printf("\n");

  result = checkDiv(inp);

  if (result == 0) {
    printf("0 is not an option");
  }

  else if (result == 1) {
    printf("%d is not divisible by neither %d, %d nor both", inp, num1, num2);
  }

  else if (result == (num1 * num2)) {
    printf("%d is divisible by both %d and %d (%d)", inp, num1, num2, (result));
  }

  else {
    printf("%d is divisible by %d", inp, result);
  }

  printf("\n");

  return 0;
}
```

#### Output

```sh
$ gcc -o output 2_2-Divisibility_Check.c && ./output
This program checks if the given number is divisible by 2 or 3 or both

, using if-else statementsEnter the number to check for divisibility: 48

48 is divisible by both 2 and 3 (6)
```

### Using nested `if` statements

#### Algorithm

1. START
2. Initialize:
    * num1 = 2
    * num2 = 3
    * inp (integer)
    * result (integer)
3. Define function `checkDiv(int inp)`:
    * If inp is 0, return 0
    * If inp is divisible by both num1 and num2, return (num1 * num2)
    * If inp is divisible by num1:
        * If inp is also divisible by both num1 and num2, return (num1 * num2)
        * Else, return num1
    * If inp is divisible by num2:
        * If inp is also divisible by both num1 and num2, return (num1 * num2)
        * Else, return num2
    * Otherwise, return 1
4. Print "This program checks if the given number is divisible by 2 or 3 or both, using nested if and else statements"
5. Print "Enter the number to check for divisibility: "
6. Input inp
7. Call `checkDiv(inp)` and store the result in result
8. Check the value of result and print the appropriate message:
    * If result is 0, print "0 is not an option"
    * If result is 1, print "[inp] is not divisible by neither 2, 3 nor both"
    * If result is 6 (num1 * num2), print "[inp] is divisible by both 2 and 3 (6)"
    * If result is 2 or 3, print "[inp] is divisible by [result]"
9. Print a newline
10. END

#### Code

```c
#include <stdio.h>

// Define the numbers to check for divisibility
int num1 = 2;
int num2 = 3;
int inp, result;

// Use a function to check divisibility and return the divisor. Also returns the
// multiple if both numbers are divisible. Returns zero if input is zero.
int checkDiv(int inp) {
  // Do not process if input is zero
  if (inp == 0) {
    return 0;
  }
  if (inp % (num1 * num2) == 0) {
    return (num1 * num2);
  }
  // use nested if to check if given number is divisible by both numbers if it
  // is divisible by one number
  if (inp % (num1) == 0) {
    if (inp % (num1 * num2) == 0) {
      return (num1 * num2);
    } else {

      return (num1);
    }
  }
  if (inp % (num2) == 0) {
    if (inp % (num1 * num2) == 0) {
      return (num1 * num2);
    } else {

      return (num2);
    }
  }
  return 1;
}

int main() {

  printf("This program checks if the given number is divisible by %d or %d or "
         "both\n\n, using nested if and else statements",
         num1, num2);
  printf("Enter the number to check for divisibility: ");

  scanf("%d", &inp);
  printf("\n");

  result = checkDiv(inp);

  if (result == 0) {
    printf("0 is not an option");
  }
  if (result == 1) {
    printf("%d is not divisible by neither %d, %d nor both", inp, num1, num2);
  }
  if (result == (num1 * num2)) {
    printf("%d is divisible by both %d and %d (%d)", inp, num1, num2, (result));
  }
  if (result == num1 || result == num2) {
    printf("%d is divisible by %d", inp, result);
  }

  printf("\n");

  return 0;
}
```

#### Output

```sh
$ gcc -o output 2_3-Divisibility_Check.c && ./output
This program checks if the given number is divisible by 2 or 3 or both

, using nested if and else statementsEnter the number to check for divisibility: 43

43 is not divisible by neither 2, 3 nor both
```

## Finding the largest number

### Using `if` only statements

#### Algorithm

1. START
2. Initialize:
    * num1, num2, num3, num4 (integers)
    * tmpResult1, tmpResult2, tmpResult3, result (integers)
    * tmpResult12, tmpResult23 (integers)
3. Print "This program returns the greatest among 4 numbers using if statements"
4. Print "Enter 4 numbers separated by spaces: "
5. Input num1, num2, num3, num4
6. Compare num1 and num2 to find the greater number:
    * If num1 >= num2, set tmpResult1 = num1
    * Else, set tmpResult1 = num2
7. Compare num2 and num3 to find the greater number:
    * If num2 >= num3, set tmpResult2 = num2
    * Else, set tmpResult2 = num3
8. Compare num3 and num4 to find the greater number:
    * If num3 >= num4, set tmpResult3 = num3
    * Else, set tmpResult3 = num4
9. Compare tmpResult1 and tmpResult2 to find the greater number:
    * If tmpResult1 >= tmpResult2, set tmpResult12 = tmpResult1
    * Else, set tmpResult12 = tmpResult2
10. Compare tmpResult2 and tmpResult3 to find the greater number:
    * If tmpResult2 >= tmpResult3, set tmpResult23 = tmpResult2
    * Else, set tmpResult23 = tmpResult3
11. Compare tmpResult12 and tmpResult23 to find the greatest number:
    * If tmpResult12 >= tmpResult23, set result = tmpResult12
    * Else, set result = tmpResult23
12. Print "The greatest number among [num1], [num2], [num3], [num4], is: [result]"
13. END

#### Code

```c
#include <stdio.h>

int num1, num2, num3, num4;
int tmpResult1, tmpResult2, tmpResult3, result;
int tmpResult12, tmpResult23;

int main() {
  printf("This program returns the greatest among 4 numbers using if "
         "statements\n\n");

  printf("Enter 4 numbers separated by spaces: ");
  scanf("%d %d %d %d", &num1, &num2, &num3,
        &num4); // Read 4 numbers separated by space
  printf("\n");

  // Use a really inefficient logic to reduce 4 numbers to top 3 greatest
  // numbers (eliminate the lowest number)

  // Handle edge cases where numbers are equal
  if (num1 >= num2) {
    tmpResult1 = num1;
  }
  if (num1 < num2) {
    tmpResult1 = num2;
  }

  if (num2 >= num3) {
    tmpResult2 = num2;
  }
  if (num2 < num3) {
    tmpResult2 = num3;
  }

  if (num3 >= num4) {
    tmpResult3 = num3;
  }
  if (num3 < num4) {
    tmpResult3 = num4;
  }

  // Use an even inefficient logic to reduce the top 3 to top 2
  // Compare the greatest numbers among the three
  if (tmpResult1 >= tmpResult2) {
    tmpResult12 = tmpResult1;
  }
  if (tmpResult1 < tmpResult2) {
    tmpResult12 = tmpResult2;
  }

  if (tmpResult2 >= tmpResult3) {
    tmpResult23 = tmpResult2;
  }

  if (tmpResult2 < tmpResult3) {
    tmpResult23 = tmpResult3;
  }

  // Finally compare the top 2 greatest numbers to find the greatest number

  if (tmpResult12 >= tmpResult23) {
    result = tmpResult12;
  }
  if (tmpResult12 < tmpResult23) {
    result = tmpResult23;
  }

  printf("The greatest number among %d, %d, %d, %d, is: %d\n", num1, num2, num3,
         num4, result);
}
```

#### Output

```sh
$ gcc -o output 3_1-Greatest_Number.c && ./output
This program returns the greatest among 4 numbers using if statements

Enter 4 numbers separated by spaces: 2 4 1 3

The greatest number among 2, 4, 1, 3, is: 4
```

### Using `if-else` statements

#### Algorithm

1. START
2. Initialize:
    * num1, num2, num3, num4 (integers)
    * tmpResult1, tmpResult2, tmpResult3, result (integers)
    * tmpResult12, tmpResult23 (integers)
3. Print "This program returns the greatest among 4 numbers using if-else statements"
4. Print "Enter 4 numbers separated by spaces: "
5. Input num1, num2, num3, num4
6. Compare num1 and num2 to find the greater number:
    * If num1 >= num2, set tmpResult1 = num1
    * Else, set tmpResult1 = num2
7. Compare num2 and num3 to find the greater number:
    * If num2 >= num3, set tmpResult2 = num2
    * Else, set tmpResult2 = num3
8. Compare num3 and num4 to find the greater number:
    * If num3 >= num4, set tmpResult3 = num3
    * Else, set tmpResult3 = num4
9. Compare tmpResult1 and tmpResult2 to find the greater number:
    * If tmpResult1 >= tmpResult2, set tmpResult12 = tmpResult1
    * Else, set tmpResult12 = tmpResult2
10. Compare tmpResult2 and tmpResult3 to find the greater number:
    * If tmpResult2 >= tmpResult3, set tmpResult23 = tmpResult2
    * Else, set tmpResult23 = tmpResult3
11. Compare tmpResult12 and tmpResult23 to find the greatest number:
    * If tmpResult12 >= tmpResult23, set result = tmpResult12
    * Else, set result = tmpResult23
12. Print "The greatest number among [num1], [num2], [num3], [num4], is: [result]"
13. END

#### Code

```c
#include <stdio.h>

int num1, num2, num3, num4;
int tmpResult1, tmpResult2, tmpResult3, result;
int tmpResult12, tmpResult23;

int main() {
  printf("This program returns the greatest among 4 numbers using if-else "
         "statements\n\n");

  printf("Enter 4 numbers separated by spaces: ");
  scanf("%d %d %d %d", &num1, &num2, &num3,
        &num4); // Read 4 numbers separated by space
  printf("\n");

  // Use a little less inefficient logic to reduce 4 numbers to top 3 greatest
  // numbers (eliminate the lowest number)

  // Handle edge cases where numbers are equal
  if (num1 >= num2) {
    tmpResult1 = num1;
  } else {
    tmpResult1 = num2;
  }

  if (num2 >= num3) {
    tmpResult2 = num2;
  } else {
    tmpResult2 = num3;
  }

  if (num3 >= num4) {
    tmpResult3 = num3;
  } else {
    tmpResult3 = num4;
  }

  // Use an even little less inefficient logic to reduce the top 3 to top 2
  // Compare the greatest numbers among the three
  if (tmpResult1 >= tmpResult2) {
    tmpResult12 = tmpResult1;
  } else {
    tmpResult12 = tmpResult2;
  }

  if (tmpResult2 >= tmpResult3) {
    tmpResult23 = tmpResult2;
  }

  else {
    tmpResult23 = tmpResult3;
  }

  // Finally compare the top 2 greatest numbers to find the greatest number

  if (tmpResult12 >= tmpResult23) {
    result = tmpResult12;
  } else {
    result = tmpResult23;
  }

  printf("The greatest number among %d, %d, %d, %d, is: %d\n", num1, num2, num3,
         num4, result);
}
```

#### Output

```sh
$ gcc -o output 3_2-Greatest_Number.c && ./output
This program returns the greatest among 4 numbers using if-else statements

Enter 4 numbers separated by spaces: 4 9 1 0

The greatest number among 4, 9, 1, 0, is: 9

```

### Using nested `if` statements

#### Algorithm

1. START
2. Initialize:
    * num1, num2, num3, num4 (integers)
    * result (integer)
3. Print "This program returns the greatest among 4 numbers using nested if statements"
4. Print "Enter 4 numbers separated by spaces: "
5. Input num1, num2, num3, num4
6. Use nested if-else statements to find the greatest number:
    * If num1 >= num2:
        * If num1 >= num3:
            * If num1 >= num4, set result = num1
            * Else, set result = num4
        * Else if num3 >= num4, set result = num3
        * Else, set result = num4
    * Else if num2 >= num3:
        * If num2 >= num4, set result = num2
        * Else, set result = num4
    * Else if num3 >= num4, set result = num3
    * Else, set result = num4
7. Print "The greatest number among [num1], [num2], [num3], [num4], is: [result]"
8. END

#### Code

```c
#include <stdio.h>

int num1, num2, num3, num4;
int tmpResult1, tmpResult2, tmpResult3, result;
int tmpResult12, tmpResult23;

int main() {
  printf("This program returns the greatest among 4 numbers using nested if "
         "statements\n\n");

  printf("Enter 4 numbers separated by spaces: ");
  scanf("%d %d %d %d", &num1, &num2, &num3,
        &num4); // Read 4 numbers separated by space
  printf("\n");

  // Use a little more lesser inefficient (but ridiculous) logic to find the
  // greatest number using nested if-else

  // Handle edge cases where numbers are equal

  if (num1 >= num2) {
    if (num1 >= num3) {
      if (num1 >= num4) {
        result = num1;
      } else {
        result = num4;
      }
    } else if (num3 >= num4) {
      result = num3;
    } else {
      result = num4;
    }
  } else if (num2 >= num3) {
    if (num2 >= num4) {
      result = num2;
    } else {
      result = num4;
    }
  } else if (num3 >= num4) {
    result = num3;
  } else {
    result = num4;
  }

  printf("The greatest number among %d, %d, %d, %d, is: %d\n", num1, num2, num3,
         num4, result);
}
```

#### Output

```sh
$ gcc -o output 3_3-Greatest_Number.c && ./output
This program returns the greatest among 4 numbers using nested if statements

Enter 4 numbers separated by spaces: 2 4 1 39

The greatest number among 2, 4, 1, 39, is: 39
```

# Selection - Decision Making and Branching (Part 2)

## Calculator implementation

### Using `if` statements only

#### Algorithm

1. START
2. Initialize:
    * operation (character)
    * num1, num2 (integers)
3. Print "Enter the operation to perform (+,-,*,/,%,&,^,|): "
4. Input operation
5. Print "Enter two numbers separated by a space: "
6. Input num1, num2
7. Check the value of operation and perform the corresponding calculation:
    * If operation is '+', print "The sum of [num1] and [num2] is [num1 + num2]"
    * If operation is '-', print "The difference between [num1] and [num2] is [num1 - num2]"
    * If operation is '*', print "The product of [num1] and [num2] is [num1* num2]"
    * If operation is '/', print "The division of [num1] and [num2] is [num1 / num2]"
    * If operation is '%', print "[num1] % [num2] = [num1 % num2]"
    * If operation is '&', print "[num1] & [num2] = [num1 & num2]"
    * If operation is '^', print "[num1] ^ [num2] = [num1 ^ num2]"
    * If operation is '|', print "[num1] | [num2] = [num1 | num2]"
8. END

#### Code

```c
// This program implements a simple calculator using just if statements

#include <stdio.h>
int main() {
  char operation;
  int num1, num2;

  printf("\nEnter the operation to perform (+,-,*,/,%%,&,^,|): ");
  scanf("%c", &operation);

  printf("Enter two numbers separated by a space: ");
  scanf("%d %d", &num1, &num2);

  printf("\n");

  if (operation == '+') {
    printf("The sum of %d and %d is %d\n", num1, num2, num1 + num2);
  }
  if (operation == '-') {
    printf("The differrence between %d and %d is %d\n", num1, num2,
           num1 - num2);
  }
  if (operation == '*') {
    printf("The product of %d and %d is %d\n", num1, num2, num1 * num2);
  }
  if (operation == '/') {
    printf("The division of %d and %d is %d\n", num1, num2, num1 / num2);
  }
  if (operation == '%') {
    printf("%d %% %d = %d\n", num1, num2, num1 % num2);
  }
  if (operation == '&') {
    printf("%d & %d = %d\n", num1, num2, num1 & num2);
  }
  if (operation == '^') {
    printf("%d ^ %d = %d\n", num1, num2, num1 ^ num2);
  }
  if (operation == '|') {
    printf("%d | %d = %d\n", num1, num2, num1 | num2);
  }

  return 0;
}
```

#### Output

```sh
$ gcc -o output 1_1-Calculator.c && ./output

Enter the operation to perform (+,-,*,/,%,&,^,|): ^
Enter two numbers separated by a space: 3 8

3 ^ 8 = 11

```

### Using `if-else` statements

#### Algorithm

1. START
2. Initialize:
    * operation (character)
    * num1, num2 (integers)
3. Print "Enter the operation to perform (+,-,*,/,%,&,^,|): "
4. Input operation
5. Print "Enter two numbers separated by a space: "
6. Input num1, num2
7. Check the value of operation and perform the corresponding calculation using if-else statements:
    * If operation is '+', print "The sum of [num1] and [num2] is [num1 + num2]"
    * Else if operation is '-', print "The difference between [num1] and [num2] is [num1 - num2]"
    * Else if operation is '*', print "The product of [num1] and [num2] is [num1* num2]"
    * Else if operation is '/', print "The division of [num1] and [num2] is [num1 / num2]"
    * Else if operation is '%', print "[num1] % [num2] = [num1 % num2]"
    * Else if operation is '&', print "[num1] & [num2] = [num1 & num2]"
    * Else if operation is '^', print "[num1] ^ [num2] = [num1 ^ num2]"
    * Else if operation is '|', print "[num1] | [num2] = [num1 | num2]"
8. END

#### Code

```c
// This program implements a simple calculator using if-else statements

#include <stdio.h>
int main() {
  char operation;
  int num1, num2;

  printf("\nEnter the operation to perform (+,-,*,/,%%,&,^,|): ");
  scanf("%c", &operation);

  printf("Enter two numbers separated by a space: ");
  scanf("%d %d", &num1, &num2);

  printf("\n");

  if (operation == '+') {
    printf("The sum of %d and %d is %d\n", num1, num2, num1 + num2);
  } else if (operation == '-') {
    printf("The delse ifferrence between %d and %d is %d\n", num1, num2,
           num1 - num2);
  } else if (operation == '*') {
    printf("The product of %d and %d is %d\n", num1, num2, num1 * num2);
  } else if (operation == '/') {
    printf("The division of %d and %d is %d\n", num1, num2, num1 / num2);
  } else if (operation == '%') {
    printf("%d %% %d = %d\n", num1, num2, num1 % num2);
  } else if (operation == '&') {
    printf("%d & %d = %d\n", num1, num2, num1 & num2);
  } else if (operation == '^') {
    printf("%d ^ %d = %d\n", num1, num2, num1 ^ num2);
  } else if (operation == '|') {
    printf("%d | %d = %d\n", num1, num2, num1 | num2);
  }

  return 0;
}
```

#### Output

```sh
$ gcc -o output 1_2-Calculator.c && ./output

Enter the operation to perform (+,-,*,/,%,&,^,|): *
Enter two numbers separated by a space: 4 26

The product of 4 and 26 is 104
```

## Railway seating

### Using `if` statements only

#### Algorithm

1. START
2. Initialize:
    * seat (integer)
3. Print "Enter the seat number: "
4. Input seat
5. Check if seat is valid:
    * If seat > 80 or seat <= 0, print "Seat number [seat] is invalid. Train has only 80 seats" and return 22 (Invalid argument error code)
6. Determine the berth type based on seat number:
    * If seat % 8 == 0, print "The seat assigned to [seat] is: SIDE UPPER BERTH"
    * If seat % 8 == 7, print "The seat assigned to [seat] is: SIDE LOWER BERTH"
    * If seat % 8 == 6, print "The seat assigned to [seat] is: UPPER BERTH"
    * If seat % 8 == 5, print "The seat assigned to [seat] is: MIDDLE BERTH"
    * If seat % 8 == 4, print "The seat assigned to [seat] is: LOWER BERTH"
    * If seat % 8 == 3, print "The seat assigned to [seat] is: UPPER BERTH"
    * If seat % 8 == 2, print "The seat assigned to [seat] is: MIDDLE BERTH"
    * If seat % 8 == 1, print "The seat assigned to [seat] is: LOWER BERTH"
7. END

#### Code

```c
// Program to find out berth in train when seat number is provided

#include <stdio.h>

int main() {
  int seat;
  printf("Enter the seat number: ");
  scanf("%d", &seat);

  if (seat > 80 || seat <= 0) {
    printf("Seat number %d is invalid. Train has only 80 seats\n", seat);
    return 22; // Exit with Invalid argument error code
  }

  if (seat % 8 == 0) {
    printf("The seat assigned to %d is: SIDE UPPER BERTH\n", seat);
  }
  if (seat % 8 == 7) {
    printf("The seat assigned to %d is: SIDE LOWER BERTH\n", seat);
  }
  if (seat % 8 == 6) {
    printf("The seat assigned to %d is: UPPER BERTH\n", seat);
  }
  if (seat % 8 == 5) {
    printf("The seat assigned to %d is: MIDDLE BERTH\n", seat);
  }
  if (seat % 8 == 4) {
    printf("The seat assigned to %d is: LOWER BERTH\n", seat);
  }
  if (seat % 8 == 3) {
    printf("The seat assigned to %d is: UPPER BERTH\n", seat);
  }
  if (seat % 8 == 2) {
    printf("The seat assigned to %d is: MIDDLE BERTH\n", seat);
  }
  if (seat % 8 == 1) {
    printf("The seat assigned to %d is: LOWER BERTH\n", seat);
  }
  return 0;
}
```

#### Output

```sh
$ gcc -o output 2_1-Railway-seating.c && ./output
Enter the seat number: 35
The seat assigned to 35 is: UPPER BERTH
```

### Using `if-else` statements

#### Algorithm

1. START
2. Initialize:
    * seat (integer)
3. Print "Enter the seat number: "
4. Input seat
5. Check if seat is valid:
    * If seat > 80 or seat <= 0, print "Seat number [seat] is invalid. Train has only 80 seats" and return 22 (Invalid argument error code)
6. Determine the berth type based on seat number using if-else statements:
    * Else if seat % 8 == 0, print "The seat assigned to [seat] is: SIDE UPPER BERTH"
    * Else if seat % 8 == 7, print "The seat assigned to [seat] is: SIDE LOWER BERTH"
    * Else if seat % 8 == 6, print "The seat assigned to [seat] is: UPPER BERTH"
    * Else if seat % 8 == 5, print "The seat assigned to [seat] is: MIDDLE BERTH"
    * Else if seat % 8 == 4, print "The seat assigned to [seat] is: LOWER BERTH"
    * Else if seat % 8 == 3, print "The seat assigned to [seat] is: UPPER BERTH"
    * Else if seat % 8 == 2, print "The seat assigned to [seat] is: MIDDLE BERTH"
    * Else if seat % 8 == 1, print "The seat assigned to [seat] is: LOWER BERTH"
7. END

#### Code

```c
// Program to find out berth in train when seat number is provided

#include <stdio.h>

int main() {
  int seat;
  printf("Enter the seat number: ");
  scanf("%d", &seat);

  if (seat > 80 || seat <= 0) {
    printf("Seat number %d is invalid. Train has only 80 seats\n", seat);
    return 22; // Exit with Invalid argument error code
  }

  else if (seat % 8 == 0) {
    printf("The seat assigned to %d is: SIDE UPPER BERTH\n", seat);
  } else if (seat % 8 == 7) {
    printf("The seat assigned to %d is: SIDE LOWER BERTH\n", seat);
  } else if (seat % 8 == 6) {
    printf("The seat assigned to %d is: UPPER BERTH\n", seat);
  } else if (seat % 8 == 5) {
    printf("The seat assigned to %d is: MIDDLE BERTH\n", seat);
  } else if (seat % 8 == 4) {
    printf("The seat assigned to %d is: LOWER BERTH\n", seat);
  } else if (seat % 8 == 3) {
    printf("The seat assigned to %d is: UPPER BERTH\n", seat);
  } else if (seat % 8 == 2) {
    printf("The seat assigned to %d is: MIDDLE BERTH\n", seat);
  } else if (seat % 8 == 1) {
    printf("The seat assigned to %d is: LOWER BERTH\n", seat);
  }
  return 0;
}
```

#### Output

```sh
$ gcc -o output 2_2-Railway-seating.c && ./output
Enter the seat number: 80
The seat assigned to 80 is: SIDE UPPER BERTH

$ gcc -o output 2_2-Railway-seating.c && ./output
Enter the seat number: 81
Seat number 81 is invalid. Train has only 80 seats
```

## Internet Plan Speed Calculator

### Using `if` statements only

#### Algorithm

1. START
2. Initialize:
    * input (float)
    * unit (character)
    * KBps, Kbps, GBps, Gbps, MBps, Mbps, Bps, bps (floats)
3. Print "Enter your data plan in the format number x multiplierBps Example: If your plan is 50MBps, enter 50M. Note: Omit Bps in your input)"
4. Input input and unit
5. Check if unit is valid:
    * If unit is not 'K', 'k', 'G', 'g', 'M', or 'm', print "Invalid input" and return 22 (Invalid argument error code)
6. Convert the input based on the unit:
    * If unit is 'K' or 'k':
        * Calculate GBps = input / 1048576
        * Calculate Gbps = GBps * 8
        * Calculate MBps = input / 1024
        * Calculate Mbps = MBps * 8
        * Calculate KBps = input
        * Calculate Kbps = KBps * 8
        * Calculate Bps = input * 1024
        * Calculate bps = Bps * 8
    * If unit is 'M' or 'm':
        * Calculate GBps = input / 1024
        * Calculate Gbps = GBps * 8
        * Calculate MBps = input
        * Calculate Mbps = MBps * 8
        * Calculate KBps = input * 1024
        * Calculate Kbps = KBps * 8
        * Calculate Bps = input *1024* 1024
        * Calculate bps = input *1024* 1024 * 8
    * If unit is 'G' or 'g':
        * Calculate GBps = input
        * Calculate Gbps = GBps * 8
        * Calculate MBps = input * 1024
        * Calculate Mbps = MBps * 8
        * Calculate KBps = input * 1048576
        * Calculate Kbps = KBps * 8
        * Calculate Bps = input *1024* 1024 * 1024
        * Calculate bps = Bps * 8
7. Print the converted values:
    * Print "Gigabytes per second (GBps): [GBps]"
    * Print "Gigabits per second (Gbps): [Gbps]"
    * Print "Megabytes per second (MBps): [MBps]"
    * Print "Megabits per second (Mbps): [Mbps]"
    * Print "Kilobytes per second (KBps): [KBps]"
    * Print "Kilobits per second (Kbps): [Kbps]"
    * Print "Bytes per second (Bps): [Bps]"
    * Print "Bits per second (bps): [bps]"
8. END

#### Code

```c

// Simple program to convert data from one unit to another
// Promarily to be used with ISP data calculation

#include <stdio.h>

int main() {
  float input;
  char unit;
  float KBps, Kbps, GBps, Gbps, MBps, Mbps, Bps, bps;

  printf("Enter your data plan in the format number multiplier Bps\nExample: "
         "If your plan is 50MBps, enter 50M. Note: Omit Bps in your input)\n");

  scanf("%f%c", &input, &unit);

  if ((unit != 'K' && unit != 'k' && unit != 'G' && unit != 'g' &&
       unit != 'M' && unit != 'm')) {
    printf("Invalid input\n");
    return 22; // Exit code for invalid argument
  }

  if (unit == 'K' || unit == 'k') {
    GBps = input / 1048576;
    Gbps = GBps * 8;
    MBps = input / 1024;
    Mbps = MBps * 8;
    KBps = input * 1;
    Kbps = KBps * 8;
    Bps = input * 1024;
    bps = Bps * 8;
  }
  if (unit == 'M' || unit == 'm') {
    GBps = input / 1024;
    Gbps = GBps * 8;
    MBps = input * 1;
    Mbps = MBps * 8;
    KBps = input * 1024;
    Kbps = KBps * 8;
    Bps = input * 1024 * 1024;
    bps = input * 1024 * 1024 * 8;
  }
  if (unit == 'G' || unit == 'g') {
    GBps = input * 1;
    Gbps = GBps * 8;
    MBps = input * 1024;
    Mbps = MBps * 8;
    KBps = input * 1048576;
    Kbps = KBps * 8;
    Bps = input * 1024 * 1024 * 1024;
    bps = Bps * 8;
  }
  printf("Gigabytes per second (GBps):%.0f\n", GBps);
  printf("Gigabits per second (Gbps):%.0f\n", Gbps);
  printf("Megabytes per second (MBps):%.0f\n", MBps);
  printf("Megabits per second (Mbps):%.0f\n", Mbps);
  printf("Kilobytes per second (KBps): %.0f\n", KBps);
  printf("Kilobits per second (Kbps): %.0f\n", Kbps);
  printf("Bytes per second (Bps):%.0f\n", Bps);
  printf("Bits per second (bps):%.0f\n", bps);

  return 0;
}
```

#### Output

```sh
$ gcc -o output 3_1-Internet_plan.c && ./output
Enter your data plan in the format number multiplier Bps
Example: If your plan is 50MBps, enter 50M. Note: Omit Bps in your input)
23G
Gigabytes per second (GBps):23
Gigabits per second (Gbps):184
Megabytes per second (MBps):23552
Megabits per second (Mbps):188416
Kilobytes per second (KBps): 24117248
Kilobits per second (Kbps): 192937984
Bytes per second (Bps):24696061952
Bits per second (bps):197568495616
```

### Using `if-else` statements

#### Algorithm

1. START
2. Initialize:
    * input (float)
    * unit (character)
    * KBps, Kbps, GBps, Gbps, MBps, Mbps, Bps, bps (floats)
3. Print "Enter your data plan in the format number multiplier Bps Example: If your plan is 50MBps, enter 50M. Note: Omit Bps in your input)"
4. Input input and unit
5. Check the value of unit and perform the corresponding conversions:
    * If unit is 'K' or 'k':
        * Calculate GBps = input / 1048576
        * Calculate Gbps = GBps * 8
        * Calculate MBps = input / 1024
        * Calculate Mbps = MBps * 8
        * Calculate KBps = input
        * Calculate Kbps = KBps * 8
        * Calculate Bps = input * 1024
        * Calculate bps = Bps * 8
    * Else if unit is 'M' or 'm':
        * Calculate GBps = input / 1024
        * Calculate Gbps = GBps * 8
        * Calculate MBps = input
        * Calculate Mbps = MBps * 8
        * Calculate KBps = input * 1024
        * Calculate Kbps = KBps * 8
        * Calculate Bps = input *1024* 1024
        * Calculate bps = input *1024* 1024 * 8
    * Else if unit is 'G' or 'g':
        * Calculate GBps = input
        * Calculate Gbps = GBps * 8
        * Calculate MBps = input * 1024
        * Calculate Mbps = MBps * 8
        * Calculate KBps = input * 1048576
        * Calculate Kbps = KBps * 8
        * Calculate Bps = input *1024* 1024 * 1024
        * Calculate bps = Bps * 8
    * Else:
        * Print "Invalid input" and return 22 (Invalid argument error code)
6. Print the converted values:
    * Print "Gigabytes per second (GBps): [GBps]"
    * Print "Gigabits per second (Gbps): [Gbps]"
    * Print "Megabytes per second (MBps): [MBps]"
    * Print "Megabits per second (Mbps): [Mbps]"
    * Print "Kilobytes per second (KBps): [KBps]"
    * Print "Kilobits per second (Kbps): [Kbps]"
    * Print "Bytes per second (Bps): [Bps]"
    * Print "Bits per second (bps): [bps]"
7. END

#### Code

```c
// Simple program to convert data from one unit to another
// Promarily to be used with ISP data calculation

#include <stdio.h>

int main() {
  float input;
  char unit;
  float KBps, Kbps, GBps, Gbps, MBps, Mbps, Bps, bps;

  printf("Enter your data plan in the format number multiplier Bps\nExample: "
         "If your plan is 50MBps, enter 50M. Note: Omit Bps in your input)\n");

  scanf("%f%c", &input, &unit);

  if (unit == 'K' || unit == 'k') {
    GBps = input / 1048576;
    Gbps = GBps * 8;
    MBps = input / 1024;
    Mbps = MBps * 8;
    KBps = input * 1;
    Kbps = KBps * 8;
    Bps = input * 1024;
    bps = Bps * 8;
  } else if (unit == 'M' || unit == 'm') {
    GBps = input / 1024;
    Gbps = GBps * 8;
    MBps = input * 1;
    Mbps = MBps * 8;
    KBps = input * 1024;
    Kbps = KBps * 8;
    Bps = input * 1024 * 1024;
    bps = input * 1024 * 1024 * 8;
  } else if (unit == 'G' || unit == 'g') {
    GBps = input * 1;
    Gbps = GBps * 8;
    MBps = input * 1024;
    Mbps = MBps * 8;
    KBps = input * 1048576;
    Kbps = KBps * 8;
    Bps = input * 1024 * 1024 * 1024;
    bps = Bps * 8;
  } else {
    printf("Invalid input\n");
    return 22; // Exit code for invalid argument
  }

  printf("Gigabytes per second (GBps):%.0f\n", GBps);
  printf("Gigabits per second (Gbps):%.0f\n", Gbps);
  printf("Megabytes per second (MBps):%.0f\n", MBps);
  printf("Megabits per second (Mbps):%.0f\n", Mbps);
  printf("Kilobytes per second (KBps): %.0f\n", KBps);
  printf("Kilobits per second (Kbps): %.0f\n", Kbps);
  printf("Bytes per second (Bps):%.0f\n", Bps);
  printf("Bits per second (bps):%.0f\n", bps);

  return 0;
}
```

#### Output

```sh
$ gcc -o output 3_2-Internet_plan.c && ./output
Enter your data plan in the format number multiplier Bps
Example: If your plan is 50MBps, enter 50M. Note: Omit Bps in your input)
38273K
Gigabytes per second (GBps):0
Gigabits per second (Gbps):0
Megabytes per second (MBps):37
Megabits per second (Mbps):299
Kilobytes per second (KBps): 38273
Kilobits per second (Kbps): 306184
Bytes per second (Bps):39191552
Bits per second (bps):313532416
```

## Number base converter

### Using `if` statements only

#### Algorithm

1. START
2. Initialize:
    * num (integer)
3. Print "Enter a decimal number: "
4. Input num
5. Check if num can be represented in 4 binary bits:
    * If num > 15 or num < 0, print "Exception: The number [num] cannot be represented in 4 bits" and return 22 (Invalid argument error code)
6. Determine the binary, octal, and hexadecimal values based on num:
    * If num == 0:
        * Print "Binary: 00"
        * Print "Octal: 0"
        * Print "Hexadecimal: 0"
    * If num == 1:
        * Print "Binary: 01"
        * Print "Octal: 1"
        * Print "Hexadecimal: 1"
    * If num == 2:
        * Print "Binary: 10"
        * Print "Octal: 2"
        * Print "Hexadecimal: 2"
    * If num == 3:
        * Print "Binary: 11"
        * Print "Octal: 3"
        * Print "Hexadecimal: 3"
    * If num == 4:
        * Print "Octal: 4"
        * Print "Hexadecimal: 4"
    * If num == 5:
        * Print "Octal: 5"
        * Print "Hexadecimal: 5"
    * If num == 6:
        * Print "Octal: 6"
        * Print "Hexadecimal: 6"
    * If num == 7:
        * Print "Octal: 7"
        * Print "Hexadecimal: 7"
    * If num == 8:
        * Print "Octal: 10"
        * Print "Hexadecimal: 8"
    * If num == 9:
        * Print "Octal: 11"
        * Print "Hexadecimal: 9"
    * If num == 10:
        * Print "Octal: 12"
        * Print "Hexadecimal: A"
    * If num == 11:
        * Print "Octal: 13"
        * Print "Hexadecimal: B"
    * If num == 12:
        * Print "Octal: 14"
        * Print "Hexadecimal: C"
    * If num == 13:
        * Print "Octal: 15"
        * Print "Hexadecimal: D"
    * If num == 14:
        * Print "Octal: 16"
        * Print "Hexadecimal: E"
    * If num == 15:
        * Print "Octal: 17"
        * Print "Hexadecimal: F"
7. END

#### Code

```c
// Simple program to convert decimal to binary, octal and hexadecimal values
// Only supported till 4 bits. Values are hardcoded so not extensible.

#include <stdio.h>

int main() {

  int num;

  printf("Enter a decimal number: ");
  scanf("%d", &num);

  // Break if number cannot be represented in 4 binary bits
  if (num > 15 || num < 0) {
    printf("Exception: The number %d cannot be represented in 4 bits\n", num);
    return 22; // Exit code for invalid argument
  }

  if (num == 0) {
    printf("Binary: 00\n");
    printf("Octal: 0\n");
    printf("Hexadecimal: 0\n");
  }
  if (num == 1) {
    printf("Binary: 01\n");
    printf("Octal: 1\n");
    printf("Hexadecimal: 1\n");
  }
  if (num == 2) {
    printf("Binary: 10\n");
    printf("Octal: 2\n");
    printf("Hexadecimal: 2\n");
  }
  if (num == 3) {
    printf("Binary: 11\n");
    printf("Octal: 3\n");
    printf("Hexadecimal: 3\n");
  }
  if (num == 4) {
    // Binary of numbers greater than 4 exceeds 2 bits, hence ignore binary
    printf("Octal: 4\n");
    printf("Hexadecimal: 4\n");
  }
  if (num == 5) {
    printf("Octal: 5\n");
    printf("Hexadecimal: 5\n");
  }
  if (num == 6) {
    printf("Octal: 6\n");
    printf("Hexadecimal: 6\n");
  }
  if (num == 7) {
    printf("Octal: 7\n");
    printf("Hexadecimal: 7\n");
  }
  if (num == 8) {
    printf("Octal: 10\n");
    printf("Hexadecimal: 8\n");
  }
  if (num == 9) {
    printf("Octal: 11\n");
    printf("Hexadecimal: 9\n");
  }
  if (num == 10) {
    printf("Octal: 12\n");
    printf("Hexadecimal: A\n");
  }
  if (num == 11) {
    printf("Octal: 13\n");
    printf("Hexadecimal: B\n");
  }
  if (num == 12) {
    printf("Octal: 14\n");
    printf("Hexadecimal: C\n");
  }
  if (num == 13) {
    printf("Octal: 15\n");
    printf("Hexadecimal: D\n");
  }
  if (num == 14) {
    printf("Octal: 16\n");
    printf("Hexadecimal: E\n");
  }
  if (num == 15) {
    printf("Octal: 17\n");
    printf("Hexadecimal: F\n");
  }
  return 0;
}
```

#### Output

```sh
$ gcc -o output 4_1-Number_converter.c && ./output
Enter a decimal number: 43
Exception: The number 43 cannot be represented in 4 bits

$ gcc -o output 4_1-Number_converter.c && ./output
Enter a decimal number: 12
Octal: 14
Hexadecimal: C
```

### Using `if-else` statements

#### Algorithm

1. START
2. Initialize:
    * num (integer)
3. Print "Enter a decimal number: "
4. Input num
5. Check if num can be represented in 4 binary bits:
    * If num > 15 or num < 0, print "Exception: The number [num] cannot be represented in 4 bits" and return 22 (Invalid argument error code)
6. Determine the binary, octal, and hexadecimal values based on num using if-else statements:
    * If num == 0:
        * Print "Binary: 00"
        * Print "Octal: 0"
        * Print "Hexadecimal: 0"
    * Else if num == 1:
        * Print "Binary: 01"
        * Print "Octal: 1"
        * Print "Hexadecimal: 1"
    * Else if num == 2:
        * Print "Binary: 10"
        * Print "Octal: 2"
        * Print "Hexadecimal: 2"
    * Else if num == 3:
        * Print "Binary: 11"
        * Print "Octal: 3"
        * Print "Hexadecimal: 3"
    * Else if num == 4:
        * Print "Octal: 4"
        * Print "Hexadecimal: 4"
    * Else if num == 5:
        * Print "Octal: 5"
        * Print "Hexadecimal: 5"
    * Else if num == 6:
        * Print "Octal: 6"
        * Print "Hexadecimal: 6"
    * Else if num == 7:
        * Print "Octal: 7"
        * Print "Hexadecimal: 7"
    * Else if num == 8:
        * Print "Octal: 10"
        * Print "Hexadecimal: 8"
    * Else if num == 9:
        * Print "Octal: 11"
        * Print "Hexadecimal: 9"
    * Else if num == 10:
        * Print "Octal: 12"
        * Print "Hexadecimal: A"
    * Else if num == 11:
        * Print "Octal: 13"
        * Print "Hexadecimal: B"
    * Else if num == 12:
        * Print "Octal: 14"
        * Print "Hexadecimal: C"
    * Else if num == 13:
        * Print "Octal: 15"
        * Print "Hexadecimal: D"
    * Else if num == 14:
        * Print "Octal: 16"
        * Print "Hexadecimal: E"
    * Else if num == 15:
        * Print "Octal: 17"
        * Print "Hexadecimal: F"
    * Else:
        * Print "Unhandled error" and return 22
7. END

#### Code

```c
// Simple program to convert decimal to binary, octal and hexadecimal values
// Only supported till 4 bits. Values are hardcoded so not extensible.

#include <stdio.h>

int main() {

  int num;

  printf("Enter a decimal number: ");
  scanf("%d", &num);

  // Break if number cannot be represented in 4 binary bits
  if (num > 15 || num < 0) {
    printf("Exception: The number %d cannot be represented in 4 bits\n", num);
    return 22; // Exit code for invalid argument
  } else {
    if (num == 0) {
      printf("Binary: 00\n");
      printf("Octal: 0\n");
      printf("Hexadecimal: 0\n");
    } else if (num == 1) {
      printf("Binary: 01\n");
      printf("Octal: 1\n");
      printf("Hexadecimal: 1\n");
    } else if (num == 2) {
      printf("Binary: 10\n");
      printf("Octal: 2\n");
      printf("Hexadecimal: 2\n");
    } else if (num == 3) {
      printf("Binary: 11\n");
      printf("Octal: 3\n");
      printf("Hexadecimal: 3\n");
    } else if (num == 4) {
      // Binary of numbers greater than 4 exceeds 2 bits, hence ignore binary
      printf("Octal: 4\n");
      printf("Hexadecimal: 4\n");
    } else if (num == 5) {
      printf("Octal: 5\n");
      printf("Hexadecimal: 5\n");
    } else if (num == 6) {
      printf("Octal: 6\n");
      printf("Hexadecimal: 6\n");
    } else if (num == 7) {
      printf("Octal: 7\n");
      printf("Hexadecimal: 7\n");
    } else if (num == 8) {
      printf("Octal: 10\n");
      printf("Hexadecimal: 8\n");
    } else if (num == 9) {
      printf("Octal: 11\n");
      printf("Hexadecimal: 9\n");
    } else if (num == 10) {
      printf("Octal: 12\n");
      printf("Hexadecimal: A\n");
    } else if (num == 11) {
      printf("Octal: 13\n");
      printf("Hexadecimal: B\n");
    } else if (num == 12) {
      printf("Octal: 14\n");
      printf("Hexadecimal: C\n");
    } else if (num == 13) {
      printf("Octal: 15\n");
      printf("Hexadecimal: D\n");
    } else if (num == 14) {
      printf("Octal: 16\n");
      printf("Hexadecimal: E\n");
    } else if (num == 15) {
      printf("Octal: 17\n");
      printf("Hexadecimal: F\n");
    } else {
      printf("Unhandled error\n");
      return 22;
    }
  }
  return 0;
}
```

#### Output

```sh
$ gcc -o output 4_2-Number_converter.c && ./output
Enter a decimal number: -1
Exception: The number -1 cannot be represented in 4 bits
$ gcc -o output 4_2-Number_converter.c && ./output
Enter a decimal number: 8 
Octal: 10
Hexadecimal: 8
```

# Repetition - Looping Statements

## Multiplication table

### Algorithm

1. START
2. Print "Enter the number to want the multiplication table for in the format number x<until>. Example: 5x4 -> "
3. Input `input` and `tableUntil`
4. If `input` <= 0 or `tableUntil` <= 0, print "Inputs must be positive integers. Given: [input] and [tableUntil]" and return 22
5. For `i` from 1 to `tableUntil`:
    * Print "[input] *[i] = [input* i]"
6. END

### Code

```c
// Program to print multiplication table upto n numbers of a given input

#include <stdio.h>
int main() {

  int input;
  int tableUntil;

  printf("Enter the number to want the multiplication table for in the format "
         "number x<until>\nExample: 5x4\n-> ");

  scanf("%dx%d", &input, &tableUntil);
  printf("\n");

  if (input <= 0 || tableUntil <= 0) {
    printf("Inputs must be positive integers. Given: %d and %d\n", input,
           tableUntil);
    return 22; // Exit code for invalid arguments
  }

  for (int i = 1; i <= tableUntil; i++) {
    printf("%d * %d = %d\n", input, i, input * i);
  }

  return 0;
}
```

### Output

```sh
$ gcc -o output 1-Multiplication_table.c && ./output
Enter the number to want the multiplication table for in the format number x<until>
Example: 5x4
-> 4x19

4 * 1 = 4
4 * 2 = 8
4 * 3 = 12
4 * 4 = 16
4 * 5 = 20
4 * 6 = 24
4 * 7 = 28
4 * 8 = 32
4 * 9 = 36
4 * 10 = 40
4 * 11 = 44
4 * 12 = 48
4 * 13 = 52
4 * 14 = 56
4 * 15 = 60
4 * 16 = 64
4 * 17 = 68
4 * 18 = 72
4 * 19 = 76
```

## Factorial Calculator

### Algorithm

1. START
2. Initialize:
    * ans = 1 (unsigned long)
3. Input inp (integer) from the user.
4. Check if inp < 0:
    * If true, print an error message and exit with code 22.
5. Check if inp > 20:
    * If true, print an error message and exit with code 1.
6. Check if inp == 0:
    * If true, set ans = 1 (since 0! = 1).
7. If inp > 0:
    * For i from inp down to 1:
        * Multiply ans by i.
8. Output inp! = ans.
9. END

### Code

```sh
// Simple program to find factorial of a number

#include <stdio.h>

int main() {

  int inp;

  unsigned long ans = 1;

  printf("Enter the number to find the factorial: ");
  scanf("%d", &inp);

  if (inp < 0) {
    printf("Input must be a positive integer. Provided: %d\n", inp);
    return 22; // Exit code for invalid arguments
  } else if (inp > 20) {
    printf("Due to C data type 'unsigned long' limitations, numbers greater "
           "than 20! cannot be stored\n");
    return 1; // Exit code for operation not permitted
  } else if (inp == 0) {
    ans = 0; // 0! = 1
  } else {
    for (int i = inp; i > 0; i--) {
      ans *= i;
    }
  }

  printf("%d! = %lu\n", inp, ans);

  return 0;
}
```

### Output

```sh
$ gcc -o output 2-Factorial.c && ./output
Enter the number to find the factorial: 8
8! = 40320
$ gcc -o output 2-Factorial.c && ./output
Enter the number to find the factorial: 24 
Due to C data type 'unsigned long' limitations, numbers greater than 20! cannot be stored
$ gcc -o output 2-Factorial.c && ./output
Enter the number to find the factorial: -1
Input must be a positive integer. Provided: -1
```

## Fibonacci Series until n numbers

### Algorithm

1. START
2. Initialize:
    * num1 = 1 (unsigned long)
    * num2 = 1 (unsigned long)
3. Input inp (integer) from the user.
4. Check if inp <= 0:
    * If true, print an error message and exit with code 22.
5. Print num1.
6. For i from 1 to inp - 1:
    * Print num2.
    * Set tmpnum = num2.
    * Update num2 = num2 + num1.
    * Update num1 = tmpnum.
7. Print a newline character.
8. END

### Code

```c
// Program to print Fibonacci sequence until the given index

#include <stdio.h>

int main() {
  int inp;
  unsigned long num1 = 1;
  unsigned long num2 = 1;
  int tmpnum;

  printf("Enter the index to find Fibonacci sequence until: ");
  scanf("%d", &inp);

  if (inp <= 0) {
    printf("Index must be a greater than 0. Input: %d\n", inp);
    return 22; // Error code for invalid argument
  }

  printf("%lu", num1);

  for (int i = 1; i < inp; i++) {
    printf(", %lu", num2);

    // Jump shift the numbers by 1 for addition
    tmpnum = num2;
    num2 += num1;
    num1 = tmpnum;
  }

  printf("\n");
  return 0;
}
```

### Output

```sh
$ gcc -o output 3-Fibonacci_series.c && ./output
Enter the index to find Fibonacci sequence until: 34
1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 83204
0, 1346269, 2178309, 3524578, 5702887
```

## Fibonacci Series identifier

### Algorithm

1. START
2. Initialize:
    * num1 = 1 (unsigned long)
    * num2 = 1 (unsigned long)
3. Input inp (integer) from the user.
4. Check if inp <= 0:
    * If true, print an error message and exit with code 22.
5. While num2 <= inp:
    * If num2 == inp:
        * Print that inp is a member of the Fibonacci sequence and exit.
    * Else:
        * Set tmpnum = num2.
        * Update num2 = num2 + num1.
        * Update num1 = tmpnum.
6. Print that inp is not a member of the Fibonacci sequence.
7. END

### Code

```c
// Program to find if input number is a member of the Fibonacci sequence

#include <stdio.h>

int main() {

  int inp;

  unsigned long num1 = 1;
  unsigned long num2 = 1;
  int tmpnum;

  printf(
      "Enter the number to check if it is member of the Fibonacci sequence: ");
  scanf("%d", &inp);

  if (inp <= 0) {
    printf("Input must be a greater than 0. Input: %d\n", inp);
    return 22; // Error code for invalid argument
  }

  // Keep generating numbers in the Fibonacci sequence as long as it is less
  // than given input
  while (num2 <= inp) {

    if (num2 == inp) {
      printf("%d is a member of the Fibonacci sequence\n", inp);
      return 0;
    } else {
      // Find the next number of the Fibonacci sequence

      // Jump shift the numbers by 1 for addition
      tmpnum = num2;
      num2 += num1;
      num1 = tmpnum;
    }
  }

  printf("%d is not a member of the Fibonacci sequence\n", inp);
  return 0;
}
```

### Output

```sh
$ gcc -o output 4-Fibbonacci_identifier.c && ./output
Enter the number to check if it is member of the Fibonacci sequence: 32
32 is not a member of the Fibonacci sequence
$ gcc -o output 4-Fibbonacci_identifier.c && ./output
Enter the number to check if it is member of the Fibonacci sequence: 89
89 is a member of the Fibonacci sequence
```

## Sum of digits of a number

### Algorithm

1. START
2. Initialize:
    * sum = 0
3. Input inp (integer) from the user.
4. Set tmpinp = inp.
5. Check if inp <= 0:
    * If true, print an error message and exit with code 22.
6. While tmpinp > 0:
    * Add tmpinp % 10 to sum.
    * Update tmpinp = tmpinp / 10.
7. Output the sum of digits of inp.
8. END

### Code

```sh
// Simple program to find the sum of digits of a positive integer

#include <stdio.h>

int main(void) {
  int inp;
  int tmpinp;
  int sum;

  printf("Enter the number to find the sum of its digits: ");
  scanf("%d", &inp);
  tmpinp = inp;

  if (inp <= 0) {
    printf("Input must be greater than 0. Recieved: %d\n", inp);
    return 22; // Exit code for invalid arguments
  }

  while (tmpinp > 0) {

    // Add the units place of the given number to the sum variable
    sum += tmpinp % 10;

    // Divide the given number by 10 (to get rid of the units place and replace
    // it with ten's place)
    tmpinp /= 10;

    // Rince and repeat
  }

  printf("The sum of digits of %d is %d\n", inp, sum);

  return 0;
}
```

### Output

```sh
$ gcc -o output 5-Sum_of_digits.c && ./output
Enter the number to find the sum of its digits: 32423
The sum of digits of 32423 is 14
$ gcc -o output 5-Sum_of_digits.c && ./output
Enter the number to find the sum of its digits: -213
Input must be greater than 0. Recieved: -213
```

#
