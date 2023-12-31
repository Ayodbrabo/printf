#include "main.h"

/**
* width_handler - Calculates the width for printing
* @format: Formatted string in which to print the arguments.
* @i: List of arguments to be printed.
* @args: list of arguments.
*
* Return: width.
*/
int width_handler(const char *format, int *i, va_list args)
{
int curr_i;
int width = 0;

for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
{
if (is_digit(format[curr_i]))
{
width *= 10;
width += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
width = va_arg(args, int);
break;
}
else
break;
}

*i = curr_i - 1;

return (width);
}
