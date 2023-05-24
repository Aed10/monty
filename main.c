#include "monty.h"

/**
 * parse_file - parses a file
 * @file: file to parse
 */
void	parse_file(FILE *file)
{
	char			*line;
	size_t			len;
	ssize_t			read;
	stack_t			*stack;
	unsigned int	line_number;
	char			*token;

	line = NULL;
	len = 0;
	stack = NULL;
	line_number = 0;
	token = NULL;
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		token = strtok(line, " \n\t");
		if (token == NULL || token[0] == '#')
			continue;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \n\t");
			if (token == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			process_push(&stack, file, token, line_number);
		}
		else
		{
			process_token(&stack, token, line_number);
		}
	}
	free(line);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * process_push - processes a push command
 * @stack: pointer to the stack
 * @file: File
 * @token: token to process
 * @line_number: line number
 * Return: void
*/
void	process_push(stack_t **stack, FILE *file, char *token,
		unsigned int line_number)
{
	int	i;

	i = is_number(token);
	if (i == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	push(stack, atoi(token));
}

/**
 * process_token - processes a token
 * @stack: pointer to the stack
 * @token: token to process
 * @line_number: line number
 * Return: void
*/
void	process_token(stack_t **stack, char *token, unsigned int line_number)
{
	get_op_func(token, stack, line_number);
}

/**
 * main - main function
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0
 */
int	main(int argc, char *argv[])
{
	FILE	*file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	parse_file(file);
	return (0);
}
