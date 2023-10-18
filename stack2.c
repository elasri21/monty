#include "monty.h"
/**
 * swapping - swaps elements in a stack
 * @stack: the stack
 * @l_num: line number
 * Return: nothing
 */
void swapping(stack_t **stack, unsigned int l_num)
{
stack_t *tmp;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
m_err(8, l_num, "swap");
tmp = (*stack)->next;
(*stack)->next = tmp->next;
if (tmp->next != NULL)
tmp->next->prev = *stack;
tmp->next = *stack;
(*stack)->prev = tmp;
tmp->prev = NULL;
*stack = tmp;
}
/**
 * nop - do nothing
 * @stack: the stack
 * @l_num: line number
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int l_num)
{
(void)stack;
(void)l_num;
return;
}
/**
 * adding - summing nodes
 * @stack: the stack
 * @l_num: line number
 * Return: nothing
 */
void adding(stack_t **stack, unsigned int l_num)
{
int result;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
m_err(8, l_num, "add");
(*stack) = (*stack)->next;
result = (*stack)->n + (*stack)->prev->n;
(*stack)->n = result;
free((*stack)->prev);
(*stack)->prev = NULL;
}
/**
 * subbing - do subtuction on nodes
 * @stack: the stack
 * @l_num: line number
 * Return: nothing
 */
void subbing(stack_t **stack, unsigned int l_num)
{
int res;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
m_err(8, l_num, "sub");
(*stack) = (*stack)->next;
res = (*stack)->n - (*stack)->prev->n;
(*stack)->n = res;
free((*stack)->prev);
(*stack)->prev = NULL;
}
/**
 * multi - multiply nodes
 * @stack: the stack
 * @l_num:line number
 * Return:nothing
 */
void multi(stack_t **stack, unsigned int l_num)
{
int res;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
m_err(8, l_num, "mul");
(*stack) = (*stack)->next;
res = (*stack)->n * (*stack)->prev->n;
(*stack)->n = res;
free((*stack)->prev);
(*stack)->prev = NULL;
}

