#include "main.h"
/**
 * _strtok - works like strtok
 * @str: string to split
 * @delim: delimiter to split string by
 *
 * Return: split string
 */
char *_strtok(char *s, const char *delim)
{
	static char *olds;
	char *token;

	if (s == NULL)
		s = olds;

	/* Scan leading delimiters.  */
	s += strspn(s, delim);
	if (*s == '\0')
	{
		olds = s;
		return NULL;
	}

	/* Find the end of the token.  */
	token = s;
	s = strpbrk(token, delim);
	if (s == NULL)
		/* This token finishes the string.  */
		olds = strchr(token, '\0');
	else
	{
		/* Terminate the token and make OLDS point past it.  */
		*s = '\0';
		olds = s + 1;
	}
	return token;
}
