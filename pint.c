#include "monty.h"

/**
 * f_pint - Prints the value at the top of the stack,
 * followed by a new line.
 * @head: The stack heah.
 * @counter: The line_number.
 */
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
