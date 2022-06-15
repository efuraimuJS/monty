#include "monty.h"
/**
* veigar - the FIFO data type
* Also stacks in League of Legends
* @stack: the memory
* @fresh: the new memory to add
*/
void veigar(stack_t **stack, stack_t *fresh)
{
	stack_t *temp;

	fresh->next = NULL;
	fresh->n = atoi(argument_container.arguments);
	if (!*stack)
	{
		fresh->prev = NULL;
		*stack = fresh;
	}
	else
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = fresh;
		fresh->prev = temp;
	}
}
