#include "minirt.h"

static void	ft_swap(float *a, float *b)
{
	float *temp;

	temp = a;
	*a = *b;
	*b = *temp;
}

int	check_intersections(float t1, float t2, t_intersections **intersections, t_object *object)
{
	float	t[2];

	if (t1 > t2)
		ft_swap(&t1, &t2);
	if (t2 < 0)
		return (0);
	if (t1 < 0)
	{
		t[0] = t2;
		add_intersect_list(intersections, object, t);
		return (1);
	}
	t[0] = t1;
	t[1] = t2;
	add_intersect_list(intersections, object, t);
	return (2);
}

int	hit_sphere(t_object *sphere, t_ray *ray, t_intersections **intersections)
{
	float	t1;
	float	t2;
	t_vec3 	oc;

	oc = subtract_vec3s(ray->origin, sphere->position);
	float a = dot_product(ray->direction, ray->direction);
	float b = 2 * dot_product(ray->direction, oc);
	float c = dot_product(oc, oc) - 1;
	float discriminant = b*b - 4*a*c;
	if (discriminant < 0)
		return (0);
	t1 = (-b - sqrtf(discriminant)) / (2 * a);
	t2 = (-b + sqrtf(discriminant)) / (2 * a);
	return (check_intersections(t1, t2, intersections, sphere));
}

t_intersections *intersect(t_ray *ray, t_scene *world)
{
    t_object        *objects;

    objects = world->objects;
    while (objects && objects->type != NONE)
    {
        if (objects->type == SPHERE)
   			hit_sphere(objects, ray, &ray->intersections);
		else if (objects->type == CYLINDER)
			hit_cylinder(objects, ray, &ray->intersections);
		objects = objects->next;
    }
    return (ray->intersections);
}

// t_matrix	*find_trans_matrix(t_object *obj, t_scene *scene)
// {
// 	t_matrix	*trans;
// 	t_matrix	*temp;
// 	t_matrix	*translate_mtx;
// 	float		angle_rad;

// 	temp = mtx_identity(3, 3);
// 	translate_mtx = translate(obj->position.x, obj->position.y, obj->position.z);
// 	trans = mtx_multiply(*translate_mtx, *temp);
// 	mtx_free(trans);
// 	mtx_free(translate_mtx);
// 	angle_rad = acosf(dot_product(obj->orientation));
// 	mtx_rotate_x(trans);
// }
