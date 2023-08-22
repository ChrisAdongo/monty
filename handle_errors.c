#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_monty_error - Prints formatted error messages to the standard error stream.
 *
 * @format: Format string for the error message.
 * @...: Additional arguments for the format string.
 *
 * Return: EXIT_FAILURE.
 */
int print_monty_error(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	return (EXIT_FAILURE);
}

/**
 * empty_pop_error - Prints an error message when 'pop' is attempted on an empty stack.
 *
 * @line_number: Line number where the error occurred.
 *
 * Return: EXIT_FAILURE.
 */
int empty_pop_error(unsigned int line_number)
{
	return (print_monty_error("L%u: can't pop an empty stack\n", line_number));
}

/**
 * empty_pint_error - Prints an error message when 'pint' is attempted on an empty stack.
 *
 * @line_number: Line number where the error occurred.
 *
 * Return: EXIT_FAILURE.
 */
int empty_pint_error(unsigned int line_number)
{
	return (print_monty_error("L%u: can't pint, stack empty\n", line_number));
}

/**
 * short_stack_math_error - Prints an error message for math ops on a short stack.
 *
 * @line_number: Line number where the error occurred.
 * @operation: The specific operation attempted.
 *
 * Return: EXIT_FAILURE.
 */
int short_stack_math_error(unsigned int line_number, char *operation)
{
	return (print_monty_error("L%u: can't %s, stack too short\n", line_number, operation));
}
