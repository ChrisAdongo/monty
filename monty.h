#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **tokenized_ops;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* PRIMARY INTERPRETER FUNCTIONS */
int main(int argc, char **argv);
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_tokens_snake(void);
unsigned int token_arr_len_snake(void);
int run_monty_snake(FILE *script_fd);
void set_op_token_error(int error_code);
char *integer_to_string(int num);
unsigned int absolute_value(int i);
int required_string_length(unsigned int num, unsigned int base);
void fill_string_buffer(unsigned int num, unsigned int base, char *buffer, int buffer_size);
void (*get_op_func_snake(char *opcode))(stack_t**, unsigned int);
char **split_string(char *str, char *delims);
int is_delimiter(char ch, char *delims);
int get_word_length(char *str, char *delims);
int count_words(char *str, char *delims);
char *find_next_word(char *str, char *delims);

/* void set_op_tok_error(const char *message);
const char *malloc_error(void);
const char *no_int_error(unsigned int line_number);
const char *pint_error(unsigned int line_number);
const char *pop_error(unsigned int line_number);
const char *short_stack_error(unsigned int line_number, const char *op);*/

void pint_error(unsigned int line_number);
void pop_error(unsigned int line_number);
void short_stack_error(unsigned int line_number, const char *op);

/* OPCODE FUNCTIONS */
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);
void monty_print_char(stack_t **stack, unsigned int line_number);
void monty_print_str(stack_t **stack, unsigned int line_number);
void monty_rotate_left(stack_t **stack, unsigned int line_number);
void monty_rotate_right(stack_t **stack, unsigned int line_number);
void monty_convert_to_stack(stack_t **stack, unsigned int line_number);
void monty_convert_to_queue(stack_t **stack, unsigned int line_number);
void monty_print_char(stack_t **stack, unsigned int line_number);

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delims);
char *get_int(int n);

/* ERROR MESSAGES & ERROR CODES */
int print_error(const char *format, ...);
int malloc_error(void);
int file_open_error(char *filename);
int general_error(const char *error_message);
int print_monty_error(const char *format, ...);
int unknown_opcode_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int empty_pop_error(unsigned int line_number);
int empty_pint_error(unsigned int line_number);
int short_stack_math_error(unsigned int line_number, char *operator);
int division_by_zero_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);
int is_empty_line_snake(char *line, char *delims);

#endif /* __MONTY_H__ */
