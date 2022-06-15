#include "monty.h"
/**
* nasus - The master of stacks in League of Legends
* LIFO data type, defualt functionality
* @stack: the memory
* @fresh: the new memory to add
*/
void nasus(stack_t **stack, stack_t *fresh)
{
	fresh->n = atoi(argument_container.arguments);
	if (!*stack)
	{
		fresh->prev = NULL;
		fresh->next = NULL;
		*stack = fresh;
	}
	else
	{
		(*stack)->prev = fresh;
		fresh->next = *stack;
		fresh->prev = NULL;
		*stack = fresh;
	}
}
