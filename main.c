/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/14 12:42:23 by svoort         #+#    #+#                */
/*   Updated: 2019/03/15 15:50:18 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	if (argc != 5)
		ft_error("Usage: ./pipex file1 cmd1 cmd2 file2\n");
	else
	{
		ft_pipex(argv[1], argv[2], argv[3], argv[4]);
		wait(NULL);
	}
	return (0);
}
