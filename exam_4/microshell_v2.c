#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>

static void	put_error(char *str, char *arg)
{
	while (*str)
		write(STDERR_FILENO, str++, 1);
	if (arg)
		while (*arg)
			write(STDERR_FILENO, arg++, 1);
	write(STDERR_FILENO, "\n", 1);
}

static void	exec_cd(char **argv, int i)
{
	if (i != 2)
		put_error("error: cd: bad arguments", NULL);
	else if (chdir(argv[1]) == -1)
		put_error("error: cd: cannot change directory to ", argv[1]);
}

static void	set_pipe(int has_pipe, int *fd, int end)
{
	if (has_pipe)
		dup2(fd[end], end);
	close(fd[0]);
	close(fd[1]);
}

static void	execute(char **argv, int i, char **envp)
{
	bool	has_pipe;
	int		fd[2];

	has_pipe = argv[i] && !strcmp(argv[i], "|");
	if (has_pipe)
		pipe(fd);
	if (fork() == 0)
	{
		argv[i] = 0;
		set_pipe(has_pipe, fd, STDOUT_FILENO);
		execve(argv[0], argv, envp);
		put_error("error: cannot execute ", argv[0]);
		exit(EXIT_FAILURE);
	}
	waitpid(pid, NULL, 0);
	set_pipe(has_pipe, fd, STDIN_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;

	(void)argc;
	i = 0;
	while (argv[i] && argv[i + 1])
	{
		argv += i + 1;
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (!strcmp(*argv, "cd"))
			exec_cd(argv, i);
		else if (i)
			execute(argv, i, envp);
	}
	return (EXIT_SUCCESS);
}
