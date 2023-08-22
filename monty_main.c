#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - The entry point for Monty interpreter.
 *
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int main(int argc, char **argv)
{
	FILE *monty_script_file = NULL;
	char **op_toks = NULL;

	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
	{
		usage_error();
		return (EXIT_FAILURE);
	}

	monty_script_file = fopen(argv[1], "r");

	if (monty_script_file == NULL)
	{
		f_open_error(argv[1]);
		return (EXIT_FAILURE);
	}

	exit_code = run_monty(monty_script_file);

	fclose(monty_script_file);

	return (exit_code);
}
