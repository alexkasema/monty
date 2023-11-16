#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 * @stack: double pointer to stack
 * @line_num: number line of command
 * Return: Nothing
 */

void _add(stack_t **stack, unsigned int line_num)
{
	int num;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		_opcode_errors(4, line_num);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = num;
	_pop(stack, line_num);
}
