#include "monty.h"

/**
 * monty_push - Pushes a value to a stack_t linked list.
 *
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *new_node;
	int i;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}
	if (tokenized_ops[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}
	for (i = 0; tokenized_ops[1][i]; i++)
	{
		if (tokenized_ops[1][i] == '-' && i == 0)
		{
			continue;
		}
		if (tokenized_ops[1][i] < '0' || tokenized_ops[1][i] > '9')
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		}
	}
	new_node->n = atoi(tokenized_ops[1]);

	if (check_mode(*stack) == STACK)
	{
		current = (*stack)->next;
		new_node->prev = *stack;
		new_node->next = current;
	}
	if (current)
	{
		current->prev = new_node;
		(*stack)->next = new_node;
	}
	else
	{
		current = *stack;

		while (current->next)
		{
			current = current->next;
			new_node->prev = current;
			new_node->next = NULL;
			current->next = new_node;
		}
	}
}

/**
 * monty_pall - Prints the values of a stack_t linked list.
 *
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = (*stack)->next;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}

/**
 * monty_pint - Prints the top value of a stack_t linked list.
 *
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}
	printf("%d\n", (*stack)->next->n);
}

/**
 * monty_pop - Removes the top value element of a stack_t linked list.
 *
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next_node = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}
	next_node = (*stack)->next->next;

	free((*stack)->next);
	if (next_node)
	{
		next_node->prev = *stack;
	}
	(*stack)->next = next_node;
}

/**
 * monty_swap - Swaps the top two value elements of a stack_t linked list.
 *
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "swap"));
		return;
	}

	temp = (*stack)->next->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->prev = temp;

	if (temp->next)
	{
		temp->next->prev = (*stack)->next;
		temp->next = (*stack)->next;
		temp->prev = *stack;
	}
	(*stack)->next = temp;
}
