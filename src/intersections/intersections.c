#include "minirt.h"

int	hit_sphere(t_object *sphere, t_ray *ray, t_intersections **intersections)
{
	float	i1;
	float	i2;
	float	t[2];
	int		ret;
	t_vec3 	oc;

	oc = ray->origin;
	//oc = translate(ray->origin, sphere->position); // assumimos que a esfera esta no centro,
	// sempre que fizer estes calculos vou fazer transformacoes com matrizes
    float a = dot_product(ray->direction, ray->direction);
    float b = 2 * dot_product(ray->direction, oc);
    float c = dot_product(oc, oc) - sphere->radius*sphere->radius;
    float discriminant = b*b - 4*a*c;
	if (discriminant < 0)
		return (0);
	i1 = (-b - sqrtf(discriminant)) / (2 * a);
	i2 = (-b + sqrtf(discriminant)) / (2 * a);
	if (i1 < 0 && i2 > 0)
	{
		t[0] = i2;
		t[1] = i1;
		ret = 1;
	}
	else if (i2 < 0 && i1 > 0)
	{
		t[0] = i1;
		t[1] = i2;
		ret = 1;
	}
	else if (i1 < 0 && i2 < 0)
	{
		if (i1 < i2)
		{
			t[0] = i1;
			t[1] = i2;
		}
		else
		{
			t[0] = i1;
			t[1] = i2;	
		}
		ret = 0;	
	}
	else if (i1 > i2)
	{
		t[0] = i2;
		t[1] = i1;
		ret = 2;
	}
	else
	{
		t[0] = i1;
		t[1] = i2;
		ret = 2;
	}
	return (add_intersect_list(intersections, sphere, t), ret);
}

t_intersections *intersect(t_ray *ray, t_scene *world)
{
    t_object        *objects;

    objects = world->objects;

    while (objects)
    {
        if (objects->type == SPHERE)
   			hit_sphere(objects, ray, &ray->intersections);
		objects = objects->next;
    }
    return (ray->intersections);
}
