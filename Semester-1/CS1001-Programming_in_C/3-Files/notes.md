# File handling

## Formatted I/O functions

### printf()

`int printf(const char *format, ...);`

`printf("format string", arg1, arg2, ...)`

### sprintf()

`int sprintf(char *str, const char*format, ...);`

`sprintf(char * str, "format string", arg1, arg2, ...);`

### fprintf()

`int fprintf(char *str, const char *format, ...);`

`fprintf(FILE * stream, "format string", arg1, arg2, ...);`

### scanf()

`int scanf(const char *format, ...);`

### sscanf()

`int sscanf(const char *str, const char *format, ...);`

### fscanf()

`int fscanf(FILE *stream, const char *format, ...);`

## Format Specifiers

| Specifier | Description                      |
|-----------|----------------------------------|
| %d        | Signed decimal integer           |
| %i        | Signed decimal integer           |
| %u        | Unsigned decimal integer         |
| %f        | Decimal floating point           |
| %e        | Scientific notation (mantissa/exponent) |
| %E        | Scientific notation (mantissa/exponent) |
| %g        | Use the shortest representation: %e or %f |
| %G        | Use the shortest representation: %E or %f |
| %x        | Unsigned hexadecimal integer     |
| %X        | Unsigned hexadecimal integer (uppercase) |
| %o        | Unsigned octal                   |
| %s        | String of characters             |
| %c        | Character                        |
| %p        | Pointer address                  |
| %n        | Number of characters written so far |
| %%        | Percent sign                     |

## Unformatted I/O functions

`int getc(FILE *stream);`

`int getchar(void);`

`int getche(void); // Non-standard`

`char *gets(char *str); // Deprecated`

`char *fgets(char *str, int n, FILE *stream);`

`int putc(int c, FILE *stream);`

`int putchar(int char); // ASCII`

`int puts(const char *str);`

## Data files

* General purpose
* Platform independent
* Data can be stored in any format
* Proprietary format
* .dat extension

## Command Line Arguments

`int main(int argc, char *argv[]);`

* `argc` - Number of arguments
* `argv` - Array of arguments (strings, 2D array)

### Example

`./hello arg1 arg2 arg3`

* `argc = 4`
* `argv[0] = "./hello"`
* `argv[1] = "arg1"`
* `argv[2] = "arg2"`
* `argv[3] = "arg3"`
