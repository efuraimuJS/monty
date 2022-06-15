#include "monty.h"

/**
* op_pop - removes the top element of the stack. Still working on edge cases
* @stack: the memory
* @line_number: the line
*/
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!stack || !*stack)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (!temp->next)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}
