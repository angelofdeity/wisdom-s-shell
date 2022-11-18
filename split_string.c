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

	token = strtok(string, delimiter);
	while (token != NULL && check_isPrint(token) == 1)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, delimiter);
	}
	tokens[position] = NULL;
	return (tokens);
}

int check_isPrint(char *str)
{
	int i = 0;
	int size = strlen(str);
	for (i = 0; i < size; i++)
	{
		if (str[i] != 32)
		{
			return (1);
		}
	}

	return (0);
}
