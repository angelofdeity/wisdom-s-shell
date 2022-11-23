#include "main.h"
#include <ctype.h>

/**
 * _split - split a string into an array
 * @string: string to split
 * @delimiter: delimiter to split by
 *
 * Return: string array
 */
/* char **_split(char *string, char *delimiter)
{
	size_t n = 4096;
	char **tokens = (char **)malloc(n * sizeof(char *));
	char *token;
	int position = 0;

	token = strtok(string, delimiter);
	while (token != NULL && check_isPrint(token) == 1 && token[0] > 32)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, delimiter);
	}
	tokens[position] = NULL;
	return (tokens);
} */

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
	return tokens;
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
