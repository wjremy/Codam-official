/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:46:27 by wremy             #+#    #+#             */
/*   Updated: 2023/06/08 19:22:51 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

# define ESC_KEY 53

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define W 13
# define S 1
# define A 0
# define D 2
# define Q 12
# define E 14

# define PLUS 24
# define MINUS 27
# define P 35
# define O 31

void	handle_rotation(int keycode, t_program *prog)
{
	int	rotation_step;

	rotation_step = 4;
	if (keycode == S)
		prog->rotate_x += rotation_step;
	if (keycode == W)
		prog->rotate_x -= rotation_step;
	if (keycode == D)
		prog->rotate_y -= rotation_step;
	if (keycode == A)
		prog->rotate_y += rotation_step;
	if (keycode == E)
		prog->rotate_z += rotation_step;
	if (keycode == Q)
		prog->rotate_z -= rotation_step;
}

void	handle_zoom(int keycode, t_program *prog)
{
	float	zoom_step;
	float	depth_step;

	zoom_step = 1.1;
	depth_step = 1.1;
	if (keycode == PLUS)
		prog->zoom *= zoom_step;
	if (keycode == MINUS)
		prog->zoom /= zoom_step;
	if (keycode == P)
		prog->depth *= depth_step;
	if (keycode == O)
		prog->depth /= depth_step;
}

void	handle_move(int keycode, t_program *prog)
{
	int	move_step;

	move_step = 1;
	if (keycode == LEFT)
		prog->move_x -= move_step;
	if (keycode == RIGHT)
		prog->move_x += move_step;
	if (keycode == DOWN)
		prog->move_y += move_step;
	if (keycode == UP)
		prog->move_y -= move_step;
}

int key_press(int keycode, t_program *prog)
{
    if (keycode == ESC_KEY)
        exit(0);
	handle_rotation(keycode, prog);
	handle_zoom(keycode, prog);
	handle_move(keycode, prog);
	redraw(prog);
    return (0);
}


// void main_loop(t_program *prog)
// {
//     while (1)
//     {
//         handle_rotation(prog);
//         //handle_zoom(prog);
//         //handle_move(prog);
//         redraw(prog);
//     }
// }
