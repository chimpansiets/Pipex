/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pipex.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/14 15:10:31 by svoort         #+#    #+#                */
/*   Updated: 2019/03/16 16:00:14 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cmd1(int fd1, int pipes[2], char *cmd1)
{
	extern char	**environ;
	char		**command;
	int			ret;

	command = ft_strsplit(cmd1, ' ');
	ret = dup2(fd1, 0);
	if (ret < 0)
		ft_error("Error redirecting file descriptor.\n");
	ret = dup2(pipes[1], 1);
	if (ret < 0)
		ft_error("Error redirecting file descriptor.\n");
	close(fd1);
	close(pipes[0]);
	close(pipes[1]);
	if (command[0][0] == '/')
	{
		if (execve(command[0], command, environ) < 0)
			ft_error("Could not find command.\n");
	}
	else
		ft_try_paths(command);
	close(fd1);
	close(pipes[0]);
	close(pipes[1]);
}

void	ft_cmd2(int fd2, int pipes[2], char *cmd2)
{
	extern char	**environ;
	char		**command;
	int			ret;

	wait(NULL);
	ret = dup2(pipes[0], 0);
	command = ft_strsplit(cmd2, ' ');
	if (ret < 0)
		ft_error("Error redirecting file descriptor\n");
	ret = dup2(fd2, 1);
	if (ret < 0)
		ft_error("Error redirecting file descriptor\n");
	close(fd2);
	close(pipes[0]);
	close(pipes[1]);
	if (command[0][0] == '/')
	{
		if (execve(command[0], command, environ) < 0)
			ft_error("Command does not exist.\n");
	}
	else
		ft_try_paths(command);
	close(fd2);
	close(pipes[0]);
	close(pipes[1]);
}

/*
**	pipe() opens a new process. pipes[0] = read() file descriptor.
**								pipes[1] = write() file descriptor.
*/

void	ft_pipex(char *input, char *cmd1, char *cmd2, char *output)
{
	pid_t	pid;
	int		fd1;
	int		fd2;
	int		pipes[2];

	pipe(pipes);
	fd1 = open(input, O_RDONLY);
	if (fd1 < 0)
		ft_error("File open failure\n");
	fd2 = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd2 < 0)
		ft_error("File open failure\n");
	pid = fork();
	if (pid == -1)
		ft_error("Process creation error \n");
	if (pid == 0)
	{
		ft_cmd1(fd1, pipes, cmd1);
	}
	pid = fork();
	if (pid == -1)
		ft_error("Process creation error \n");
	else if (pid == 0)
		ft_cmd2(fd2, pipes, cmd2);
}
