#include "main.h"

/**
 * malloc_error - print malloc error to stderr and exits the program with status 1
 */
void malloc_error()
{
    fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * opcode_error - prints the unknown instruction error msg
 * @opcode: invalid opcode char
 * @line_number: invalid number line
 */
 void opcode_error(char *opcode, unsigned int line_number)
 {
    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
 }

/**
 * usage_error - print the incorrect usage error msg
 */
 void usage_error()
 {
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
 }

 /**
  * file_error - handle file descriptor error and msg
  * @filename: target filename
  */
  void file_error(char *filename)
  {
    fprintf(stderr, "Error: Can't open file %s\n");
    exit(EXIT_FAILURE);
  }

  /**
   * push_error - will print error if push is given wrong arguments
   */
   void push_error(unsigned int line_number)
   {
    fprintf(stderr, "L%u: usage: push integer\n", line_number);
    exit(EXIT_FAILURE);
   }