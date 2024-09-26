#include "monty.h"

int push_value;

/**
 * main - Entry point for the Monty interpreter
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char line[1024];
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Cant't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		execute_instruction(line, &stack, line_number);
	}
	fclose(file);
	return (EXIT_SUCCESS);
}

/**
 * execute_instruction - Executes an opcode from the file.
 * @opcode: The line from the file containg the opcode.
 * @stack: Pointer to the top of the stack.
 * @line_number: Current line number in the file.
 */
void execute_instruction(char *opcode, stack_t **stack,
		unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *command = strtok(opcode, " \n\t");
	char *arg = strtok(NULL, " \n\t");

	if (!command)
		return;

	if (strcmp(command, "push") == 0)
	{
		if (!arg || (atoi(arg) == 0 && strcmp(arg, "0") != 0))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		push_value = atoi(arg);
	}
	while (instructions[i].opcode)
	{
		if (strcmp(command, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
