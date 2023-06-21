/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:08:49 by wremy             #+#    #+#             */
/*   Updated: 2023/01/11 21:41:25 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (1)
	{
		if (*s == (char) c)
			return ((char *) s);
		if (!*s)
			break ;
		s++;
	}
	return (NULL);
}

void	ft_strcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*add_chunk_to_line(char *line, char *chunk)
{
	char	*replace_line;
	int		line_len;

	line_len = ft_strlen(line);
	replace_line = malloc(line_len + ft_strlen(chunk) + 1);
	if (replace_line == NULL)
		return (NULL);
	if (line != NULL)
	{
		ft_strcpy(replace_line, line);
		free(line);
	}
	ft_strcpy(&replace_line[line_len], chunk);
	return (replace_line);
}

char	*save_after_n(char	*line)
{
	char	*leftover;
	char	*leftover_line;
	int		i;

	i = 0;
	leftover_line = ft_strchr(line, '\n') + 1;
	if (ft_strlen(leftover_line) == 0)
		return (NULL);
	leftover = malloc(ft_strlen(leftover_line) + 1);
	if (leftover == NULL)
		return (NULL);
	while (leftover_line[i])
	{
		leftover[i] = leftover_line[i];
		i++;
	}
	leftover[i] = '\0';
	return (leftover);
}

char	*del_after_n(char	*line)
{
	char	*replace_line;
	int		i;

	i = 0;
	while (line[i] != '\n')
		i++;
	replace_line = malloc(i + 2);
	if (replace_line == NULL)
		return (NULL);
	line[i + 1] = '\0';
	ft_strcpy(replace_line, line);
	free(line);
	return (replace_line);
}
