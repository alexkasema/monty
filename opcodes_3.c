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

/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: double pointer to the stack
 * @line_num: number line of command
 * Return: void
 */

void _pstr(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *current = *stack;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	while (current != NULL)
	{
		if (current->n > 0 && current->n <= 127)
		{
			printf("%c", current->n);
			current = current->next;
		}
		else
			break;
	}
	printf("\n");
}
