/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:40:47 by wremy             #+#    #+#             */
/*   Updated: 2023/06/08 21:11:59 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_program *prog)
{
	int	i;

	i = 0;
	while (i < prog->width * prog->height * prog->bpp / 8) 
	{
		prog->img_data[i] = 0;
		i++;
	}
}

void	redraw(t_program *prog)
{
	char	*img_data;
	int		size_line;
	int		endian;

	prog->img_data = mlx_get_data_addr(
			prog->img_ptr, &prog->bpp, &size_line, &endian);
	clear_image(prog);
	draw_map(prog);
	mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_ptr, 0, 0);
}

void	load_image(t_program *prog)
{
    mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_ptr, 0, 0);
    mlx_hook(prog->win_ptr, 2, 1L<<0, key_press, prog); // Listen for key press events
    mlx_loop(prog->mlx_ptr);
}
