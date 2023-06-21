#include "fdf.h"
#define ESC_KEY 53

int key_press(int keycode, void *param)
{
    // Handle key press events here
	if (keycode == ESC_KEY)
        exit(0);
    return (0);
}

void	make_line(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1, int color)
{
	float	change;

	change = (x1 - x0) / (y1 - y0);
	change = (x1 - x0) % (y1 - y0);
	while (x0 != x1 || y0 != y1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, color);
		x0++;
		if ((x1 - x0) % change_x_for_y == 0)
			y0++;
	}
	// int i = 0;
	// while (i != 10)
	// {
	// 	mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, color);
	// 	x0++;
	// 	i++;
	// }
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 800, "My first window");

    mlx_key_hook(win_ptr, key_press, (void *)0);
	make_line(mlx_ptr, win_ptr, 300, 300, 500, 400, 0xFFFFFF);

    mlx_loop(mlx_ptr);

    return (0);
}
