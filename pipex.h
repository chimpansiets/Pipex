/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/14 12:42:53 by svoort         #+#    #+#                */
/*   Updated: 2019/03/16 14:31:16 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>

# define BUFF_SIZE 420

void		ft_pipex(char *input, char *cmd1, char *cmd2, char *output);
void		ft_error(char *str);
char		**ft_get_path(void);
void		ft_try_paths(char **command);

/*
**	libft files.
*/

char		*ft_joinfree(char *s1, char *s2, int j);
size_t		ft_strlen(const char *s);
size_t		ft_wcharlen(const wchar_t *s);
char		**ft_strsplit(char const *s, char c);
size_t		ft_countwords(char const *str, char c);
char		*ft_strnew(size_t size);
void		*ft_memalloc(size_t size);
void		*ft_memset(void *str, int c, size_t n);
int			ft_strncmp(char *s1, char *s2, int len);
char		*ft_strncat(char *dest, const char *src, size_t n);
void		ft_strclr(char *s);
void		ft_set_null(char ***str2, int i);

#endif
