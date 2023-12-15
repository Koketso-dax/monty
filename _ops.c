#include "main.h"

/**
 * push - will push an element to the stack
 * @stack: doubly linked list stack head address
 * @value: stack value data member
 */

void push(stack_t **stack, char *value)
{
	int num;
	stack_t *node;

	if ((!value || !isdigit(*value)) && *value != '-' && *value != '+')
	{
		fprintf(stderr,"usage: push integer\n");
		exit(EXIT_FAILURE);
	}
	num = atoi(value);
	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = num;
	node->prev = NULL;
	node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = node;
	}
	*stack = node;
}

/**
 * pall - prints all the values on the stack from the top
 * @stack: input stack
 */
void pall(stack_t **stack)
{
	stack_t *node = *stack;

	while(node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

/**
 * _run_opcode - will run a monty opcode script
 * @opcode: command opcode
 * @arg: instruction argument
 * @stack: stack object
 */
void _run_opcode(char *opcode, char *arg, stack_t **stack)
{
	int x = 0;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}};
	
	while(instructions[x].opcode)
	{
		if (strcmp(opcode, instructions[x].opcode) == 0)
		{
			instructions[x].f(stack);
			return;
		}
		x++;
	}

	fprintf(stderr, "unknown instruction%s\n", opcode);
	exit(EXIT_FAILURE);
}
