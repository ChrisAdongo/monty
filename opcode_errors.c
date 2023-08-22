#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * file_open_error - Prints an error message for failed file opening.
 *
 * @filename: Name of the file that couldn't be opened.
 *
 * Return: EXIT_FAILURE.
 */
int file_open_error(char *filename)
{
	return (general_error("Can't open file"));
}

/**
 * unknown_opcode_error - Prints an error message for unknown opcodes.
 *
 * @opcode: The unknown opcode encountered.
 * @line_number: Line number in Monty bytecode file where error occurred.
 *
 * Return: EXIT_FAILURE.
 */
int unknown_opcode_error(char *opcode, unsigned int line_number)
{
	return (general_error("unknown instruction"));
}

/**
 * no_int_error - Prints an error message for invalid 'push' arguments.
 *
 * @line_number: Line number in Monty bytecode file where error occurred.
 *
 * Return: EXIT_FAILURE.
 */
int no_int_error(unsigned int line_number)
{
	return (general_error("usage: push integer"));
}
