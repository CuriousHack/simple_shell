#include "shell.h"

/**
* _myhistory - displays the history list.
* @info: prototype structure
* Return: Always 0
*/
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
* unset_alias - alias to string
* @info: parameter struct
* @str: the string alias
*
* Return: Always 0 on success, 1 on error
*/
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		ret = delete_node_at_index(&(info->alias),
				get_node_index(info, alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

**
* set_alias - string alias
* @info: parameter struct
* @str: alias string
*
* Return: Always 0 on success, 1 otherwise
*/
int set_alias(info_t *info, char *str)
{
	char *p;
	p = _strchr(str, '=');

	if (!++p)
		return (unst_alias`
char *p;
p = _strchr(str, '=');
if (!p)
return (1);
if (!*++p)
return (unset_alias(info, str));
unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

