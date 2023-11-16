#include "monty.h"

/**
 * _opcodes - executes opcodes
 * @token: double pointer to tokens
 * @stack: double pointer to struct stacks
 * @line_num: number line
 * Return: EXIT_SUCCESS on success else EXIT_FAILURE
 */

int _opcodes(char **token, stack_t **stack, unsigned int line_num)
{
	unsigned int i = 0;

	instruction_t exec[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"null", NULL}
	};

	for (i = 0; i < 11; i++)
	{
		if (strcmp(exec[i].opcode, token[0]) == 0)
		{
			exec[i].f(stack, line_num);
			return (EXIT_SUCCESS);
		}
	}
	_free_stack(stack);
	fprintf(stderr, "L%i: unknown instruction %s\n", line_num, token[0]);
	return (EXIT_FAILURE);
}
