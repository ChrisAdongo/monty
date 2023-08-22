#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_number);
void monty_print_char(stack_t **stack, unsigned int line_number);
void monty_print_str(stack_t **stack, unsigned int line_number);

/**
 * monty_nop - Does nothing (no operation) for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_print_char - Prints the character in the top value
 *                    node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_print_char(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_number, "value out of range"));
		return;
	}
	printf("%c\n", (*stack)->next->n);
}

/**
 * monty_print_str - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_print_str(stack_t **stack, unsigned int line_number)
{
	stack_t *current = (*stack)->next;

	while (current && current->n != 0 && (current->n > 0 && current->n <= 127))
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
	(void)line_number;
}
