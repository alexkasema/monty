#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack of its ascii value
 * @stack: double pointer to the stack
 * @line_num: number line of command
 * Return: void
 */

void _pchar(stack_t **stack, unsigned int line_num)
{
	int num;
	stack_t *current = *stack;

	if (!current)
	{
		_opcode_errors(10, line_num);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->n;
	if (num < 0 || num > 127)
	{
		_opcode_errors(11, line_num);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", current->n);
}
