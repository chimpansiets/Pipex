/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:40:52 by svoort         #+#    #+#                */
/*   Updated: 2019/03/14 17:09:55 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char*)ft_memalloc(size + 1);
	return (str);
}
