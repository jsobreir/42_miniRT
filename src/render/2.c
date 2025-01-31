#include "minirt.h"

//apagar depois do parser estar pronto
static t_object *init_sphere(t_object *sphere)
{
	sphere->type = SPHERE;
	sphere->radius = 5;
	sphere->position.x = 0.0;
	sphere->position.y = 0.0;
	sphere->position.z = 0.0;
	sphere->rgb.x = 1;
	sphere->rgb.y = 0;
	sphere->rgb.z = 0;
	return (sphere);
}

static t_ray* generate_ray(int x, int y, t_camera *camera, t_ray *ray)
{
	t_vec3	*viewport_u;
	t_vec3	*viewport_v;
	t_vec3 pixel_delta_u;
	t_vec3 pixel_delta_v;
	t_vec3 viewport_upper_left;
	t_vec3	viewport_u_divided;
	t_vec3	viewport_v_divided;

	viewport_u->x = camera->viewport_width;
	viewport_u->y = 0;
	viewport_u->z = 0;
	viewport_v->x = 0;
	viewport_v->y = -camera->viewport_height;
	viewport_v->z = 0;
	pixel_delta_u = mult_byscalar(viewport_u, 1/WIDTH);
	pixel_delta_v = mult_byscalar(viewport_v, 1/HEIGHT);

	viewport_upper_left = subtract_vec3s(camera->position, camera->orientation);
	viewport_u_divided = mult_byscalar(viewport_u, 0.5);
	viewport_v_divided = mult_byscalar(viewport_v, 0.5);
	viewport_upper_left = subtract_vec3s(viewport_upper_left, viewport_u_divided);
	viewport_upper_left = subtract_vec3s(viewport_upper_left, viewport_v_divided);
    t_vec3	pix00;
	pix00.x = viewport_upper_left.x + 0.5 * (pixel_delta_u.x + pixel_delta_v.x);
	pix00.y = viewport_upper_left.y + 0.5 * (pixel_delta_u.y + pixel_delta_v.y);
	pix00.z = viewport_upper_left.z + 0.5 * (pixel_delta_u.z + pixel_delta_v.z);

	return ray;
}

int hit_sphere(t_object *sphere, t_ray *ray)
{
	// IST pagina 7
	t_vec3 oc;  // vetor entre camera e esfera?
	oc.x = - sphere->position.x;
	oc.y = - sphere->position.y;
	oc.z = - sphere->position.z;
    float a = dot_product(ray->direction, ray->direction);
    float b = -2 * dot_product(ray->direction, oc);
    float c = dot_product(oc, oc) - sphere->radius*sphere->radius;
    float discriminant = b*b - 4*a*c;
	// printf("%f\n", discriminant);
    return (discriminant > 0);
}

int make_sphere(int x, int y, t_camera *camera)
{
	t_object sphere;
	t_ray ray;

	init_sphere(&sphere);
	generate_ray(x, y, camera, &ray);
	if (hit_sphere(&sphere, &ray))
		return (0x89CFF0);
	else
		return (0x000000);
}
