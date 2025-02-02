#include "minirt.h"

static void	ft_swap(float *a, float *b)
{
	float *temp;

	temp = a;
	*a = *b;
	*b = *temp;
}

int	hit_sphere(t_object *sphere, t_ray *ray, t_intersections **intersections)
{
	float	t1;
	float	t2;
	float	t[2];
	t_vec3 	oc;

	oc = subtract_vec3s(ray->origin, sphere->position);
	float a = dot_product(ray->direction, ray->direction);
	float b = 2 * dot_product(ray->direction, oc);
	float c = dot_product(oc, oc) - (sphere->radius*sphere->radius);
	float discriminant = b*b - 4*a*c;
	if (discriminant < 0)
		return (0);
	t1 = (-b - sqrtf(discriminant)) / (2 * a);
	t2 = (-b + sqrtf(discriminant)) / (2 * a);
	if (t1 > t2)
		ft_swap(&t1, &t2);
	if (t2 < 0)
		return (0);
	if (t1 < 0)
	{
		t[0] = t2;
		add_intersect_list(intersections, sphere, t);
		return (1);
	}
	t[0] = t1;
	t[1] = t2;
	add_intersect_list(intersections, sphere, t);
	return (2);
}

t_intersections *intersect(t_ray *ray, t_scene *world)
{
    t_object        *objects;

    objects = world->objects;
    while (objects && objects->type != NONE)
    {
        if (objects->type == SPHERE)
   			hit_sphere(objects, ray, &ray->intersections);
		objects = objects->next;
    }
    return (ray->intersections);
}
