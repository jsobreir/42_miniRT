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

	a = trans_ray->direction.x * trans_ray->direction.x + trans_ray->direction.y * trans_ray->direction.y;
	b = 2*(trans_ray->direction.x * ray->origin.x + trans_ray->direction.y * ray->origin.y);
	c = ray->origin.x * ray->origin.x + ray->origin.y * ray->origin.y;
	c -= cyl->radius * cyl->radius;
	if (b * b - 4 * a * c < 0)
		return (0);
	i1 = (-b*b - sqrtf(b * b - 4 * a * c))/(2 * a);
	i2 = (-b*b + sqrtf(b * b - 4 * a * c))/(2 * a);
	return (check_intersections(i1, i2, inters, cyl, ray));
}

int	hit_plane(t_object *plane, t_ray *ray, t_intersections **inter)
{
	float i;
	float d;
	t_vec3 normal = normalize(&plane->orientation);
	t_vec3 point = plane->position;
	float numerator;
	float denominator;

	d = -(normal.x * point.x + normal.y * point.y + normal.z * point.z);
	denominator = normal.x * ray->direction.x + normal.y * ray->direction.y + normal.z * ray->direction.z;
	if (fabs(denominator) < EPSILON)
		return (0);
	numerator = d - (normal.x * ray->origin.x + normal.y * ray->origin.y + normal.z * ray->origin.z);
	i = numerator / denominator;
	return (check_intersections(i, i, inter, plane, ray));
}

int	hit_sphere(t_object *sphere, t_ray *ray, t_intersections **intersections)
{
	float	t1;
	float	t2;
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
	return (check_intersections(t1, t2, intersections, sphere, ray));
}
