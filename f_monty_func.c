#include "monty.h"

void monty_rotate_left(stack_t **stack, unsigned int line_number);
void monty_rotate_right(stack_t **stack, unsigned int line_number);
void monty_convert_to_stack(stack_t **stack, unsigned int line_number);
void monty_convert_to_queue(stack_t **stack, unsigned int line_number);

/**
 * monty_rotate_left - Rotates top value of a stack_t linked list to the bot.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_rotate_left(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		return;
	}
	top = (*stack)->next;
	bottom = (*stack)->next;

	while (bottom->next != NULL)
	{
		bottom = bottom->next;
	}
	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}

/**
 * monty_rotate_right - Rotates bot val of a stack_t linked list to top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_rotate_right(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		return;
	}
	top = (*stack)->next;
	bottom = (*stack)->next;

	while (bottom->next != NULL)
	{
		bottom = bottom->next;
	}
	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}

/**
 * monty_convert_to_stack - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_convert_to_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_convert_to_queue - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_convert_to_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
