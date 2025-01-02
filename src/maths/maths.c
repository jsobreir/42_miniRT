#include "minirt.h"

t_vector add_vectors(t_vector *one, t_vector *two)
{
	t_vector new;

	new.x = one->x + two->x;
	new.y = one->y + two->y;
	new.z = one->z + two->z;
	return (new);
}

t_vector subtract_vectors(t_vector *one, t_vector *two)
{
	t_vector new;

	new.x = one->x - two->x;
	new.y = one->y - two->y;
	new.z = one->z - two->z;
	return (new);
}

t_vector multiply_vectors(t_vector *one, t_vector *two)
{
	t_vector new;

	new.x = one->x * two->x;
	new.y = one->y * two->y;
	new.z = one->z * two->z;
	return (new);
}

t_vector divide_vectors(t_vector *one, t_vector *two)
{
	t_vector new;

	new.x = one->x / two->x;
	new.y = one->y / two->y;
	new.z = one->z / two->z;
	return (new);
}