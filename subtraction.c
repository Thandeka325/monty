#include "monty.h"

/**
 * f_sub - Subtracts the top element of the stack from the second,
 * top element of the stack.
 * @head: The head of the stack.
 * @counter: The line_number
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int sub, nodes;

	temp = *head;

	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	sub = temp->next->n - temp->n;
	temp->next->n = sub;
	*head = temp->next;
	free(temp);
}
