#include "monty.h"
/**
* op_mul - multiplies the top two elements of the stack,
* and combines them into one node.
* @stack: the memory
* @line_number: the line
*/
void op_mul(stack_t **stack, unsigned int line_number)
{
	int x, y;

	if (!(*stack)->next || !*stack || !stack)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	x = (*stack)->n;
	y = (*stack)->next->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = x * y;
}
