#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

static void	put_error(char *err, char *arg)
{
	int	fdout;

	fdout = STDERR_FILENO;
	while (*err)
		write(fdout, err++, 1);
	if (arg)
	{
		write(fdout, " ", 1);
		while (*arg)
			write(fdout, arg++, 1);
	}
	write(fdout, "\n", 1);
}

static void	exit_fatal()
{
	put_error("error: fatal", NULL);
	exit(EXIT_FAILURE);
}

static int	next_sep_index(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] && strcmp("|", argv[i]) && strcmp(";", argv[i]))
		i++;
	return (i);
}

static int	run_cd(char **argv, int i)
{
	if (i != 2)
	{
		put_error("error: cd: bad arguments", NULL);
		return (EXIT_FAILURE);
	}
	if (chdir(argv[1]) == -1)
	{
		put_error("error: cd: cannot change directory to", argv[1]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static void	set_pipe(int *fds, int end)
{	
	dup2(fds[end], end);
	close(fds[1]);
	close(fds[0]);
}


static int	execute_cmd(char **argv, int i, char **envp)
{
	int		has_pipe;
	int		fds[2];
	pid_t	pid;
	int		status;
	
	if (!strcmp("cd", argv[0]))
		return (run_cd(argv, i));
	has_pipe = argv[i] && !strcmp("|", argv[i]);
	if (has_pipe)
		pipe(fds);
	pid = fork();
	if (pid < 0)
		exit_fatal();
	if (pid == 0)
	{
		if (has_pipe)
			set_pipe(fds, STDOUT_FILENO);
		argv[i] = NULL;
		execve(argv[0], argv, envp);
		put_error("error: cannot execute", argv[0]);
		exit (EXIT_FAILURE);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	if (has_pipe)
		set_pipe(fds, STDIN_FILENO);
	return (status);
}

int	main(int argc, char **argv, char **envp)
{
	int	status;
	int	i;

	(void)argc;
	status = EXIT_SUCCESS;
	i = 0;
	while (argv[i])
	{
		argv += i + 1;
		i = next_sep_index(argv);
		if (i != 0)
			status = execute_cmd(argv, i, envp);
	}
	return (status);
}
