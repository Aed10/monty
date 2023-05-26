#include "monty.h"

/**
 * is_number - check if string is a number
 * @token: string
 * Return: 1 if true, 0 if false
 */
int	is_number(char *token)
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
void	free_stack(stack_t *stack)
{
	stack_t	*temp;

	temp = stack;
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/**
 * add_end_node - add node to end of stack
 * @stack: stack
 * @number: number
 * Return: void
 */
void	add_end_node(stack_t **stack, int number)
{
	stack_t *new, *temp;

	new = NULL;
	temp = *stack;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(global.line);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new->n = number;
	new->next = NULL;
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}
