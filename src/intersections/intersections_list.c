#include "minirt.h"

t_intersections	*new_inters_node(t_object *object, float *t, t_ray *ray)
{
	t_intersections	*new;

	new = malloc(sizeof(t_intersections));
	new->object = object;
	new->t[0] = t[0];
	new->t[1] = t[1];
	new->next = NULL;
	new->point = point_on_vec3(t[0], ray);
	return (new);
}

t_intersections	*last_inters_node(t_intersections *inters)
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

void	add_inter(t_intersections **inter, t_intersections *new,
		t_intersections *prev, float t[])
{
	t_intersections	*temp;

	temp = *inter;
	while (temp && t[0] > temp->t[0])
	{
		prev = temp;
		temp = temp->next;
	}
	if (!prev)
	{
		new->next = *inter;
		*inter = new;
	}
	else
	{
		prev->next = new;
		new->next = temp;
	}
}

t_intersections	*add_intersect_list(t_intersections **inter,
	t_object *obj, float *t, t_ray *ray)
{
	t_intersections	*new;
	t_intersections	*prev;
	t_intersections	*temp;

	new = new_inters_node(obj, t, ray);
	temp = *inter;
	prev = NULL;
	if (!new)
		return (NULL);
	if (!temp || temp->t[0] == INFINITY)
		return (*inter = new, new);
	add_inter(inter, new, prev, t);
	return (*inter);
}

void	free_t(t_intersections *intersections)
{
	t_intersections	*current;
	t_intersections	*temp;

	if (!intersections)
		return ;
	current = intersections;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}
