#include "shell.h"

/**
* interactive - return shell interactive status
* @info: struct pointer
* Return: 1 if true, 0 otherwise
*/
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* is_delim - check for delimeter
* @c: character to check
* @delim: delim string
* Return: 1 if true, 0 otherwise
*/

int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim++ == c)
		{
			return (1);
		}
	}
	return (0);
}

/**
* _isalpha - check for alphabet
* @c: input char
* Return: 1 if true, 0 otherwise
*/
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
* _atoi - string to integer
* @s: string to be converted
* Return: 0 if no numbers in string, converted number otherwise
*/
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, result;
	unsigned int output = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			output *= 10;
			output += (s[i] - '0');
		}
		else if (flag == 1)
		{
			flag = 2;
		}
	}
	if (sign == -1)
	{
		result = -output;
	}
	else
	{
		result = output;
	}
	return (result);
}
