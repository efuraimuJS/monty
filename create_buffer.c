#include "monty.h"

/**
* create_buff - creates the buffer to parse through files
* @file_name: name of the file
*/
void create_buff(char *file_name)
{
	char *str = NULL;
	char *command = NULL;
	unsigned int line = 1;
	size_t size = 0;
	stack_t *stack = NULL;
	FILE *file;

	file = fopen(file_name, "r");
	if (!file)
	{
		printf("Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	argument_container.file = file;
	while (getline(&str, &size, file) != -1)
	{
		argument_container.input = str;
		if (*str == '\n')
		{
			line++;
			continue;
		}
		command = strtok(str, " \t\n");
		if (!command)
		{
			line++;
			continue;
		}
		argument_container.arguments = strtok(NULL, " \t\n");
		get_opcode(&stack, line, command);
		line++;
	}
	free_stack(&stack);
}
