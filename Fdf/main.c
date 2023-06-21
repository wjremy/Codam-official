/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:04:03 by wremy             #+#    #+#             */
/*   Updated: 2023/06/07 17:06:36 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	int			**map;
	t_program	prog;

	//argv[1] = "maps/map.fdf";
	if (initialize_graphics_program(argv[1], &prog) == -1)
		return (-1);
	if (get_map(argv[1], &prog) == -1)
		return (-1);
	draw_map(&prog);
	load_image(&prog);
}
