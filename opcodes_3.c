#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element of the
 * stack by the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void	mod(stack_t **stack, unsigned int line_number)
{
	stack_t	*temp;
	int tmp;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = 0;
	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = temp->n;
	pop(stack, line_number);
	(*stack)->n = (*stack)->n % tmp;
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void	pchar(stack_t **stack, unsigned int line_number)
{
	stack_t	*temp;
	int ascii_val;

	ascii_val = 0;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d:  can't pchar, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	ascii_val = temp->n;
	if (ascii_val <= 65 && ascii_val <= 90)
	{
		printf("%c\n", ascii_val);
	}
	else if (ascii_val <= 97 && ascii_val <= 122)
	{
		printf("%c\n", ascii_val);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
