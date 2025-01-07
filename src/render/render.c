#include "minirt.h"

//apagar depois do parser estar pronto
static t_object *init_sphere(t_object *sphere)
{
	sphere->type = SPHERE;
	sphere->radius = 5;
	sphere->position.x = 0.0;
	sphere->position.y = 0.0;
	sphere->position.z = 0.0;
	sphere->rgb.x = 1;
	sphere->rgb.y = 0;
	sphere->rgb.z = 0;
	return (sphere);
}

static t_ray* generate_ray(int x, int y, t_camera *camera, t_ray *ray)
{
    ray->origin = camera->position;
	float viewport_width;
	float viewport_height;
    
    // Calculate camera basis vectors
    t_vec3 forward = camera->orientation;  // Already normalized
    t_vec3 right, up;
    
    // Calculate right vector (cross product of forward and world-up)
    t_vec3 world_up;
	world_up.x = 0;
	world_up.y = 1;
	world_up.z = 0;
    right = cross_product(forward, world_up);
    right = normalize(&right);
    
    // Calculate up vector
    up = cross_product(right, forward);
    up = normalize(&up);
    
    // Calculate viewport dimensions
    float fov = camera->fov * (PI / 180.0);
	if (ASPECT_RATIO >= 1)
	{
		viewport_width = 2 * tan(fov / 2.0f);
		viewport_height = viewport_width * ASPECT_RATIO;	
	}
	else
	{
		viewport_height = 2 * tan(fov / 2.0f);
		viewport_width = viewport_height * ASPECT_RATIO;
	}
    // Convert pixel coordinates to viewport coordinates
    // float px = (((2.0f * (float)x) / WIDTH) - 1.0f) * viewport_width *0.5;
    // float py = (1.0f - ((2.0f * (float)y) / HEIGHT)) * viewport_height *0.5;
	float pixel_size = viewport_width / WIDTH;
	float px, py;
	px = (x + 0.5) * pixel_size;
	py = (y + 0.5) * pixel_size;

    // Calculate ray direction using camera basis vectors
    t_vec3 direction;
    direction.x = px * right.x + py * up.x + forward.x;
    direction.y = px * right.y + py * up.y + forward.y;
    direction.z = px * right.z + py * up.z + forward.z;
    if ((x == 0 && y==0) || (x == 402 && y == 402) || (x == 400 && y == 400))
	{
		printf("%d | %d : dx = %f, dy = %f and dz = %f\n", x, y, direction.x, direction.y, direction.z);
	}
    ray->direction = normalize(&direction);
	    if ((x == 0 && y==0)|| (x == 402 && y == 402) || (x == 400 && y == 400))
	{
		printf("%d | %d : dx = %f, dy = %f and dz = %f\n", x, y, direction.x, direction.y, direction.z);
	}
    return ray;
}

int hit_sphere(t_object *sphere, t_ray *ray, float *t)
{
	// Livro pagina 62
	float	i1;
	float	i2;
	t_vec3 oc;
	oc = subtract_vec3s(&ray->origin, &sphere->position);
    float a = dot_product(ray->direction, ray->direction);
    float b = 2 * dot_product(ray->direction, oc);
    float c = dot_product(oc, oc) - sphere->radius*sphere->radius;
    float discriminant = b*b - 4*a*c;
	if (discriminant < 0)
		return (0);
	i1 = -b - sqrtf(discriminant) / (2 * a);
	i2 = -b + sqrtf(discriminant) / (2 * a);
	if (i1 == i2)
		return (t[0] = i1, 1);
	else if (i1 > i2)
	{
		t[0] = i1;
		t[1] = i2;
	}
	else
	{
		t[0] = i2;
		t[1] = i1;
	}
	return (2);
}

t_intersections	*intersect(t_ray *ray, t_scene *world)
{
	t_object	**objects;
	int			i;
	t_intersections	intersections;

	i = 0;
	objects = world->objects[0];
	while (objects[i])
	{
		if (hit_sphere(objects[i], ray, intersections.t))
		{
			intersections.object = objects[i]->type;
			intersections = intersections.next;
		}
		i++;
	}
}

int make_sphere(int x, int y, t_camera *camera)
{
	t_object sphere;
	t_ray ray;

	init_sphere(&sphere);
	generate_ray(x, y, camera, &ray);
	if (hit_sphere(&sphere, &ray))
		return (0x89CFF0);
	else
		return (0x000000);
}
