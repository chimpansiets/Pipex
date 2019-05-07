/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strncat.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 13:48:46 by svoort         #+#    #+#                */
/*   Updated: 2019/03/15 13:48:51 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		i2;
	size_t	destlen;
	size_t	maxlen;

	i = ft_strlen(dest);
	i2 = 0;
	destlen = i;
	maxlen = ft_strlen(src) + ft_strlen(dest);
	while (i < maxlen && i < (destlen + n))
	{
		dest[i] = src[i2];
		i++;
		i2++;
	}
	dest[i] = '\0';
	return (dest);
}
