#ifndef MONTY_H
# define MONTY_H
# define _POSIX_C_SOURCE 200809L
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s	*prev;
	struct stack_s	*next;
}					stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char	*opcode;
	void	(*f)(stack_t **stack, unsigned int line_number);
}	instruction_t;

/* ---------------Functions----------------------*/
void parse_file(FILE *file);
void process_push(stack_t **stack, FILE *file, char *token, unsigned int line_number);
void process_token(stack_t **stack, char *token, unsigned int line_number);
int get_op_func(char *token, stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
int is_number(char *token);
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, int number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
#endif /* MONTY_H */
