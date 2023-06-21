/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:01:58 by wremy             #+#    #+#             */
/*   Updated: 2023/06/08 21:28:29 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int z, t_program *prog)
{
	int	red;
	int	blue;
	int	green;
	int	max_z;

	z *= -1;
	max_z = prog->map_width * prog->zoom;
	z += 0.5 * max_z;
	red = 255;
	green = 230 - (int)((float)z / max_z * 230);
	if (green < 0)
		green = 0;
	blue = green;
	return ((red << 16) + (green << 8) + blue);
}

void	set_pixel(t_vector3D vect, t_program *prog)
{
	int	color;
	int	i;

	if ((int)vect.x <= 0 || (int)vect.x >= prog->width
		|| (int)vect.y <= 0 || (int)vect.y >= prog->height)
		return ;
	i = ((int)vect.x + (int)vect.y * prog->width) * prog->bpp / 8;
	color = get_color(vect.z, prog);
	*(int *)(prog->img_data + i) = color;
}

void draw_line(t_vector3D vect1, t_vector3D vect2, t_program *prog) {
	vect1 = transform(vect1, prog);
	vect2 = transform(vect2, prog);

	int	dx = (int)(vect2.x - vect1.x);
	int	dy = (int)(vect2.y - vect1.y);

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float x_inc = dx / (float) steps;
	float y_inc = dy / (float) steps;

	float x = vect1.x;
	float y = vect1.y;
	for (int i = 0; i <= steps; i++) {
		t_vector3D newVect;
		newVect.x = x;
		newVect.y = y;
		newVect.z = vect1.z
		set_pixel(newVect, prog);
		x += x_inc;
		y += y_inc;
	}
}

void	draw_line_to_adjacent_points(t_vector3D vect, t_program *prog)
{
	t_vector3D	vect_next;

	if (vect.x < prog->map_width - 1)
	{
		vect_next.x = vect.x + 1;
		vect_next.y = vect.y;
		vect_next.z = prog->map[(int)vect.y][(int)vect.x + 1];
		draw_line(vect, vect_next, prog);
	}
	if (vect.y < prog->map_height - 1)
	{
		vect_next.x = vect.x;
		vect_next.y = vect.y + 1;
		vect_next.z = prog->map[(int)vect.y + 1][(int)vect.x];
		draw_line(vect, vect_next, prog);
	}
}

void	draw_map(t_program *prog)
{
	t_vector3D	vect;

	vect.y = 0;
	while (vect.y < prog->map_height)
	{
		vect.x = 0;
		while (vect.x < prog->map_width)
		{
			vect.z = prog->map[(int)vect.y][(int)vect.x];
			set_pixel(transform(vect, prog), prog);
			draw_line_to_adjacent_points(vect, prog);
			vect.x++;
		}
		vect.y++;
	}
}
