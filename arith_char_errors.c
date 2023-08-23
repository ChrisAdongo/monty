#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * division_by_zero_error - Prints an error message for division by zero.
 *
 * @line_number: Line number where the error occurred.
 *
 * Return: EXIT_FAILURE.
 */
int division_by_zero_error(unsigned int line_number)
{
	return (print_error("L%u: division by zero\n", line_number));
}

/**
 * pchar_error - Prints an error message for invalid pchar operations.
 *
 * @line_number: Line number where the error occurred.
 * @message: The specific error message.
 *
 * Return: EXIT_FAILURE.
 */
int pchar_error(unsigned int line_number, char *message)
{
	return (print_error("L%u: can't pchar, %s\n", line_number, message));
}
