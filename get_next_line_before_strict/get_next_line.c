/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:08:58 by wremy             #+#    #+#             */
/*   Updated: 2023/01/11 20:34:06 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*chunk;
	char		*line;
	static char	*leftover = NULL;
	int			rt;

	line = leftover;
	leftover = NULL;
	chunk = malloc(BUFFER_SIZE + 1);
	if (chunk == NULL)
		return (NULL);
	while (ft_strchr(line, '\n') == NULL)
	{
		rt = read(fd, chunk, BUFFER_SIZE);
		if (rt == -1)
			return (free(chunk), free(line), NULL);
		if (rt == 0)
			return (free(chunk), line);
		chunk[rt] = '\0';
		line = add_chunk_to_line(line, chunk);
		if (line == NULL)
			return (NULL);
	}
	free(chunk);
	leftover = save_after_n(line);
	line = del_after_n(line);
	return (line);
}

// int	main(void)
// {
// 	int	i;
// 	int	filed;

// 	filed = open("hello.txt", O_RDONLY);
// 	i = 0;
// 	while (i < 2)
// 	{
// 		printf("%s", get_next_line(filed));
// 		i++;
// 	}
// 	// char	*line;
// 	// char	*chunk;

// 	// line = malloc(3);
// 	// chunk = malloc(6);
// 	// chunk[0] = 'h';
// 	// chunk[1] = 'i';
// 	// chunk[2] = '\n';
// 	// chunk[3] = '\n';
// 	// chunk[4] = 's';
// 	// chunk[5] = '\0';
// 	// line[0] = 's';
// 	// line[1] = 'o';
// 	// line[2] = '\0';
// 	// line = NULL;
// 	// line = save_after_n(chunk);
// 	// printf("%s", line);
// }