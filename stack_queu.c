#include "monty.h"

/**
 * _stack - sets the format of the data to a stack (LIFO)
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void	_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global.queue = 0;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void	queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global.queue = 1;
}
