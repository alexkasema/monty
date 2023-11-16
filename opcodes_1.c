#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @stack: double pointer to the struct stack
 * @token: double pointer to the array of strings
 * @line_num: current line number
 * Return: EXIT_SUCCESS on success else EXIT_FAILURE
 */
int _push(stack_t **stack, char **token, unsigned int line_num)
{
	stack_t *new;

	int i = 0;

	if (token[1] == 0)
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
	if ((*stack) != NULL)
		(*stack)->prev = new;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
	return (EXIT_SUCCESS);
}


/**
 * _pall - prints elements in a stack
 * @stack: stack to be printed
 * @line_num: number line
 * return: void
 */
void _pall(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * _pint - print the top most element
 * @stack: double pointer to stack
 * @line_num: number line of command
 * Return: Nothing
 *
 */

void _pint(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	if (!current)
	{
		_opcode_errors(1, line_num);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", current->n);
}

/**
 * _pop - removes topmost element of a stack
 * @stack: double pointer to stack
 * @line_num: number line of command
 * Return: nothing
 */

void _pop(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	if (!current)
	{
		_opcode_errors(2, line_num);
		exit(EXIT_FAILURE);
	}
	if (current->next)
		current->next->prev = current->prev;
	*stack = current->next;
	free(current);
}
