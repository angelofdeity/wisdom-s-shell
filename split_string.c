#include "main.h"
#include <ctype.h>

/**
 * _split - split a string into an array
 * @string: string to split
 * @delimiter: delimiter to split by
 *
 * Return: string array
 */

char **_split(char *string, char *delimiter)
{
	size_t n = 4096;
	char **tokens = (char **)malloc(n * sizeof(char *));
	char *token;
	int position = 0;

	token = _strtok(string, delimiter);
	while (token != NULL)
	{
		tokens[position] = token;

		if (token && !isDelim(token[0], delimiter) && token[0] > 32)
		{
			tokens[position] = token;
			position++;
		}
		token = _strtok(NULL, delimiter);
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * isDelim - checks if a char is delim
 * @c: char to check
 * @delim: delim to chec
 *
 * Return: int
 */
int isDelim(char c, const char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}

	return (0);
}
