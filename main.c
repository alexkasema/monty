#include "monty.h"

/**
 * main - entry point of the interpreter
 * @ac: number of arguments
 * @av: pointer to array of program arguments
 * Return: 0 on Success
 */

int main(int ac, char **av)
{
	FILE *fd = NULL;
	int exit_status = EXIT_SUCCESS;

	if (ac != 2)
		return (_program_error(1));

	fd = fopen(av[1], "r");
	if (fd == NULL)
		return (_file_error(av[1]));

	exit_status = _run(fd);
	fclose(fd);

	return (exit_status);
		_file_error(av[1]);

	_run(fd);
	exit(EXIT_SUCCESS);
	return (0);
}

