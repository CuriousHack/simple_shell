#include "main.h"

/**
 * set_data - data structure initialization
 * @datash: data structure to be initialized
 * @av: argument vector
 * Retutn: no return
 */
void set_data(data_shell *datash, char **av)
{
	unsigned int a;

	datash->av = av;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;
	datash->input = NULL;

	for (a = 0; environ[a]; a++)
	{
		;
	}
	datash->_environ = malloc(sizeof(char *) * (a + 1));
	for (a = 0; environ[a]; a++)
	{
		datash->_environ[a] = _strdup(environ[a]);
	}
	datash->_environ[a] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * free_data - free memory data
 * @datash: data structure to be freed
 * Return: no return
 */
void free_data(data_shell *datash)
{
	unsigned int a;

	for (a = 0; datash->_environ[a]; a++)
	{
		free(datash->_environ[a]);
	}
	free(datash->_environ);
	free(datash->pid);
}

/**
 * main - Entry point
 * @av: argument vectorr
 * @ac: argument count
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	data_shell datash;
	(void)ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
