#include "monty.h"

/**
 * _tokenize - A fuction that tokenizes a string
 * @line: The string to tokenize
 * @delim: The separators
 * Return: Double Pointer to token array
 */

char **_tokenize(char *line, char *delim)
{
	char *tokens = NULL, **token = NULL;
	size_t buffer_size = 0;
	int i = 0;

	if (line == NULL || !*line)
		return (NULL);

	buffer_size = strlen(line);
	if (buffer_size == 0)
		return (NULL);
	token = malloc(sizeof(char *) * buffer_size);
	if (token == NULL)
	{
		free(line);
		free(token);
		exit(_program_error(0));
	}
	tokens = strtok(line, delim);
	if (tokens == NULL)
	{
		free(token);
		free(line);
		return (NULL);
	}
	while (tokens != NULL)
	{
		token[i] = tokens;
		i++;
		tokens = strtok(NULL, delim);
	}
	token[i] = '\0';
	return (token);
}

/**
 * _line_empty - check if line is empty
 * @line: string to check
 * @delim: list of separators
 *
 * Return: 1 if line only contains delimiters, else 0
 */

int _line_empty(char *line, char *delim)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (line[i] == delim[j])
				break;
		}
		if (delim[j] == '\0')
			return (0);
	}

	return (1);
}
