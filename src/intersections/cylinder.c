#include "minirt.h"

int	cylinder_cap_plane_check(t_ray *ray, float cap_y, float	t[2])
{
	t_point3	point;

	if (t[0] > t[1])
		ft_swap(&t[0], &t[1]);
	if (t[1] < 0)
		return (0);
	if (t[0] < 0)
		t[0] = t[1];
	point = point_on_vec3(t[0], ray);
	if (point.y <= cap_y && point.y >= -cap_y)
		return (1);
	return (0);
}

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
	return (-1);
}

// static int	cylinder_caps(t_ray *ray, t_object *cyl, float cap_y)
// {
// 	if (cylinder_cap_intersection(ray, cyl, cap_y) >= 0)
// 		return (1);
// 	if (cylinder_cap_intersection(ray, cyl, -cap_y) >= 0)
// 		return (1);
// 	return (0);
// }

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
	(void)ray;

	a = trans_ray->direction.x * trans_ray->direction.x + trans_ray->direction.z * trans_ray->direction.z;
	b = 2 * (trans_ray->origin.x * trans_ray->direction.x + trans_ray->origin.z * trans_ray->direction.z);
	c = trans_ray->origin.x * trans_ray->origin.x + trans_ray->origin.z * trans_ray->origin.z - cyl->radius * cyl->radius;
	if (a == 0)
		return (1);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (0);
	i[0] = (-b - sqrtf(discriminant)) / (2 * a);
	i[1] = (-b + sqrtf(discriminant)) / (2 * a);
	if (!cylinder_cap_plane_check(trans_ray, cyl->height / 2, i))
		return (0);
	i[2] = cylinder_cap_intersection(ray, cyl, cyl->height / 2);
	i[3] = cylinder_cap_intersection(ray, cyl, -cyl->height / 2);
	return (check_cyl_intersections(i, inters, cyl, trans_ray));
}
