#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp->n = temp->n + temp->next->n;
}
