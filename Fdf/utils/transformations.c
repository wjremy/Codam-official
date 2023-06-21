#include "../fdf.h"

t_vector3D centralize(t_vector3D vect, t_program *prog) {
    vect.x -= (prog->map_width - 1) / 2.0;
    vect.y -= (prog->map_height - 1) / 2.0;
    return vect;
}

t_vector3D apply_perspective(t_vector3D vect) {
    if (vect.z != 0) {
        vect.x /= 1 + 0.001 *vect.z;
        vect.y /= 1 + 0.001 *vect.z;
    }
    return vect;
}

t_vector3D apply_zoom(t_vector3D vect, t_program *prog) {
    vect.x *= prog->zoom;
    vect.y *= prog->zoom;
    vect.z *= prog->zoom;
    return vect;
}

t_vector3D reposition(t_vector3D vect, t_program *prog) {
    vect.x += prog->width / 2 + prog->move_x * prog->zoom;
    vect.y += prog->height / 2 + prog->move_y * prog->zoom;
    return vect;
}

t_vector3D transform(t_vector3D vect, t_program *prog) {
    vect.z *= prog->depth;
    vect = centralize(vect, prog);
    vect = apply_zoom(vect, prog);
    vect = rotate(vect, prog);
    vect = apply_perspective(vect);
    vect = reposition(vect, prog);
    return vect;
}