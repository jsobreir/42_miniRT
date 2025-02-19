#include "minirt.h"

t_intersections	*new_inters_node(t_object *object, float *t, t_ray *ray)
{
	t_intersections *new;

	new = malloc(sizeof(t_intersections));
	new->object = object;
	new->t[0] = t[0];
	new->t[1] = t[1];
	new->next = NULL;
	new->point = point_on_vec3(t[0], ray);
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

/*t_intersections *add_intersect_list(t_intersections **intersections, t_object *object, float *t, t_ray *ray)
{
    t_intersections *last;
    t_intersections *new;

    new = new_inters_node(object, t, ray);
    if (!new)
        return NULL;
    if (*intersections && (*intersections)->t[0] != INFINITY && (*intersections)->t[1] != INFINITY)
    {
        last = last_inters_node(*intersections);
        last->next = new;
    }
    else
		*intersections = new;
	return (*intersections);
}*/
t_intersections *add_intersect_list(t_intersections **intersections, t_object *object, float *t, t_ray *ray)
{
    t_intersections *new;
	t_intersections *temp;
	t_intersections *temp2;

	temp = *intersections;
    new = new_inters_node(object, t, ray);
	if (!new)
		return NULL;
	if (!temp || temp->t[0] == INFINITY || temp->t[1] == INFINITY)
	{
		*intersections = new;
		return (*intersections);
	}
	if (!temp->next)
	{
		if (t[0] > temp->t[0])
			temp->next = new;
		else
		{
			*intersections = new;
			new->next = temp;
		}
		return (*intersections);
	}
	while (temp)
	{
		if (!temp->next)
		{
			temp->next = new;
			break ;
		}
		if (t[0] > temp->t[0] && t[0] < temp->next->t[0])
		{
			temp2 = temp->next;
			new->next = temp2;
			temp->next = new;
			return (*intersections);
		}
		temp = temp->next;
	}
	return (*intersections);
}

void	free_intersections(t_intersections *intersections)
{
	t_intersections *current;
	t_intersections *temp;

	if (!intersections)
		return ;
	current = intersections;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	intersections = NULL;
}