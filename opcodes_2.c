#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
*/
void add(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(global.line);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = 0;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(global.line);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
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
/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int tmp;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free(global.line);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = 0;
	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free(global.line);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = temp->n;
	pop(stack, line_number);
	(*stack)->n = (*stack)->n - tmp;
}

/**
 * _div - divides the second top element of the stack by the top element
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
*/
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int tmp;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free(global.line);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = 0;
	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free(global.line);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = temp->n;
	if (tmp == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(global.line);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
	(*stack)->n = (*stack)->n / tmp;
}

/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int tmp;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(global.line);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = 0;
	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(global.line);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = temp->n;
	pop(stack, line_number);
	(*stack)->n = (*stack)->n * tmp;
}
