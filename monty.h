#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 *
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int _run(FILE *fd);
int _opcodes(char **token, stack_t **stack, unsigned int line_num);

int _push(stack_t **stack, char **token, unsigned int line_num);
void _pall(stack_t **stack, unsigned int line_num);
void _pint(stack_t **stack, unsigned int line_num);
void _pop(stack_t **stack, unsigned int line_num);
void _swap(stack_t **stack, unsigned int line_num);
void _add(stack_t **stack, unsigned int line_num);
void _sub(stack_t **stack, unsigned int line_num);

char **_tokenize(char *line, char *delim);
int _line_empty(char *line, char *delim);

char *_getline(FILE *fd);
char *_realloc(char *str, int size);

void _free_stack(stack_t **stack);

int _program_error(int flag);
int _file_error(char *file_name);
int _opcode_errors(int flag, unsigned int line_num);

#endif

