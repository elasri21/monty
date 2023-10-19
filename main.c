#include "monty.h"
stack_t *h = NULL;
/**
 * main - the main function
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
op_file(argv[1]);
f_node();
return (0);
}
/**
 * c_node - create a newnode
 * @data: data part
 * Return: address of the new node
 */
stack_t *c_node(int data)
{
stack_t *new;
new = malloc(sizeof(stack_t));
if (new == NULL)
p_err(4);
new->next = NULL;
new->prev = NULL;
new->n = data;
return (new);
}

/**
 * f_node - free memory
 * Return: nothing
 */
void f_node(void)
{
stack_t *tmp;
if (h == NULL)
return;
while (h != NULL)
{
tmp = h;
h = h->next;
free(tmp);
}
}

/**
 * add_in_queue - add element to the queue
 * @new: new node to add to the queue
 * @l_num: line number
 * Return: nothing
 */
void add_in_queue(stack_t **new, __attribute__((unused))unsigned int l_num)
{
stack_t *tmp;
if (new == NULL || *new == NULL)
exit(EXIT_FAILURE);
if (h == NULL)
h = *new;
else
{
tmp = h;
while (tmp->next != NULL)
tmp = tmp->next;
tmp->next = *new;
(*new)->prev = tmp;
}
}
