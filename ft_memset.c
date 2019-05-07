/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 10:58:47 by svoort         #+#    #+#                */
/*   Updated: 2019/03/14 17:16:40 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = (char*)str;
	while (i < n)
	{
		ret[i] = c;
		i++;
	}
	return (ret);
}
