#include "monty.h"
/**
 * add_in_stack - adds elements to the stack
 * @new: new node to add
 * @l_num: line number
 * Return: nothing
 */
void add_in_stack(stack_t **new, __attribute__((unused))unsigned int l_num)
{
stack_t *tmp;
if (*new == NULL)
exit(EXIT_FAILURE);
if (h == NULL)
{
h = *new;
return;
}
tmp = h;
h = *new;
h->next = tmp;
tmp->prev = h;
}

/**
 * p_stack - print elements of a stack
 * @stack: the stack
 * @l_num: line number
 * Return: nothing
 */
void p_stack(stack_t **stack, unsigned int l_num)
{
stack_t *tmp;
(void)l_num;
if (stack == NULL || *stack == NULL)
printf("\n");
else
{
tmp = *stack;
while (tmp != NULL)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
}
}
/**
 * popping - pop an element
 * @stack: the stack
 * @l_num: line number
 * Return: nothing
 */
void popping(stack_t **stack, unsigned int l_num)
{
stack_t *tmp;
if (stack == NULL || *stack == NULL)
m_err(7, l_num);
tmp = *stack;
*stack = tmp->next;
if (*stack != NULL)
(*stack)->prev = NULL;
free(tmp);
}
/**
 * p_top - print the top element
 * @stack: the stack
 * @l_num: line number
 * Return: nothing
 */
void p_top(stack_t **stack, unsigned int l_num)
{
if (stack == NULL || *stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", l_num);
f_node();
exit(EXIT_FAILURE);
}
else
printf("%d\n", (*stack)->n);
}
