#include "monty.h"

/**
 * f_mod - Computes the rest of the division of the second,
 * top element of the stack by the top element of the stack
 * @head: The stack head.
 * @counter: The line_number
 */
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, tmp;

	h = *head;

	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;

	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = h->next->n % h->n;
	h->next->n = tmp;
	*head = h->next;
	free(h);
}
