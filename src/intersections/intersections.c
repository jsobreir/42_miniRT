#include "minirt.h"

static void	ft_swap(float *a, float *b)
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

	// oc = subtract_vec3s(ray->origin, sphere->position);
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
		{
			hit_cylinder(objects, ray, transform_ray(objects, world, ray),  &ray->intersections);
			// printf("%f and %f\n", ray->intersections->t[0], ray->intersections->t[1]);
		}
		objects = objects->next;
    }
    return (ray->intersections);
}

t_ray	*transform_ray(t_object *obj, t_scene *scene, t_ray *ray)
{
	t_matrix	*trans = NULL;
	t_ray		*new_ray = calloc(1, sizeof(t_ray));

	if (!obj->cached_transform || !obj->cached_rot_transform)
	{
		printf("=====Object=====\n");
		printf("position: x = %f, y = %f, z = %f\n", obj->position.x, obj->position.y, obj->position.z);
		printf("orientation: x = %f, y = %f, z = %f\n", obj->orientation.x, obj->orientation.y, obj->orientation.z);
		trans = translate(obj->position.x, obj->position.y, obj->position.z);
		printf("trans:\n");
		mtx_print(trans);
		if (obj->type == SPHERE)
			obj->cached_rot_transform = mtx_identity(4,4);
		else
			obj->cached_rot_transform = rotation_matrix(obj);
		obj->cached_transform = mtx_multiply(*obj->cached_rot_transform, *trans);
		obj->cached_transform = mtx_inverse(scene, obj->cached_transform);
		printf("rotation:\n");
		mtx_print(obj->cached_rot_transform);
		printf("trans final:\n");
		mtx_print(obj->cached_transform);
		printf("\n");
		free(trans);
	}
	new_ray->origin = mtx_mult_point3(obj->cached_transform, &ray->origin);
	// ray->direction = mtx_mult_vec3(obj->cached_rot_transform, &ray->direction);
	new_ray->intersections = NULL;
	new_ray->direction = mtx_mult_vec3(obj->cached_transform, &ray->direction);
	return (new_ray);
}

t_matrix	*execute_rot_z(t_vec3 *orient, t_matrix *rotation)
{
	t_matrix	*rot_z;

	rot_z = mtx_identity(4, 4);
	mtx_rotate_x(rot_z, orient->z * M_PI / 2);
	if (orient->x || orient->y)
		rotation = mtx_multiply(*rotation, *rot_z);
	else
	{
		mtx_free(rotation);
		rotation = rot_z;
	}
	return (rotation);
}

t_matrix	*execute_rot_y(t_vec3 *orient, t_matrix *rotation)
{
	t_matrix	*rot_y;

	rot_y = mtx_identity(4, 4);
	mtx_rotate_y(rot_y, orient->y * M_PI / 2);
	if (orient->x)
		rotation = mtx_multiply(*rotation, *rot_y);
	else
	{
		mtx_free(rotation);
		rotation = rot_y;
	}
	return (rotation);
}


t_matrix	*rotation_matrix(t_object *obj)
{
	t_matrix	*rotation;

	rotation = mtx_identity(4, 4);
	if (obj->orientation.x)
		mtx_rotate_z(rotation, obj->orientation.x * M_PI / 2);
	if (obj->orientation.y)
		rotation = execute_rot_y(&obj->orientation, rotation);
	if (obj->orientation.z)
		rotation = execute_rot_z(&obj->orientation, rotation);
	return (rotation);
}

// t_matrix	*rotation_matrix(t_object *obj)
// {
// 	t_vec3		up;
// 	t_vec3		forward;
// 	t_vec3		right;
// 	t_vec3		world_up;
// 	t_matrix	*trans;

// 	forward = obj->orientation;

// 	if (fabs(forward.y) > 0.9999)
// 		return (mtx_identity(4, 4));
// 	else
// 		fill_vec3(&world_up, 0, 1, 0);
// 	right = cross_product(forward, world_up);
// 	right = normalize(&right);
// 	up = cross_product(right, forward);
// 	up = normalize(&up);
// 	trans = new_mtx(4,4);
// 	trans->matrix[0][0] = right.x;
// 	trans->matrix[0][1] = right.y;
// 	trans->matrix[0][2] = right.z;
// 	trans->matrix[0][3] = 0;
// 	trans->matrix[1][0] = up.x;
// 	trans->matrix[1][1] = up.y;
// 	trans->matrix[1][2] = up.z;
// 	trans->matrix[1][3] = 0;
// 	trans->matrix[2][0] = forward.x;
// 	trans->matrix[2][1] = forward.y;
// 	trans->matrix[2][2] = forward.z;
// 	trans->matrix[2][3] = 0;
// 	trans->matrix[3][0] = 0;
// 	trans->matrix[3][1] = 0;
// 	trans->matrix[3][2] = 0;
// 	trans->matrix[3][3] = 1;
// 	return (trans);
// }


// int	check_obj_transform(t_object *obj)
// {
// 	t_point3	p;
// 	t_vec3		o;
// 	int			ret;

// 	p = obj->position;
// 	o = obj->orientation;
// 	ret = 0;
// 	if (p.x != 0 || p.y != 0 || p.z != 0)
// 		ret++;
// 	if (obj->type != SPHERE && (o.x != 0 || o.y != 0 || o.z != 1))
// 		ret++;
// 	return (ret);
// }
