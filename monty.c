#include "main.h"

/**
 * main - entry point for the monty interpreter
 * @argc: arguments count
 * @argv: arguments vector
 * Return: Zero on Success stderr on failure
 */

int main(int argc, char *argv[])
{
	FILE *file = NULL;
	int status = 0;

	if (argc != 2)
	{
		usage_error();
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		file_error(argv[1]);
	}

	status = _run_opcode(file);
	fclose(file);
	return (status);
}
