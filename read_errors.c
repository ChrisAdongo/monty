#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_error - Prints formatted error messages to standard error stream.
 *
 * @format: Format string for the error message.
 * @...: Additional arguments for the format string.
 *
 * Return: EXIT_FAILURE.
 */
int print_error(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);

	return (EXIT_FAILURE);
}

/**
 * usage_error - Prints a usage error message for the Monty interpreter.
 *
 * Return: EXIT_FAILURE.
 */
int usage_error(void)
{
	return (print_error("USAGE: monty file\n"));
}

/**
 * general_error - Prints a general error message.
 *
 * @error_message: The error message to print.
 *
 * Return: EXIT_FAILURE.
 */
int general_error(const char *error_message)
{
	return (print_error("Error: %s\n", error_message));
}
