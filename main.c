#include "monty.h"

/**
* main - exec Monty code
* @argc: number of command arguments
* @argv: vector of command arguments
* Return: EXIT_SUCCESS on success, EXIT_FAILURE on fail
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	create_buff(argv[1]);
	fclose(argument_container.file);
	return (EXIT_SUCCESS);
}

/**
* free_stack - frees memory in the stack
* @head: the first node
*/
void free_stack(stack_t **head)
{
	stack_t *temp;

	if (!head)
		return;
	free(argument_container.input);
	while (*head != NULL)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}

/**
* get_opcode - gets the correct function
* @stack: the stack
* @line_number: the line_number
* @command: the command being searched for
*/
void get_opcode(stack_t **stack, unsigned int line_number, char *command)
{
	int index = 0;
	instruction_t codes[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"sub", op_sub},
		{"div", op_sub},
		{"mul", op_mul},
		{"nop", op_nop},
		{"mod", op_mod},
		{"\0", NULL}
	};

	if (command[0] == '#')
		return;
	if (strcmp(command, "queue") == 0)
	{
		argument_container.stack_queue = 0;
		return;
	}
	if (strcmp(command, "stack") == 0)
	{
		argument_container.stack_queue = 1;
		return;
	}
	while (codes[index].opcode != NULL)
	{
		if (strcmp(codes[index].opcode, command) == 0)
		{
			codes[index].f(stack, line_number);
			return;
		}
		index++;
	}
	printf("L%d: unknown instruction %s\n", line_number, command);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
