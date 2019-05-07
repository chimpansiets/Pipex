/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:29:32 by svoort         #+#    #+#                */
/*   Updated: 2019/03/14 17:14:46 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memalloc(size_t size)
{
	void	*area;

	area = (void*)malloc(size);
	if (area == NULL)
		return (NULL);
	ft_memset(area, '\0', size);
	return (area);
}
