#include "monty.h"

/**
 * get_op_func - get opcode function
 * @token: token
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
int get_op_func(char *token, stack_t **stack, unsigned int line_number)
{
	int	i;

	instruction_t ops[] = {
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}};
	i = 0;
	while (ops[i].opcode != NULL)
	{
		if (strcmp(token, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
