#include "monty.h"
/**
* op_swap - swaps the top two elements of the stack.
* still working on edge cases
* @stack: the memory
* @line_number: the line
*/
void op_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if ((*stack)->next == NULL || *stack == NULL || stack == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
