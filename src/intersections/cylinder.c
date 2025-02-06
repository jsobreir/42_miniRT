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

int	hit_cylinder(t_object *cyl, t_ray *ray, t_ray *trans_ray, t_intersections **inters)
{
	float	a;
	float	b;
	float	c;
	float	i1;
	float	i2;
	int		num_inters;

	a = trans_ray->direction.x * trans_ray->direction.x + trans_ray->direction.z * trans_ray->direction.z;
	b = 2*(trans_ray->direction.x * ray->origin.x + trans_ray->direction.z * ray->origin.z);
	c = ray->origin.x * ray->origin.x + ray->origin.z * ray->origin.z;
	c -= cyl->radius * cyl->radius;
	if (b * b - 4 * a * c < 0)
		return (0);
	i1 = (-b * b - sqrtf(b * b - 4 * a * c))/(2 * a);
	i2 = (-b * b + sqrtf(b * b - 4 * a * c))/(2 * a);
	num_inters = check_intersections(i1, i2, inters, cyl, ray);
	return (num_inters);
}

int	cylinder_caps(t_ray *ray)
{
	t_point3		inters;
	t_intersections *intersection;
	t_object		*cyl;
	float			cap_max;
	float			cap_min;

	cyl = ray->intersections->object;
	intersection = ray->intersections;
	inters = point_on_vec3(intersection->t[0], ray);
	cap_max = cyl->position.y
	if (cyl->z < inters.z || cyl->z > inters.z)
	{
		caps.z
	}
}