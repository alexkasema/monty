#include "monty.h"

/**
 * _queue - Pushes an element to the queue
 * @stack: Double Pointer to the stack
 * @token: Double pointer to the array of commands
 * @line_num: number line of command
 * Return: on success EXIT_SUCCESS else EXIT_FAILURE
 */

int _queue(stack_t **stack, char **token, unsigned int line_num)
{
	stack_t *new, *current = NULL;
	int i = 0;

	if (token[1] == NULL)
		return (_opcode_errors(0, line_num));
	while (token[1][i])
	{
		if (token[1][i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (token[1][i] < '0' || token[1][i] > '9')
		{
			_free_stack(stack);
			return (_opcode_errors(0, line_num));
		}
		i++;
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (_program_error(0));
	new->n = atoi(token[1]);
	new->next = NULL;
	new->prev = NULL;
	if (!stack || !(*stack))
	{
		(*stack) = new;
		return (EXIT_SUCCESS);
	}
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;
		new->prev = current;
		current->next = new;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
