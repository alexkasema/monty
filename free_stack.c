#include "monty.h"

/**
 * _free_stack - frees memory allocated for stack
 * @stack: pointer to the stack
 * Return: void
 */
void _free_stack(stack_t **stack)
{
	stack_t *current = *stack;

	while (*stack)
	{
		current = (*stack)->next;
		free(*stack);
		*stack = current;
	}
}
