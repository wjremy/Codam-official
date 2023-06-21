/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_program.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:40:58 by wremy             #+#    #+#             */
/*   Updated: 2023/06/08 21:19:50 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	initialize_graphics_program(char *file_name, t_program *prog)
{
	int		size_line;
	int		endian;

	prog->map_width = get_map_width(file_name);
	if (prog->map_width == -1)
		return (-1);
	prog->map_height = get_map_height(file_name);
	if (prog->map_height == -1)
		return (-1);
	prog->width = 800;
	prog->height = (float)(prog->map_height - 1) / (float)(prog->map_width - 1) * prog->width;
	prog->rotate_x = -18;
	prog->rotate_y = -42;
	prog->rotate_z = 0;
	prog->move_x = 0;
	prog->move_y = 0;
	prog->zoom = ((float)prog->height / (float)(prog->map_height - 1.0)) * 0.7;
	prog->depth = 0.5;
	prog->mlx_ptr = mlx_init();
	prog->win_ptr = mlx_new_window(
			prog->mlx_ptr, prog->width, prog->height, "FDF");
	prog->img_ptr = mlx_new_image(
			prog->mlx_ptr, prog->width, prog->height);
	prog->img_data = mlx_get_data_addr(
			prog->img_ptr, &prog->bpp, &size_line, &endian);
	return (1);
}
