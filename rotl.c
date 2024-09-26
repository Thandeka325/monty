#include "monty.h"

/**
 * f_rotl - Rotates the stack to the top.
 * @head: The head of stack.
 * @counter: The line_number
 */
void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *temp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = aux;
}
