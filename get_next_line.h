/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:34:23 by moboustt          #+#    #+#             */
/*   Updated: 2019/11/13 14:34:01 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# define MAX_INT 2147483647

int		get_next_line(int fd, char **line);
void	free_d_shit(char **to_free);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		gnl_get_index(char *stack);
void	gnl_verify_line(char **line, char **stack, char **heap);
int		gnl_read_line(char **line, char **stack, char **heap, int byte, int fd);

#endif
