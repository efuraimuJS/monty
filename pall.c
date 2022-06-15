#include "monty.h"
/**
* op_pall - prints out the stack
* @stack: the stack
* @line_number: the line
*/
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (!*stack)
		return;
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
