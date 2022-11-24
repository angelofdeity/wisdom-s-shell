#include "main.h"
#include <ctype.h>

/**
 * _split - split a string into an array
 * @str: string to split
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
/*
char **_split(char *str, char *delimiter)
{
	char **tokens = malloc(14096);
	char newstr[14096];
	char *tokstr;
	int position = 0;

	if (str == NULL)
		return (NULL);
	strcpy(newstr, str);
	tokstr = _strtok(newstr, delimiter);
	tokens[position] = tokstr;
	while (tokstr != NULL)
	{
		tokstr = _strtok(NULL, delimiter);
		if (tokstr && !isDelim(tokstr[0], delimiter) && tokstr[0] > 32)
		{
			position++;
			tokens[position] = tokstr;
		}
	}
	position++;
	tokens[position] = NULL;
	return (tokens);
}
*/
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
