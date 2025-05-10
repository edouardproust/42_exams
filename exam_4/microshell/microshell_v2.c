#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

static void	put_error(char *err, char *arg)
{
	while (*err)
		write(STDERR_FILENO, err++, 1);
	if (arg)
		while (*arg)
			write(STDERR_FILENO, arg++, 1);
	write(STDERR_FILENO, "\n", 1);
}

static void	run_cd(char **argv, int i)
{
	if (i != 2)
		put_error("error: cd: bad arguments", NULL);
	else if (chdir(argv[1]) == -1)
		put_error("error: cd: cannot change directory to ", argv[1]);
}

static void	set_pipe(int *fds, int end)
{
	dup2(fds[end], end);
	close(fds[1]);
	close(fds[0]);
}


static void	execute_cmd(char **argv, int i, char **envp)
{
	int		has_pipe;
	int		fds[2];
	pid_t	pid;
	int		status;

	if (!strcmp("cd", argv[0]))
		run_cd(argv, i);
	has_pipe = argv[i] && !strcmp("|", argv[i]);
	if (has_pipe)
		pipe(fds);
	pid = fork();
	if (pid == 0)
	{
		if (has_pipe)
			set_pipe(fds, STDOUT_FILENO);
		argv[i] = NULL;
		execve(argv[0], argv, envp);
		put_error("error: cannot execute ", argv[0]);
		exit (EXIT_FAILURE);
	}
	waitpid(pid, &status, 0);
	if (has_pipe)
		set_pipe(fds, STDIN_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;

	(void)argc;
	i = 0;
	while (argv[i])
	{
		argv += i + 1;
		while (argv[i] && strcmp("|", argv[i]) && strcmp(";", argv[i]))
			i++;
		if (i != 0)
			execute_cmd(argv, i, envp);
	}
	return (EXIT_SUCCESS);
}
