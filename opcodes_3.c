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
		if (current->n >= 1 && current->n <= 127)
		{
			printf("%c", current->n);
			current = current->next;
		}
		else
			break;
	}
	printf("\n");
}

/**
 * _rotl - rotates the stack to the top.
 * @stack: double pointer to the stack
 * @line_num: number line to command
 * Return: void
 */

void _rotl(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	int first;
	stack_t *step = *stack;

	if (*stack)
	{
		first = step->n;
		while (step->next != NULL)
		{
			step->n = step->next->n;
			step = step->next;
		}
		step->n = first;
	}
}

/**
 * _rotr - rotates the stack to the bottom.
 * @stack: Double pointer to stack
 * @line_num: number line to code
 * Return: Void
 */

void _rotr(stack_t **stack, __attribute__((unused)) unsigned int line_num)
{
	int last;
	stack_t *step = *stack;

	if (*stack)
	{
		while (step->next != NULL)
			step = step->next;

		last = step->n;

		while (step->prev != NULL)
		{
			step->n = step->prev->n;
			step = step->prev;
		}

		step->n = last;
	}
}
