/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:43:56 by moboustt          #+#    #+#             */
/*   Updated: 2019/11/10 17:39:58 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
void free_d_shit(char **to_free)
{
    free(*to_free);
    *to_free = NULL;
}
int gnl_get_index(char *stack)
{
    int i;

    i = 0;
    while (stack[i])
    {
        if (stack[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

void gnl_verify_line(char **line, char **stack, char **heap)
{
    int index;
    char *add;
    index = gnl_get_index(*heap);
    *stack = ft_strdup(&heap[0][index + 1]);
    add = ft_substr(*heap, 0, index);
    *line = ft_strjoin(line, add);
    free_d_shit(heap);
    free_d_shit(&add);
}
int get_next_line(int fd, char **line)
{
    static char *stack;
    char *heap;
    int byte;

    byte = 0;
    *line = ft_strdup("");
    if (!(heap = malloc(BUFFER_SIZE + 1 * sizeof(char))))
        return (-1);
    if (stack)
    {
        if (gnl_get_index(stack) > -1)
        {
            heap = ft_strdup(stack);
            gnl_verify_line(line, &stack, &heap);
            free_d_shit(&heap);
            return (1);
        }
        *line = ft_strdup(stack);
        free_d_shit(&stack);
    }
    while ((byte = read(fd, heap, BUFFER_SIZE)) > 0)
    {
        heap[byte] = '\0';
        if (gnl_get_index(heap) > -1)
        {
            gnl_verify_line(line, &stack, &heap);
            free_d_shit(&heap);
            return (1);
        }
        *line = ft_strjoin(line, heap);
    }
    return (byte > 0 ? 1 : byte);
}
int main(void)
{
    int fd;
    char *line;
    fd = open("tests/dracula.txt", O_RDONLY);
    while (get_next_line(fd, &line))
        printf("%s\n", line);
    return (0);
}
