#include "monty.h"

/**
 * _program_error - prints usage error
 * @flag: type of error 0 - malloc error, 1 - usage error
 * Return: EXIT_FAILURE
 */

int _program_error(int flag)
{
	char *errors[2] = {"Error: malloc failed", "USAGE: monty file"};

	fprintf(stderr, "%s\n", errors[flag]);
	return (EXIT_FAILURE);
}

/**
 * _file_error - prints errors associated with a file
 * @file_name: name of the file
 * Return: EXIT_FAILURE
 */

int _file_error(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	return (EXIT_FAILURE);
}

/**
 * _opcode_errors - prints errors associated with opcodes
 * @flag: error to output
 * @line_num: number line error
 * Return: EXIT_FAILURE
 */

int _opcode_errors(int flag, unsigned int line_num)
{
	char *errors[] = {
		"usage: push integer", "can't pint, stack empty",
		"can't pop an empty stack", "can't swap, stack too short",
		"can't add, stack too short", "sub, stack too short",
		"can't div, stack too short", "division by zero",
		"can't mul, stack too short", "can't mod, stack too short",
		"can't pchar, stack empty", "can't pchar, value out of range"
	};

	fprintf(stderr, "L%d: %s\n", line_num, errors[flag]);
	return (EXIT_FAILURE);
}
