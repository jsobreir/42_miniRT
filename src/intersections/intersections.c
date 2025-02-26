#include "minirt.h"

void	ft_swap(float *a, float *b)
{
	float *temp;

	temp = a;
	*a = *b;
	*b = *temp;
}

int	check_intersections(float t1[], t_intersections **inter, t_object *obj, t_ray *ray)
{
	float	t[2];

	if (t1[0] > t1[1])
		ft_swap(&t1[0], &t1[1]);
	if (t1[1] < 0)
		return (0);
	if (t1[0] < 0)
	{
		t[0] = t1[1];
		add_intersect_list(inter, obj, t, ray);
		return (1);
	}
	t[0] = t1[0];
	t[1] = t1[1];
	add_intersect_list(inter, obj, t, ray);
	return (2);
}

int	hit_sphere(t_object *sphere, t_ray *ray, t_ray *trans_ray, t_intersections **intersections)
{
	float	t1[2];
	t_vec3 	oc;
	int		check_int;

	oc = trans_ray->origin;
	float a = dot_product(trans_ray->direction, trans_ray->direction);
	float b = 2 * dot_product(trans_ray->direction, oc);
	float c = dot_product(oc, oc) - (sphere->radius*sphere->radius);
	float discriminant = b*b - 4*a*c;
	if (discriminant < 0)
		return (0);
	t1[0] = (-b - sqrtf(discriminant)) / (2 * a);
	t1[1] = (-b + sqrtf(discriminant)) / (2 * a);
	check_int = check_intersections(t1, intersections, sphere, ray);
	return (check_int);
}

t_intersections *intersect(t_ray *ray, t_scene *world)
{
    t_object        *objects;
	t_ray			*t_ray;

    objects = world->objects;
    while (objects && objects->type != NONE)
    {
		t_ray = transform_ray(objects, world, ray);
        if (objects->type == SPHERE)
   			hit_sphere(objects, ray, t_ray, &ray->intersections);
		else if (objects->type == CYLINDER)
			hit_cylinder(objects, t_ray,  &ray->intersections, ray);
		else if (objects->type == PLANE)
			hit_plane(objects, ray, t_ray,  &ray->intersections);
		free(t_ray);
		objects = objects->next;
    }
    return (ray->intersections);
}

t_ray	*transform_ray(t_object *obj, t_scene *scene, t_ray *ray)
{
	t_matrix	*trans = NULL;
	t_matrix	*rot_transform;
	t_matrix	*temp;
	t_ray		*new_ray;

	new_ray = calloc(1, sizeof(t_ray));
	if (!obj->cached_transform)
	{
		trans = translate(obj->position.x, obj->position.y, obj->position.z);
		if (obj->type == SPHERE)
			rot_transform = mtx_identity(4,4);
		else
			rot_transform = rotation_matrix(obj);
		temp = mtx_multiply(*trans, *rot_transform);
		obj->cached_transform = mtx_inverse(scene, temp);
		mtx_free(temp);
		mtx_free(trans);
		mtx_free(rot_transform);
	}
	new_ray->origin = mtx_mult_point3(obj->cached_transform, &ray->origin);
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
	t_matrix	*ident;
	float		theta;

	orient = obj->orientation;
	if (orient.x == 0 && orient.y != 0 && orient.z == 0)
		return (mtx_identity(4,4));
	fill_vec3(&world_up, 0, 1, 0);
	rotation_axis = cross_product(orient, world_up);
	theta = acosf(dot_product(orient, world_up) / magnitude(orient));
	skew_sym = mtx_skew_symmetric(rotation_axis);
	skew_sym = mtx_mult_by_float(skew_sym, sinf(theta));
	skew_sym_squared = mtx_skew_symmetric_squared(rotation_axis);
	skew_sym_squared = mtx_mult_by_float(skew_sym_squared, 1 - cosf(theta));
	ident = mtx_identity(4, 4);
	temp = mtx_add(*ident, *skew_sym);
	mtx_free(ident);
	mtx_free(skew_sym);
	rotation = mtx_add(*temp, *skew_sym_squared);
	mtx_free(skew_sym_squared);
	mtx_free(temp);
	rotation->matrix[3][3] = 1.0;
	return (rotation);
}
