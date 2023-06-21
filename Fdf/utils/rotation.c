/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:47:09 by wremy             #+#    #+#             */
/*   Updated: 2023/06/08 17:14:07 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	degree_to_radian(int degree)
{
	return (degree * M_PI / 180);
}

t_vector3D	rotate(t_vector3D vector, t_program *prog)
{
	float	rotate_x = degree_to_radian(prog->rotate_x);
	float	rotate_y = degree_to_radian(prog->rotate_y);
	float	rotate_z = degree_to_radian(prog->rotate_z);

	vector.z *= -1;

	float initial_y = vector.y;
	float initial_z = vector.z;

	vector.y = initial_y * cos(rotate_x) - initial_z * sin(rotate_x);
	vector.z = initial_y * sin(rotate_x) + initial_z * cos(rotate_x);

	float initial_x = vector.x;
	initial_z = vector.z;

	vector.x = initial_x * cos(rotate_y) + initial_z * sin(rotate_y);
	vector.z = -initial_x * sin(rotate_y) + initial_z * cos(rotate_y);

	initial_x = vector.x;
	initial_y = vector.y;

	vector.x = initial_x * cos(rotate_z) - initial_y * sin(rotate_z);
	vector.y = initial_x * sin(rotate_z) + initial_y * cos(rotate_z);

	return (vector);
}
