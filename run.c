#include "monty.h"

/**
 * _run - Function that runs monty bytecode script
 * @fd: The file descriptor
 *
 * Return: On success EXIT_SUCCESS on failure EXIT_FAILURE
 */

int _run(FILE *fd)
{
	stack_t *stack = NULL;
	char *line = NULL, **token = NULL;
	char delim[] = " \n\t\b\a";
	unsigned int line_num = 0, exit_status = EXIT_SUCCESS;

	while ((line = _getline(fd)) != NULL)
	{
		line_num++;
		if (_line_empty(line, delim))
			continue;
		token = _tokenize(line, delim);
		if (token[0][0] == '#' || strcmp(token[0], "nop") == 0)
		{
			free(token);
			continue;
		}
		else if (strcmp(token[0], "push") == 0)
			exit_status = _push(&stack, token, line_num);
		else
			exit_status = _opcodes(token, &stack, line_num);
		free(token);

		if (exit_status == EXIT_FAILURE)
			break;
	}
	_free_stack(&stack);
	free(line);
	return (exit_status);
}
