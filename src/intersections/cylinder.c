#include "minirt.h"

// int	hit_cylinder(t_object *cyl, t_ray *ray, t_intersections **inters)
// {
// 	t_vec3	cyl_x_axis;
// 	t_vec3	cyl_y_axis;
// 	t_vec3	cyl_z_axis;
// 	float	d;
// 	t_vec3	cyl_base;
// 	t_vec3	oc_or;
// 	float	beta;
// 	float	gamma;
// 	float	r2_minus_d2;
// 	float	solve;

// 	cyl_x_axis = cross_product(cyl->orientation, ray->direction);
// 	normalize(&cyl_x_axis);
// 	cyl_z_axis = cyl->orientation;
// 	normalize(&cyl_z_axis);
// 	cyl_y_axis = cross_product(cyl_z_axis, cyl_x_axis);
// 	normalize(&cyl_y_axis);
// 	cyl_base = subtract_vec3s(cyl->position, mult_byscalar(&cyl_z_axis, cyl->height / 2));
// 	oc_or = subtract_vec3s(ray->origin, cyl_base);
// 	d = dot_product(oc_or, cyl_x_axis);
// 	normalize(&ray->direction);
// 	beta = dot_product(ray->direction, cyl_y_axis);
// 	gamma = dot_product(ray->direction, cyl_z_axis);
// 	r2_minus_d2 = cyl->radius * cyl->radius - d * d;
// 	solve = r2_minus_d2/(beta * beta);
// 	if (solve >= 0 && solve != INFINITY)
// 	{
// 		solve = sqrtf(r2_minus_d2/(beta * beta));
// 		return (check_intersections(solve, -solve, inters, cyl));
// 	}
// 	else
// 		return (0);
// }

static float	cylinder_cap_intersection(t_ray *ray, t_object *cyl, float cap_y)
{
	float		t;
	t_point3	point;

	if (ray->direction.y == 0)
		return (0);
	t = (cap_y - ray->origin.y) / ray->direction.y;
	point = point_on_vec3(t, ray);
	if (point.x * point.x + point.z * point.z <= cyl->radius * cyl->radius)
		return (t);
	return (-INFINITY);
}

static float	cylinder_caps(t_ray *ray, t_object *cyl, float cap_y)
{
	float	i;
	i = cylinder_cap_intersection(ray, cyl, cap_y);
	if (i != -INFINITY)
		return (i);
	i = cylinder_cap_intersection(ray, cyl, -cap_y);
	if (i != -INFINITY)
		return (i);
	return (-INFINITY);
}

int	check_cyl_intersections(float i[4], t_intersections **intersections, t_object *cyl, t_ray *ray)
{
	float	t[2];

	t[0] = i[0];
	t[1] = i[1];
	if (i[2] > 0 && i[2] < t[0])
		t[0] = i[2];
	else if (i[2] > 0 && i[2] < t[1])
		t[1] = i[2];
	if (i[3] > 0 && i[3] < t[0])
		t[0] = i[3];
	else if (i[3] > 0 && i[3] < t[1])
		t[1] = i[3];
	return (check_intersections(t[0], t[1], intersections, cyl, ray));	
}

int	hit_cylinder(t_object *cyl, t_ray *ray, t_ray *trans_ray, t_intersections **inters)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float	i[4];
	int		num_inters;
	(void)ray;

	a = trans_ray->direction.x * trans_ray->direction.x + trans_ray->direction.z * trans_ray->direction.z;
	b = 2 * (trans_ray->origin.x * trans_ray->direction.x + trans_ray->origin.z * trans_ray->direction.z);
	c = trans_ray->origin.x * trans_ray->origin.x + trans_ray->origin.z * trans_ray->origin.z - cyl->radius * cyl->radius;
	if (a == 0)
	{
		i[0] = -1;
		i[1] = -1;
		i[2] = cylinder_caps(ray, cyl, cyl->height / 2);
		i[3] = cylinder_caps(ray, cyl, -cyl->height / 2);
		num_inters = check_cyl_intersections(i, inters, cyl, trans_ray);
		return (num_inters);
	}
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (0);
	i[0] = (-b - sqrtf(discriminant)) / (2 * a);
	i[1] = (-b + sqrtf(discriminant)) / (2 * a);
	i[2] = cylinder_caps(ray, cyl, cyl->height / 2);
	i[3] = cylinder_caps(ray, cyl, -cyl->height / 2);
	num_inters = check_cyl_intersections(i, inters, cyl, trans_ray);
	return (num_inters);
}
