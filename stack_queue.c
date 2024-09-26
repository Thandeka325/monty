#include "monty.h"

/**
 * f_queue - Sets the format of the data to a queue(FIFO)
 * @head: The stack head.
 * @counter: The line_number
 */
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - Adds a node to the tail of the stack.
 * @n: The new value.
 * @head: The head of the stack.
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}

/**
 * f_stack - Sets the format of the data to a stack (LIFO).
 * @head: The head of the stack.
 * @counter: The line_number.
 */
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}
