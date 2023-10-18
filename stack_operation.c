#include "monty.h"
/**
 * dividing - divides nodes
 * @stack: the stack
 * @l_num: line number
 * Return: nothing
 */
void dividing(stack_t **stack, unsigned int l_num)
{
int res;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
m_err(8, l_num, "div");
if ((*stack)->n == 0)
m_err(9, l_num);
(*stack) = (*stack)->next;
res = (*stack)->n / (*stack)->prev->n;
(*stack)->n = res;
free((*stack)->prev);
(*stack)->prev = NULL;
}
/**
 * moduling - get mod of a division
 * @stack: the stack
 * @l_num: line number
 * Return: nothing
 */
void moduling(stack_t **stack, unsigned int l_num)
{
int res;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
m_err(8, l_num, "mod");
if ((*stack)->n == 0)
m_err(9, l_num);
(*stack) = (*stack)->next;
res = (*stack)->n % (*stack)->prev->n;
(*stack)->n = res;
free((*stack)->prev);
(*stack)->prev = NULL;
}
