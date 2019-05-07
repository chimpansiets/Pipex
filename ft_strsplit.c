/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 14:59:07 by svoort         #+#    #+#                */
/*   Updated: 2019/03/16 14:33:17 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int		get_word_len(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void		ft_setzero(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

static void		ft_if_c(const char *s, int *j, char c)
{
	while (s[*j] == c)
		(*j)++;
}

static void		ft_increment(int *k, int *j)
{
	(*k)++;
	(*j)++;
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str2;

	str2 = (char **)malloc(sizeof(*str2) * (ft_countwords(s, c) + 1));
	if (!s || !str2)
		return (NULL);
	ft_setzero(&i, &j);
	while (i < (int)ft_countwords(s, c))
	{
		k = 0;
		str2[i] = ft_strnew(get_word_len(&s[j], c) + 1);
		ft_set_null(&str2, i);
		ft_if_c(s, &j, c);
		while (s[j] != c && s[j])
		{
			str2[i][k] = s[j];
			ft_increment(&k, &j);
		}
		str2[i][k] = '\0';
		i++;
	}
	str2[i] = 0;
	return (str2);
}
