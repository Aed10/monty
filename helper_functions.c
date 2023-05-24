#include "monty.h"
/**
 * is_number - check if string is a number
 * @token: string
 * Return: 1 if true, 0 if false
 */
int is_number(char *token)
{
	int i;

	i = 0;
	if (token[0] == '-')
		i++;

	while (token[i] != '\0')
	{
		if (isdigit(token[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/**
 * free_stack - free stack
 * @stack: stack
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *temp = stack;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
