#include "monty.h"

/**
 * set_op_token_error - Sets the last element of op_toks to an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void set_op_token_error(int error_code)
{
	int toks_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = token_arr_len_snake();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));

	if (!op_toks)
	{
		malloc_error_snake();
		return;
	}
	while (i < toks_len)
	{
		new_toks[i] = op_toks[i];
		i++;
	}
	exit_str = get_int_snake(error_code);
	if (!exit_str)
	{
		free(new_toks);
		malloc_error_snake();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free_tokens_snake();
	op_toks = new_toks;
}
