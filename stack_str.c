#include "monty.h"
/**
 * r_otr - get the last element to the top
 * @stack: the stack
 * @l_num: line number
 * Return: nothing
 */
void r_otr(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
stack_t *tmp;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
return;
tmp = *stack;
while (tmp->next != NULL)
tmp = tmp->next;
tmp->next = *stack;
tmp->prev->next = NULL;
tmp->prev = NULL;
(*stack)->prev = tmp;
(*stack) = tmp;
}
/**
 * r_otl - get the first element to the bottom
 * @stack: the stack
 * @l_num: line number
 * Return: nothing
 */
void r_otl(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
stack_t *tmp;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
return;
tmp = *stack;
while (tmp->next != NULL)
tmp = tmp->next;
tmp->next = *stack;
(*stack)->prev = tmp;
*stack = (*stack)->next;
(*stack)->prev->next = NULL;
(*stack)->prev = NULL;
}

/**
 * p_chars - print characters
 * @stack: the stack
 * @l_num: line number
 * Return: nothing
 */
void p_chars(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
int asc;
if (stack == NULL || *stack == NULL)
str_err(11, l_num);
asc = (*stack)->n;
if (asc < 0 || asc > 127)
str_err(10, l_num);
printf("%c\n", asc);
}

/**
 * p_str - print strings
 * @stack: the stack
 * @l_num: line number
 * Return: nothing
 */
void p_str(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
stack_t *tmp;
int asc;
if (stack == NULL || *stack == NULL)
{
printf("\n");
return;
}
tmp = *stack;
while (tmp != NULL)
{
asc = tmp->n;
if (asc < 0 || asc > 127)
break;
printf("%c", asc);
tmp = tmp->next;
}
printf("\n");
}
