#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * prnt_m_error - Prints formatted error msgs to the std error stream.
 *
 * @format: Format string for the error message.
 * @...: Additional arguments for the format string.
 *
 * Return: EXIT_FAILURE.
 */
int prnt_m_error(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	return (EXIT_FAILURE);
}

/**
 * empty_pop_error - Prints an error msg when 'pop' is on an empty stack.
 *
 * @line_number: Line number where the error occurred.
 *
 * Return: EXIT_FAILURE.
 */
int empty_pop_error(unsigned int line_number)
{
	return (prnt_m_error("L%u: can't pop an empty stack\n", line_number));
}

/**
 * empty_pint_error - Prints an error msg when 'pint' is on an empty stack.
 *
 * @line_number: Line number where the error occurred.
 *
 * Return: EXIT_FAILURE.
 */
int empty_pint_error(unsigned int line_number)
{
	return (prnt_m_error("L%u: can't pint, stack empty\n", line_number));
}

/**
 * short_stack_math_error - Prints an error msg for math ops on a short stack.
 *
 * @line_number: Line number where the error occurred.
 * @operation: The specific operation attempted.
 *
 * Return: EXIT_FAILURE.
 */
int short_stack_math_error(unsigned int line_number, char *operation)
{
	return (prnt_m_error("L%u: can't %s, stack short\n", line_number, operation));
}
