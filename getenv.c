/*
 * File: getenv.c
 * Auth: Ademoroti Olusola(94sola)
 *      Akande lateef(CuriousHack)
 */
#include "shell.h"

/**
 * get_environ - 94sola returns th strings of an arrays of the copy of  environ
 * @info: curious structure contain a potential arguments.that is Used to
 *          maintain a constant functions of a prototype.
 * Return: Always (0)
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - Ademoroti removed an environment variables
 * @info: hack structure contains a potential arguments. Used to maintain
 *        a constant functions of the prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t w = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), w);
			w = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		w++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Akande initialize a new environment for the variables,
 *             or used to modified an existing one
 * @info: olusola Structure contain a potential arguments. Used to maintain
 *        constant function prototype.
 * @var: this is the string environ var property
 * @value: this is the string environ var value
 *  Return: Always (0)
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
