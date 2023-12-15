#include "main.h"

/**
* create_stack - will initialize a stack
* @stack: stack to be initialized
* Return: 0 on success. 1 on Fail.
*/
int create_stack(stack_t stack)
{
	stack_t *ptr;

	ptr = malloc(sizeof(stack_t));

	if (ptr == NULL)
	{
		fprintf("Error: malloc failed\n")
		return (1);
	}
}

/**
 * push - will push an element to the stack
 * @stack: doubly linked list stack head address
 * @value: stack value data member
 */
void push(stack_t **stack, unsigned int line_number)
{
	int x;
	stack_t *tmp, *node; 

	node = malloc(sizeof(struct stack_t));
	if (!node)
	{
		malloc_error();	
	}

	if (global_tokens[1] == NULL)
	{
		push_error();
	}

	for (x = 0; global_tokens[1][x]; x++)
	{
		if (global_tokens[1][x] == '-' && i == 0)
		{
			continue;
		}
		if (global_tokens[1][i] < '0' || global_tokens[1][i] > '9')
		{
			push_error(line_number);
		}
		node->n =atoi(global_tokens[1]);
		tmp = (*stack)->next;
		node->prev = *stack;
		node->next = tmp;
		if (tmp)
			tmp->prev = node;
		(*stack)->next = node;
	}
}

/**
 * pall - prints all the values on the stack from the top
 * @stack: input stack
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = (*stack)->next;

	while(node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
	(void)line_number;
}

/**
 * _run_opcode - will run a monty opcode script
 * @file: input file
 */
void _run_opcode(FILE *file)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, status = 0;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (create_stack(&stack) == 1)
		return (1);

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		global_tokens = strtow(line, DELIMS);
		if (global_tokens == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (global_tokens[0][0] == '#')
		{
			free_tokens();
			continue;
		}
		op_func = get_function(global_tokens[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			status = unknown_op_error(global_tokens[0], line_number);
			free_tokens();
			break;
		}
		prev_tok_len = token_arr_len();
		op_func(&stack, line_number);
		if (token_arr_len() != prev_tok_len)
		{
			if (global_tokens && global_tokens[prev_tok_len])
				status = atoi(global_tokens[prev_tok_len]);
			else
				status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}

	free(line);
	return (status);
}
