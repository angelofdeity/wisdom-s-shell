#include "main.h"
#include "errno.h"

/**
 * main - main function
 * @argc: argument count
 * @argv: array of argument strings
 * @env: environment variables
 * Return: 0 on success
 */
int main(int argc __attribute__((unused)), char **argv, char **env)
{
	char *cmd;
	char **args;
	char *shell_name = argv[0];
	int count;
	int shell_interaction;

	_setenv("_", shell_name, 1);
	count = 1;

	shell_interaction = isatty(STDIN_FILENO);
	if (shell_interaction == 0 && argc == 1) /* if non-interactive */
	{
		int exit_code = 0;
		char *exitchar;

		exitchar = _getenv("err_code");

		if (exitchar != NULL)
		{
			exit_code = atoi(exitchar);
			free(exitchar);
		}
		
		while ((cmd = read_cmd()) != NULL) /* grabs input */
		{
			args = _split(cmd, " \t\n\a\r\f\v");

			if (args[0] == NULL)
				exit(exit_code);
			exec_cmd(args, env, cmd, &count);
			free(cmd);
		}

		exit(exit_code);
	}
	while (1)
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "$ ", 3);

		cmd = read_cmd();

		args = _split(cmd, " \t\r\n\f\v\a");

		exec_cmd(args, env, cmd, &count);
		free(args);
		free(cmd);
	}

	return (0);
}
