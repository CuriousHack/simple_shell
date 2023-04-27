/*
 * File: errors1.c code
 * Auth: Ademoroti Olusola(94sola)
 *      Akande lateef(CuriousHack)
 */

#include "shell.h"

/**
 * _erratoi - olusola converted a strings to an integers
 * @s: the string that to be converted
 * Return: always (0) if no numbr in strings, converted
 *     numbr otherwise -1 on errors.c
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - Lateef printed an errors messages
 * @info: this is the parameters & return info structure
 * @estr: this is a string which contain a specified error types
 * Return: 0 if no numbrs in strings, were converted numbe otherwise
 *        -1 on an errors
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - Ademorotisola functions  prints a decima (integer) numbr (base 10)
 * @input: this is the input
 * @fd: this is a file descriptor to write to
 *
 * Return: the numbrs of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int u, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (u = 1000000000; u > 1; u /= 10)
	{
		if (_abs_ / u)
		{
			__putchar('0' + current / u);
			count++;
		}
		current %= u;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - akande lateef converted the function, a clone of itoa
 * @num: this is the numbers
 * @base: base
 * @flags: this is an argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - olusola functions a replaced first instan of '#' with '\0'
 * @buf: this is the address of the strings that will be modified
 *
 * Return: Always (0) success;
 */
void remove_comments(char *buf)
{
	int t;

	for (t = 0; buf[t] != '\0'; t++)
		if (buf[t] == '#' && (!t || buf[t - 1] == ' '))
		{
			buf[t] = '\0';
			break;
		}
}
