#include "main.h"

/**
 * get_function - will match opcodes to correct function
 * Return: Function pointer to function
 */
 void (*get_function(char *opcode))(stack_t**, unsigned int)
 {
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };
    int x;

    for (x = 0; instructions[x].opcode; x++)
    {
        if (strcmp(opcode, instructions[x].opcode) == 0)
        {
            return (instructions[x].f);
        }
    }
    return (NULL);
 }

 /**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *node = *stack;

	while (*stack)
	{
		node = (*stack)->next;
		free(*stack);
		*stack = node;
	}
}

/**
 * free_tokens - Frees the global tokens
 */
void free_tokens(void)
{
	size_t i = 0;

	if (global_tokens == NULL)
		return;

	for (i = 0; global_tokens[i]; i++)
		free(global_tokens[i]);

	free(global_tokens);
}

/**
 * is_line_empty - will determine if a line is empty
 * @line: line in question
 * @delims: delimitors
 */
int is_line_empty(char *line, char *delims)
{
	int x, y;

	for (x = 0; x line[x]; x++)
	{
		for (y = 0; delims[y]; y++)
		{
			if (line[x] == delims[y])
			{
				break;
			}
			if (delims[y] == '\0')
			{
				return (0);
			}
		}
	}
	return (1);
}
