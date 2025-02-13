#include "minirt.h"

void	ft_swap(float *a, float *b)
{
	float *temp;

	temp = a;
	*a = *b;
	*b = *temp;
}

int	check_intersections(float t1, float t2, t_intersections **intersections, t_object *object, t_ray *ray)
{
	float	t[2];

	if (t1 > t2)
		ft_swap(&t1, &t2);
	if (t2 < 0)
		return (0);
	if (t1 < 0)
	{
		t[0] = t2;
		add_intersect_list(intersections, object, t, ray);
		return (1);
	}
	t[0] = t1;
	t[1] = t2;
	add_intersect_list(intersections, object, t, ray);
	return (2);
}

int	hit_sphere(t_object *sphere, t_ray *ray, t_ray *trans_ray, t_intersections **intersections)
{
	float	t1;
	float	t2;
	t_vec3 	oc;
	int		check_int;

	oc = trans_ray->origin;
	float a = dot_product(trans_ray->direction, trans_ray->direction);
	float b = 2 * dot_product(trans_ray->direction, oc);
	float c = dot_product(oc, oc) - (sphere->radius*sphere->radius);
	float discriminant = b*b - 4*a*c;
	if (discriminant < 0)
		return (0);
	t1 = (-b - sqrtf(discriminant)) / (2 * a);
	t2 = (-b + sqrtf(discriminant)) / (2 * a);
	check_int = check_intersections(t1, t2, intersections, sphere, ray);
	return (check_int);
}

t_intersections *intersect(t_ray *ray, t_scene *world)
{
    t_object        *objects;

    objects = world->objects;
    while (objects && objects->type != NONE)
    {
        if (objects->type == SPHERE)
   			hit_sphere(objects, ray, transform_ray(objects, world, ray), &ray->intersections);
		else if (objects->type == CYLINDER)
			hit_cylinder(objects, transform_ray(objects, world, ray),  &ray->intersections);
		else if (objects->type == PLANE)
			hit_plane(objects, ray, transform_ray(objects, world, ray),  &ray->intersections);
		objects = objects->next;
    }
    return (ray->intersections);
}

t_ray	*transform_ray(t_object *obj, t_scene *scene, t_ray *ray)
{
	t_matrix	*trans = NULL;
	t_matrix	*rot_transform;
	t_matrix	*temp;
	t_ray		*new_ray = calloc(1, sizeof(t_ray));

	if (!obj->cached_transform)
	{
		// printf("=====Object=====\n");
		// printf("position: x = %f, y = %f, z = %f\n", obj->position.x, obj->position.y, obj->position.z);
		// printf("orientation: x = %f, y = %f, z = %f\n", obj->orientation.x, obj->orientation.y, obj->orientation.z);
		trans = translate(obj->position.x, obj->position.y, obj->position.z);
		// printf("trans:\n");
		// mtx_print(trans);
		if (obj->type == SPHERE)
			rot_transform = mtx_identity(4,4);
		else
			rot_transform = rotation_matrix(obj);
		temp = mtx_multiply(*trans, *rot_transform);
		obj->cached_transform = mtx_inverse(scene, temp);
		// printf("rotation:\n");
		// mtx_print(rot_transform);
		// printf("trans final:\n");
		// mtx_print(obj->cached_transform);
		// printf("\n");
		// free(temp);
		free(trans);
		// free(rot_transform);
	}
	new_ray->origin = mtx_mult_point3(obj->cached_transform, &ray->origin);
	// ray->direction = mtx_mult_vec3(rot_transform, &ray->direction);
	new_ray->intersections = NULL;
	new_ray->direction = mtx_mult_vec3(obj->cached_transform, &ray->direction);
	return (new_ray);
}

t_matrix	*rotation_matrix(t_object *obj)
{
	t_vec3		world_up;
	t_vec3		rotation_axis;
	t_vec3		orient;
	t_matrix	*skew_sym;
	t_matrix	*skew_sym_squared;
	t_matrix	*rotation;
	t_matrix	*temp;
	float		theta;

	orient = obj->orientation;
	// if (orient.x == 0 && orient.y != 0 && orient.z == 0)
	// 	return (mtx_identity(4,4));
	// if (orient.x == 0 && orient.y == -1 && orient.z == 0)
	// {
	// 	rotation = mtx_identity(4, 4);
	// 	return (mtx_rotate_x(rotation, M_PI), rotation);
	// }
	fill_vec3(&world_up, 0, 1, 0);
	rotation_axis = cross_product(orient, world_up);
	theta = acosf(dot_product(orient, world_up) / magnitude(orient));
	skew_sym = mtx_skew_symmetric(rotation_axis);
	skew_sym = mtx_mult_by_float(skew_sym, sinf(theta));
	skew_sym_squared = mtx_skew_symmetric_squared(rotation_axis);
	skew_sym_squared = mtx_mult_by_float(skew_sym_squared, 1 - cosf(theta));
	temp = mtx_add(*mtx_identity(4, 4), *skew_sym);
	rotation = mtx_add(*temp, *skew_sym_squared);
	mtx_free(temp);
	mtx_free(skew_sym);
	mtx_free(skew_sym_squared);
	mtx_print(rotation);
	return (rotation);
}
