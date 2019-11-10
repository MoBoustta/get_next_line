/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:34:23 by moboustt          #+#    #+#             */
/*   Updated: 2019/11/10 11:33:53 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

int     get_next_line(int fd, char **line);
size_t  get_index(const char *line);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strdup(char *s1);
void    ft_bzero(void *s, size_t n);
void    *ft_memset(void *b, int c, size_t len);
char    *ft_substr(char const *s, unsigned int start, size_t len);
void    *ft_memchr(const void *s, int c, size_t n);
size_t  ft_strlen(const char *s);

#endif
