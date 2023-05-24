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
	int tmp;

	tmp = 0;
	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = temp->n;
	pop(stack, line_number);
	(*stack)->n = (*stack)->n + tmp;
}
/**
 * nop - does nothing
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
