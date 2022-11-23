#include "main.h"
#include <ctype.h>

/**
 * _split - split a string into an array
 * @str: string to split
 * @delimiter: delimiter to split by
 *
 * Return: string array
 */
char **_split(char *str, char *delimiter)
{
	char **tokens = malloc(14096);
	char newstr[14096];
	char *tokstr;
	int position = 0;

	if (str == NULL)
		return (NULL);
	strcpy(newstr, str);
	tokstr = strtok(newstr, delimiter);
	tokens[position] = tokstr;
	while (tokstr != NULL)
	{
		tokstr = strtok(NULL, delimiter);
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
