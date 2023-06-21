#include "minilibx_macos/mlx.h"
#include <math.h>
#include <stdio.h>

// #ifndef M_PI 
// #define M_PI 3.1415926535 
// #endif

typedef struct
{
    float x;
    float y;
    float z;
} Point3D;

typedef struct
{
    Point3D point;
    Point3D rotated_point;
    float rotate_x;
    float rotate_y;
    float rotate_z;
    int bpp;
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    char *img_data;
    int width;
    int height;
} program;

// void draw_line(int x0, int y0, int x1, int y1, program *prog) {
//     int dx = abs(x1 - x0);
//     int dy = abs(y1 - y0);
//     int sx = (x0 < x1) ? 1 : -1;
//     int sy = (y0 < y1) ? 1 : -1;
//     int err = dx - dy;

//     while (1) {
//         set_pixel(x0, y0, prog->width, prog);
//         if (x0 == x1 && y0 == y1)
//             break;
//         int e2 = 2 * err;
//         if (e2 > -dy) {
//             err -= dy;
//             x0 += sx;
//         }
//         if (e2 < dx) {
//             err += dx;
//             y0 += sy;
//         }
//     }
// }


float degree_to_radian(int    degree)
{
    return(degree*M_PI/180);
}

void rotate(program *prog)
{
    float   rotate_x = degree_to_radian(prog->rotate_x);
    float   rotate_y = degree_to_radian(prog->rotate_y);
    float   rotate_z = degree_to_radian(prog->rotate_z);

    // Translate to the origin
    prog->point.x -= prog->width / 2;
    prog->point.y -= prog->height / 2;

    if (rotate_x != 0)
    {
        prog->rotated_point.y = prog->point.y * cos(rotate_x) - prog->point.z * sin(rotate_x);
        prog->rotated_point.z = prog->point.y * sin(rotate_x) + prog->point.z * cos(rotate_x);
    }
    if (rotate_y != 0)
    {
        prog->rotated_point.x = prog->point.x * cos(rotate_y) + prog->point.z * sin(rotate_y);
        prog->rotated_point.z = -prog->point.x * sin(rotate_y) + prog->point.z * cos(rotate_y);
    }
    if (rotate_z != 0)
    {
        prog->rotated_point.x = prog->point.x * cos(rotate_z) - prog->point.y * sin(rotate_z);
        prog->rotated_point.y = prog->point.x * sin(rotate_z) + prog->point.y * cos(rotate_z);
    }

    // Translate back to the original location
    prog->point.x += prog->width / 2;
    prog->point.y += prog->height / 2;
    prog->rotated_point.x += prog->width / 2;
    prog->rotated_point.y += prog->height / 2;
}


// void redraw(program *prog)
// {
//     char *img_data;
//     int size_line;
//     int endian;

//     rotate(prog);
//     // prog->img_data = mlx_get_data_addr(prog->img_ptr, &prog->bpp, &size_line, &endian);
//     // mlx_clear_window(prog->mlx_ptr, prog->win_ptr);
//     set_pixel(prog->rotated_point.x, prog->rotated_point.y, prog);
//     mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_ptr, 0, 0);
// }

#define ESC_KEY 53
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
int key_press(int keycode, program *prog)
{
    int rotation_step = 10;

    if (keycode == ESC_KEY)
        exit(0);
    if (keycode == UP)
        prog->rotate_x += rotation_step;
    if (keycode == DOWN)
        prog->rotate_x -= rotation_step;
    if (keycode == LEFT)
        prog->rotate_y -= rotation_step;
    if (keycode == RIGHT)
        prog->rotate_y += rotation_step;
    if (keycode == 0)
        prog->rotate_z += rotation_step;
    if (keycode == 2)
        prog->rotate_z -= rotation_step;
    //redraw(prog);
    return (0);
}

program initialize_graphics_program(void)
{
    program prog;
    int size_line;
    int endian;

    prog.width = 800;
    prog.height = 600;

    prog.rotate_x = 0;
    prog.rotate_y = 0;
    prog.rotate_z = 0;

    prog.mlx_ptr = mlx_init();
    prog.win_ptr = mlx_new_window(prog.mlx_ptr, prog.width, prog.height, "Image Example");
    prog.img_ptr = mlx_new_image(prog.mlx_ptr, prog.width, prog.height);
    prog.img_data = mlx_get_data_addr(prog.img_ptr, &prog.bpp, &size_line, &endian);

    return(prog);
}

void    load_image(program *prog)
{
    mlx_key_hook(prog->win_ptr, key_press, &prog);
    //rotate(point1, prog.rotate_x, prog.rotate_y, prog.rotate_z);
    mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_ptr, 0, 0);
    mlx_loop(prog->mlx_ptr);
}