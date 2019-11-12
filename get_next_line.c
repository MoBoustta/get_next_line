/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:43:56 by moboustt          #+#    #+#             */
/*   Updated: 2019/11/12 14:52:54 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		free_d_shit(char **to_free)
{
	if (*to_free != NULL)
	{
		free(*to_free);
		*to_free = NULL;
	}
}

int			gnl_get_index(char *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int			gnl_handle_stack(char **line, char **stack, char **heap)
{
	if (*stack)
	{
		if (gnl_get_index(*stack) > -1)
		{
			*heap = *stack;
			gnl_verify_line(line, stack, heap);
			free_d_shit(heap);
			return (1);
		}
		*line = ft_strdup(*stack);
		free_d_shit(stack);
	}
	return (0);
}

void		gnl_verify_line(char **line, char **stack, char **heap)
{
	int		index;
	char	*add;

	index = gnl_get_index(*heap);
	*stack = ft_strdup(&heap[0][index + 1]);
	add = ft_substr(*heap, 0, index);
	*line = ft_strjoin(*line, add);
	free_d_shit(heap);
	free_d_shit(&add);
}

int			get_next_line(int fd, char **line)
{
	static	char	*stack;
	char			*heap;
	int				byte;

	byte = 0;
	heap = NULL;
	*line = ft_strdup("");
	if ((byte = gnl_handle_stack(line, &stack, &heap)) == 1)
		return (1);
	if (!(heap = malloc(BUFFER_SIZE + 1 * sizeof(char))))
		return (-1);
	while ((byte = read(fd, heap, BUFFER_SIZE)) > 0)
	{
		heap[byte] = '\0';
		if (gnl_get_index(heap) > -1)
		{
			gnl_verify_line(line, &stack, &heap);
			return (1);
		}
		*line = ft_strjoin(*line, heap);
		free_d_shit(&stack);
	}
	return (byte > 0 ? 1 : byte);
}
