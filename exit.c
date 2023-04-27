#include "shell.h"

/**
**_strncpy - copies a string
* @dest: string destination
* @src: string source
* @n: the amount of characters to be copied
* Return: concatenated string
*/
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
**_strncat - concatenates strings
*@dest: destination string
*@src: source string
*@n: byte ammount
*Return: the concatenated string
*/
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
**_strchr - character search
*@s: parse string
*@c: target character
*Return: (s)
*/
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');
		return (NULL);
}

