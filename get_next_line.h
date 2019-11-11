/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:34:23 by moboustt          #+#    #+#             */
/*   Updated: 2019/11/10 17:43:16 by moboustt         ###   ########.fr       */
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

#define RET_VALUE(ret)ret > 0 ? 1 : ret
int     get_next_line(int fd, char **line);
char    *ft_strjoin(char **s1, char *s2);
char    *ft_strdup(char *s1);
char    *ft_substr(char const *s, unsigned int start, size_t len);
size_t  ft_strlen(const char *s);
void free_d_shit(char **to_free);
int gnl_get_index(char *stack);
void gnl_verify_line(char **line, char **stack, char **heap);

#endif
