#include "minirt.h"

t_point3	translate(t_point3 point, t_vec3 trans)
{
	t_point3 new;
	new.x = point.x + trans.x;
	new.y = point.y + trans.y;
	new.z = point.z + trans.z;
	return (new);
}

t_point3	rotate(t_point3 point, double angl, char axis)
{
	t_point3 *new;
	new = NULL;
	if (axis == 'x')
	{
		(*new).x = point.x;
		(*new).y = (point.y * cos(angl)) - (sin(angl) * point.y);
		(*new).z = (sin(angl) * point.z) + (point.z * cos(angl));
	}
	else if (axis == 'y')
	{
		(*new).x = (sin(angl) * point.x) + (point.x * cos(angl));
		(*new).y = point.y;
		(*new).z = (-sin(angl) * point.z) + (cos(angl) * point.z);
	}
	else if (axis == 'z')
	{
		(*new).x = (sin(angl) * point.x) + (point.x * cos(angl));
		(*new).y = (sin(angl) * point.y) + (cos(angl) * point.y);
		(*new).z = point.z;
	}
	return (*new);
}

t_point3	scaling(t_point3 point, t_vec3 trans)
{
	t_point3 new;
	new.x = point.x * trans.x;
	new.y = point.y * trans.y;
	new.z = point.z * trans.z;
	return (new);
}
