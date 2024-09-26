#include "monty.h"

/**
 * f_add - Adds the top two elements of the stock.
 * @head: The stack head.
 * @counter: The line_number.
 *
 */
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;

	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: cant't add, strack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n + h->next->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}
