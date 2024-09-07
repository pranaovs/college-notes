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
  char flag[255] = "RRRRRRRRWWRRRRRRRRRRRRRR\n"
                   "RRRRRRRRWWRRRRRRRRRRRRRR\n"
                   "RRRRRRRRWWRRRRRRRRRRRRRR\n"
                   "RRRRRRRRWWRRRRRRRRRRRRRR\n"
                   "WWWWWWWWWWWWWWWWWWWWWWWW\n"
                   "RRRRRRRRWWRRRRRRRRRRRRRR\n"
                   "RRRRRRRRWWRRRRRRRRRRRRRR\n"
                   "RRRRRRRRWWRRRRRRRRRRRRRR\n"
                   "RRRRRRRRWWRRRRRRRRRRRRRR\n";

  // Only try colorizing the flag if user claims terminal supports 4-bit colors
  if (colorTerm) {
    printf("%s", colorize(flag));
  } else {
    printf("%s", flag);
  }

  return 0;
}
