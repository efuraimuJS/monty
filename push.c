#include "monty.h"
/**
 * op_push - pushes integers to the stack or queue still working on edge cases
 * @stack: the memory
 * @line_number: the line
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *fresh;

	if (!stack)
		exit(EXIT_FAILURE);
	if (!(isnum(argument_container.arguments)))
	{
		printf("L%u: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	fresh = malloc(sizeof(stack_t));
	if (fresh == NULL)
	{
		printf("Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (argument_container.stack_queue == 0)
		nasus(stack, fresh);
	else
		veigar(stack, fresh);
}
