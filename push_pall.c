#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void)line_number;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = push_value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - Prints all values on the stack from the top.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number; /* Avoid unused variable warning */

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
