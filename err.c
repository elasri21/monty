#include "monty.h"
/**
 * p_err - prints errorrs
 * @e_c: error code
 * Return: nothing
 */
void p_err(int e_c, ...)
{
va_list args;
char *opera;
int line_n;
va_start(args, e_c);
switch (e_c)
{
case 1:
fprintf(stderr, "USAGE: monty file\n");
break;
case 2:
fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
break;
case 3:
line_n = va_arg(args, int);
opera = va_arg(args, char *);
fprintf(stderr, "L%d: unknown instruction %s\n", line_n, opera);
break;
case 4:
fprintf(stderr, "Error: malloc failed\n");
break;
case 5:
fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
break;
default:
break;
}
f_node();
exit(EXIT_FAILURE);
}
/**
 * m_err - prints occured error
 * @e_c: error code
 * Return: nothing
 */
void m_err(int e_c, ...)
{
va_list args;
char *opera;
int line_n;
va_start(args, e_c);
switch (e_c)
{
case 6:
fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
break;
case 7:
fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
break;
case 8:
line_n = va_arg(args, unsigned int);
opera = va_arg(args, char *);
fprintf(stderr, "L%d: can't %s, stack too short\n", line_n, opera);
break;
case 9:
fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
break;
default:
break;
}
f_node();
exit(EXIT_FAILURE);
}
/**
 * str_err - print string errors
 * @e_c: error code
 * Return: nothing
 */
void str_err(int e_c, ...)
{
va_list args;
int line_n;
va_start(args, e_c);
line_n = va_arg(args, int);
switch (e_c)
{
case 10:
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_n);
break;
case 11:
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_n);
break;
default:
break;
}
f_node();
exit(EXIT_FAILURE);
}
