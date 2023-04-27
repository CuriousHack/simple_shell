#include "shell.h"

/**
 * _myenv - olusola prints the current environments
 * @info: Structure containing potential arguments. Used to
 *          maintaining a constant functions of the prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - this is olusola gets the value of an environ variables
 * @info: Structure containing potential arguments. Used to
 * @name: maintain a env var names.
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - This is to Initialize a new environment variable,
 *             or to modify an existing ones.
 * @info: Structure containing potential arguments. Used to
 *        maintaining a constant functions of the prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Lateef Removed an environment variables.
 * @info: this is a structure that contain a potential argument. Used to
 *       maintaining a constant functions of a prototype.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - olusola populates the environ linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          maintaining a constant of the function prototypes.
 * Return: Always (0) success
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
/*
 * File: builtin.c
 * Auth: Ademoroti Olusola(94sola)
 *      Akande lateef(CuriousHack)
 */

