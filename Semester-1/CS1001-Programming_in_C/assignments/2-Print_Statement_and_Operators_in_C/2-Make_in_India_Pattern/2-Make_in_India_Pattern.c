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
// https://github.com/pranaovs/college-notes/tree/main/Semester-1/CS1001-Programming_in_C/assignments/2-Print_Statement_and_Operators_in_C/3-Country-Flag/3-Country_Flag.c
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
  // https://github.com/pranaovs/college-notes/tree/main/Semester-1/CS1001-Programming_in_C/assignments/2-Print_Statement_and_Operators_in_C/3-Country-Flag/3-Country_Flag.c
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
