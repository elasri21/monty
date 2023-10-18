#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_file - open a file
 * @f_name: file name
 * Return: nothing
 */
void op_file(char *f_name)
{
FILE *file_d = fopen(f_name, "r");
if (f_name == NULL || file_d == NULL)
p_err(2, f_name);
r_file(file_d);
fclose(file_d);
}

/**
 * r_file - read from a file
 * @file_d: file descriptor
 * Return: nothing
 */

void r_file(FILE *file_d)
{
int l_num = 1, format = 0;
char *buff = NULL;
size_t length = 0;
while (getline(&buff, &length, file_d) != -1)
{
format = p_line(buff, l_num, format);
l_num++;
}
free(buff);
}

/**
 * p_line - parses a line
 * @buff: the buffer
 * @l_num: current line
 * @format: the format needed
 * Return: integer
 */
int p_line(char *buff, int l_num, int format)
{
char *val, *opcode;
const char *d = "\n";
if (buff == NULL)
p_err(4);
opcode = strtok(buff, d);
if (opcode == NULL)
return (format);
val = strtok(NULL, d);
if (strcmp(opcode, "stack") == 0)
return (0);
if (strcmp(opcode, "queue") == 0)
return (1);
f_func(opcode, val, l_num, format);
return (format);
}
/**
 * f_func - looking for a function
 * @opcode: opcode
 * @val: value
 * @l_num: line number
 * @format: format needed
 */
void f_func(char *opcode, char *val, int l_num, int format)
{
int fg, i;
instruction_t func_l[] = {
{"push", add_in_stack},
{"pall", p_stack},
{"pint", p_top},
{"pop", popping},
{"nop", nop},
{"swap", swapping},
{"add", adding},
{"sub", subbing},
{"div", dividing},
{"mul", multi},
{"mod", moduling},
{"pchar", p_chars},
{"pstr", p_str},
{"rotl", r_otl},
{"rotr", r_otr},
{NULL, NULL},
};
if (opcode[0] == '#')
return;
for (fg = 1, i = 0; func_l[i].opcode != NULL; i++)
{
if (strcmp(opcode, func_l[i].opcode) == 0)
{
coller_func(func_l[i].f, opcode, val, l_num, format);
fg = 0;
}
}
if (fg == 1)
p_err(3, l_num, opcode);
}

/**
 * coller_func - calls a function
 * @func: function name
 * @op: opcode
 * @val: value
 * @l_num: line number
 * @format: format needed
 * Return: nothing
 */
void coller_func(opera_f func, char *op, char *val, int l_num, int format)
{
int i, fg = 1;
stack_t *node;
if (strcmp(op, "push") == 0)
{
if (val != NULL && val[0] == '-')
{
val = val + 1;
fg = -1;
}
if (val == NULL)
p_err(5, l_num);
for (i = 0; val[i] != '\0'; i++)
{
if (isdigit(val[i]) == 0)
p_err(5, l_num);
}
node = c_node(atoi(val) * fg);
if (format == 0)
func(&node, l_num);
if (format == 1)
add_in_queue(&node, l_num);
}
else
func(&h, l_num);
}
