/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:40:39 by wremy             #+#    #+#             */
/*   Updated: 2023/06/08 19:21:44 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libraries/minilibx_macos/mlx.h"
# include "libraries/get_next_line/get_next_line.h"
# include "libraries/Libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define NUM_KEYS 256

typedef struct s_program
{
	int		bpp;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		width;
	int		height;

	int		rotate_x;
	int		rotate_y;
	int		rotate_z;
	int		move_x;
	int		move_y;
	float	zoom;
	float	depth;

	int		map_width;
	int		map_height;
	int		**map;
}	t_program;

typedef struct s_vector3D {
	float	x;
	float	y;
	float	z;
}	t_vector3D;

int			get_map(char	*name_file, t_program *prog);
int			initialize_graphics_program(char *file_name, t_program *prog);
void		load_image(t_program *prog);
void		draw_map(t_program *prog);
t_vector3D	transform(t_vector3D vect, t_program *prog);
t_vector3D	rotate(t_vector3D vector, t_program *prog);
int			get_map_width(char	*name_file);
int			get_map_height(char	*name_file);
void		redraw(t_program *prog);
int			key_press(int keycode, t_program *prog);
int key_release(int keycode, t_program *prog);
#endif