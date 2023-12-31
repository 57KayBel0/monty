#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

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
 * struct monty_vars - Stack Struct properties and global variables
 * @stream: buffer read from file
 * @line: entire line from stream
 * @stack_len: number of elements in the stack
 * @stack: data structure doubly linked list
 * @mode: STACK or QUEUE
 *
 * Description: structure that holds the stack properties like its length
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct monty_vars
{
	FILE *stream;
	char *line;
	size_t stack_len;
	stack_t *stack;
	int mode;
} st_data_var;

/* Global Variable to hold stack length */
extern st_data_var st_data;

#define STACK 0
#define QUEUE 1

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

/* opcodes Functions */
void get_op_func(char *op_code, stack_t **stack, unsigned int line_number);
void m_push(stack_t **stack, unsigned int line_number);
void m_pall(stack_t **stack, unsigned int line_number);
void m_pint(stack_t **stack, unsigned int line_number);
void m_pop(stack_t **stack, unsigned int line_number);
void m_nop(stack_t **stack, unsigned int line_number);
void m_swap(stack_t **stack, unsigned int line_number);
void m_add(stack_t **stack, unsigned int line_number);
void m_sub(stack_t **stack, unsigned int line_number);
void m_mul(stack_t **stack, unsigned int line_number);
void m_div(stack_t **stack, unsigned int line_number);
void m_mod(stack_t **stack, unsigned int line_number);
void m_pchar(stack_t **stack, unsigned int line_number);
void m_pstr(stack_t **stack, unsigned int line_number);
void m_rotl(stack_t **stack, unsigned int line_number);
void m_rotr(stack_t **stack, unsigned int line_number);
void m_stack(stack_t **stack, unsigned int line_number);
void m_queue(stack_t **stack, unsigned int line_number);

/* Linked Lists Functions */
stack_t *add_node(stack_t **stack, int n);
void m_free_list(void);

/* Aux Functions */
int _is_number(char *p_arg);
void m_fs_close(void);
void m_free_line(void);

#endif /* MONTY_H */
