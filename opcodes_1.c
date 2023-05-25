#include "monty.h"

/**
 * push - push function
 * @stack: stack
 * @number: number
 * Return: void
 */
void	push(stack_t **stack, int number)
{
	stack_t	*new;

	new = NULL;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(global_line);
		fclose(global_file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new->n = number;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - pall function
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void	pall(stack_t **stack, unsigned int line_number)
{
	stack_t	*temp;

	temp = *stack;
	(void)line_number;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - pint function
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t	*temp;

	temp = *stack;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(global_line);
		fclose(global_file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}

/**
 * pop - pop function
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(global_line);
		fclose(global_file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	*stack = temp->next;
	free(temp);
}

/**
 * swap - swap function
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int tmp;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(global_line);
		fclose(global_file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = temp->n;
	temp->n = temp->next->n;
	temp->next->n = tmp;
}
