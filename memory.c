#include "monty.h"

/**
 * _getline - A function that creates space for a line in memory
 * @fd: File descriptor
 * Return: Pointer to address of line
 */

char *_getline(FILE *fd)
{
	int BUFF_SIZE = 100, c, index = 0;
	char *line = NULL;
	char *current;

	line = malloc(BUFF_SIZE);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while ((c = fgetc(fd)) != EOF && c != '\n')
	{
		if (index >= BUFF_SIZE - 1)
		{
			BUFF_SIZE *= 2;
			current = _realloc(line, BUFF_SIZE);
			if (current == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			line = current;
		}

		line[index++] = c;
	}
	if (index == 0 && c == EOF)
	{
		free(line);
		return (NULL);
	}

	line[index] = '\0';
	return line;
}

/**
 * _realloc - A function that expands the memory space
 * @str: The string to allocate memory for
 * @size: Size of memory
 * Return: pointer to new memory address
 */

char *_realloc(char *str, int size)
{
	int i;
	char *new_str;

	new_str = malloc(size);
	if (new_str == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; str[i]; i++)
		new_str[i] = str[i];
	free(str);
	return (new_str);
}
