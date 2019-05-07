/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_path.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 13:20:59 by svoort         #+#    #+#                */
/*   Updated: 2019/03/16 14:05:29 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_path(void)
{
	extern char	**environ;
	char		**path;
	char		*s;
	int			i;

	i = 0;
	while (ft_strncmp(environ[i], "PATH=", 5) != 0)
		i++;
	s = environ[i];
	s += 5;
	path = ft_strsplit(s, ':');
	return (path);
}

void	ft_try_paths(char **command)
{
	extern char	**environ;
	char		**paths;
	int			i;
	char		*temp;

	paths = ft_get_path();
	i = 0;
	while (paths[i])
	{
		temp = ft_joinfree(paths[i], "/", 0);
		temp = ft_joinfree(temp, command[0], 0);
		if (execve(temp, command, environ) != -1)
		{
			i = -9999;
			break ;
		}
		i++;
		ft_strclr(temp);
	}
	if (i != -9999)
		ft_error("Command does not exist.\n");
}
