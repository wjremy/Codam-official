/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:47:33 by wremy             #+#    #+#             */
/*   Updated: 2023/05/29 21:02:37 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_map_height(char	*name_file)
{
	int		height;
	char	*line;
	int		filed;

	filed = open(name_file, O_RDONLY);
	if (filed < 0)
		return (-1);
	height = 0;
	while (1)
	{
		line = get_next_line(filed);
		if (line == NULL)
		{
			close(filed);
			return (height);
		}
		free(line);
		height++;
	}
	close(filed);
	return (height);
}

int	get_amount_numbers(char	**line)
{
	int	length_line;

	length_line = 0;
	while (line[length_line] != NULL)
		length_line++;
	return (length_line);
}

int	get_map_width(char	*name_file)
{
	int		width;
	char	*line;
	int		filed;
	char	**array_of_strings;

	filed = open(name_file, O_RDONLY);
	if (filed < 0)
		return (-1);
	line = get_next_line(filed);
	array_of_strings = ft_split(line, ' ');
	if (array_of_strings == NULL)
	{
		close(filed);
		return (-1);
	}
	width = get_amount_numbers(array_of_strings);
	free(line);
	close(filed);
	return (width);
}