#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern stack_t *h;
typedef void (*opera_f)(stack_t **stack, unsigned int l_num);
void op_file(char *f_name);
void f_func(char *, char *, int, int);
int p_line(char *buff, int l_num, int format);
int char_len(FILE *);
void r_file(FILE *);

stack_t *c_node(int data);
void f_node(void);
void p_stack(stack_t **, unsigned int);
void add_in_stack(stack_t **, unsigned int);
void add_in_queue(stack_t **, unsigned int);

void coller_func(opera_f, char *, char *, int, int);

void p_top(stack_t **, unsigned int);
void popping(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swapping(stack_t **, unsigned int);

void adding(stack_t **, unsigned int);
void subbing(stack_t **, unsigned int);
void dividing(stack_t **, unsigned int);
void multi(stack_t **, unsigned int);
void moduling(stack_t **, unsigned int);

void p_chars(stack_t **, unsigned int);
void p_str(stack_t **, unsigned int);
void r_otl(stack_t **, unsigned int);

void p_err(int, ...);
void m_err(int, ...);
void str_err(int, ...);
void r_otr(stack_t **, unsigned int);

#endif
