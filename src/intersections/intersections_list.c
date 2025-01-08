#include "minirt.h"

t_intersections	*new_inters_node(t_object *object, float *t)
{
	t_intersections *new;

	new = malloc(sizeof(t_intersections));
	new->object = object;
	// new->t = malloc(2 * sizeof(float));
	new->t[0] = t[0];
	new->t[1] = t[1];
	new->next = NULL;
	return (new);
}

t_intersections *last_inters_node(t_intersections *inters)
{
	if (!inters)
		return (NULL);
	while (inters)
	{
		if (!(inters->next))
			return (inters);
		inters = inters->next;
	}
	return (inters);
}

void add_intersect_list(t_ray *ray, t_object *object, float *t)
{
    t_intersections *last;
    t_intersections *new;

    new = new_inters_node(object, t);
    if (!new)
        return;
    if (ray->intersections)
    {
        last = last_inters_node(ray->intersections);
        last->next = new;
        new->prev = last;
    }
    else
        ray->intersections = new;
}
