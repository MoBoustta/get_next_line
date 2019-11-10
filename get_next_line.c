/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:43:56 by moboustt          #+#    #+#             */
/*   Updated: 2019/11/10 16:14:01 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "dbg.h"
int get_next_line(int fd, char **line)
{
    static char *stack;
   char *line_i;
    char *heap;
    int byte;

    byte = 0;
    heap = NULL;
    *line = ft_strdup("");
    if (!line || fd < 0 || (read(fd, heap, 0) < 0) || (!(heap = malloc(BUFFER_SIZE + 1 * sizeof(char)))))
        return (-1);
    if (stack)
    {
        if ((line_i = memchr(stack + 1, '\n', BUFFER_SIZE)))
        {
            *line = ft_substr(stack, 0, line_i - (stack));
           // log_info(">>> line ==== %s", *line);
            stack = memchr(stack + 1, '\n', BUFFER_SIZE);
            stack++;
           // log_info(">>> stack ==== %s", stack);
            return (1);
        }
        else
        {
         //  log_info("in else");
            *line = ft_strdup(stack);
         //  log_info(">>> line === %s ", *line);
           stack = NULL;
        }
    }
    while((byte = read(fd, heap, BUFFER_SIZE)) > 0)
    {
        heap[byte] = '\0';
        if ((stack = memchr(heap, '\n', BUFFER_SIZE)))
        {
            *line = ft_strjoin(*line, ft_substr(heap, 0, stack - heap));
     //       log_info(">>> line ==== %s", *line);
            stack = ft_strdup(stack + 1);
       //     log_info(">>> stack ==== %s", stack);
            return (1);
        }
        *line = ft_strjoin(*line, heap);
        //log_info(">>> line ==== %s", *line);
    }
    if (**line == 0)
        return (0);
    return (1);
}
int main(void)
{
    int fd;
    char *line;
    fd = open("test.txt", O_RDONLY);
    while (get_next_line(fd, &line))
        printf("%s\n", line);
    return (0);
}
