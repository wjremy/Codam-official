/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_map_to_dots copy.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:01:58 by wremy             #+#    #+#             */
/*   Updated: 2023/05/29 18:21:00 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	degree_to_radian(int degree)
{
	return (degree * M_PI / 180);
}

vector3D	rotate(vector3D vector, program *prog)
{
	float	rotate_x = degree_to_radian(prog->rotate_x);
	float	rotate_y = degree_to_radian(prog->rotate_y);
	float	rotate_z = degree_to_radian(prog->rotate_z);

	vector.z *= -1;

	vector.y = vector.y * cos(rotate_x) - vector.z * sin(rotate_x);
	vector.z = vector.y * sin(rotate_x) + vector.z * cos(rotate_x);

	vector.x = vector.x * cos(rotate_y) + vector.z * sin(rotate_y);
	vector.z = -vector.x * sin(rotate_y) + vector.z * cos(rotate_y);

	vector.x = vector.x * cos(rotate_z) - vector.y * sin(rotate_z);
	vector.y = vector.x * sin(rotate_z) + vector.y * cos(rotate_z);

	return (vector);
}

int	get_color(int z, program *prog)
{
	int	red;
	int	blue;
	int	green;
	int	max_z;

	z += 0.5 * prog->map_width * prog->zoom;
	max_z = prog->map_width * prog->zoom;
	red = 255;
	green = 230 - (int)((float)z / max_z * 230);
	blue = green;
	return ((red << 16) + (green << 8) + blue);
}

vector3D centralize(vector3D vect, program *prog) {
    vect.x -= prog->map_width / 2;
    vect.y -= prog->map_height / 2;
    return vect;
}

vector3D apply_perspective(vector3D vect) {
    if (vect.z != 0) {
        vect.x /= 1 + 0.05 *vect.z;
        vect.y /= 1 + 0.05 *vect.z;
    }
    return vect;
}

vector3D apply_zoom(vector3D vect, program *prog) {
    vect.x *= prog->zoom;
    vect.y *= prog->zoom;
    vect.z *= prog->zoom;
    return vect;
}

vector3D reposition(vector3D vect, program *prog) {
    vect.x += prog->width / 2 + prog->move_x * prog->zoom;
    vect.y += prog->height / 2 + prog->move_y * prog->zoom;
    return vect;
}

vector3D transform(vector3D vect, program *prog) {
    vect = centralize(vect, prog);
    vect = rotate(vect, prog);
    vect = apply_perspective(vect);
    vect = apply_zoom(vect, prog);
    vect = reposition(vect, prog);
    return vect;
}

void set_pixel(vector3D vect, program *prog) {
	int color;

	int i = ((int)vect.x + (int)vect.y * prog->width) * prog->bpp / 8;
	color = get_color(vect.z, prog);
	*(int *)(prog->img_data + i) = color;
}

void draw_line(vector3D vect1, vector3D vect2, program *prog) {
	vect1 = transform(vect1, prog);
	vect2 = transform(vect2, prog);
	int dx = abs((int)vect2.x - (int)vect1.x);
	int dy = abs((int)vect2.y - (int)vect1.y);
	int sx = (vect1.x < vect2.x) ? 1 : -1;
	int sy = (vect1.y < vect2.y) ? 1 : -1;
	int err = dx - dy;
	int e2;

	while ((int)vect1.x != (int)vect2.x || (int)vect1.y != (int)vect2.y) {
		set_pixel(vect1, prog);
		e2 = 2 * err;
		if (e2 > -dy) {
			err -= dy;
			vect1.x += sx;
		}
		if (e2 < dx) {
			err += dx;
			vect1.y += sy;
		}
	}
}

void draw_line_to_adjacent_points(vector3D vect, program *prog) {
	vector3D vect_next;
	if (vect.x < prog->map_width - 1) {
		vect_next.x = vect.x + 1;
		vect_next.y = vect.y;
		vect_next.z = prog->map[(int)vect.y][(int)vect.x + 1];
		draw_line(vect, vect_next, prog);
	}

	if (vect.y < prog->map_height - 1) {
		vect_next.x = vect.x;
		vect_next.y = vect.y + 1;
		vect_next.z = prog->map[(int)vect.y + 1][(int)vect.x];
		draw_line(vect, vect_next, prog);
	}
}

void draw_map(program *prog) {
	vector3D vect;

	vect.y = 0;
	while (vect.y < prog->map_height) {
		vect.x = 0;
		while (vect.x < prog->map_width) {
			vect.z = prog->map[(int)vect.y][(int)vect.x];
			set_pixel(transform(vect, prog), prog);
			draw_line_to_adjacent_points(vect, prog);
			vect.x++;
		}
		vect.y++;
	}
}
