/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:44:01 by wremy             #+#    #+#             */
/*   Updated: 2023/05/29 20:26:45 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*convert_line_to_ints(char *line, t_program *prog)
{
	int		*array_of_ints;
	char	**array_of_strings;
	int		i;

	i = 0;
	array_of_ints = malloc(prog->map_width * sizeof(int));
	if (array_of_ints == NULL)
		return (NULL);
	array_of_strings = ft_split(line, ' ');
	while (i < prog->map_width)
	{
		array_of_ints[i] = ft_atoi(array_of_strings[i]);
		i++;
	}
	free(array_of_strings);
	return (array_of_ints);
}

int	**fill_map(t_program *prog, int filed)
{
	int		i;
	int		**map;
	char	*line;

	i = 0;
	map = malloc((prog->map_height + 1) * sizeof(int *));
	if (map == NULL)
		return (NULL);
	while (i < prog->map_height)
	{
		line = get_next_line(filed);
		if (line == NULL)
			return (NULL);
		map[i] = convert_line_to_ints(line, prog);
		if (map[i] == NULL)
			return (NULL);
		free(line);
		i++;
	}
	return (map);
}

int	get_map(char *name_file, t_program *prog)
{
	int	i;
	int	filed;

	i = 0;
	filed = open(name_file, O_RDONLY);
	if (filed == -1)
		return (-1);
	prog->map = fill_map(prog, filed);
	if (prog->map == NULL)
	{
		close(filed);
		return (-1);
	}
	close (filed);
	return (1);
}
