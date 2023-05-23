#include "monty.h"

/**
 * main - main function
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0
 */
int	main(int argc, char *argv[])
{
	FILE *file;
	char *line;
	size_t len;
	ssize_t	read;
	stack_t	*stack;
	unsigned int line_number;
	char *token;
	int i;

	line = NULL;
	len = 0;
	stack = NULL;
	line_number = 0;
	token = NULL;
	i = 0;

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
			i = is_number(token);
			if (i == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			push(&stack, atoi(token));
		}
		else
		{
			get_op_func(token, &stack, line_number);
		}
	}
	free(line);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

