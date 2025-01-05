#include "minirt.h"

//apagar depois do parser estar pronto
static t_object *init_sphere(t_object *sphere)
{
	sphere->type = SPHERE;
	sphere->radius = 5;
	sphere->position.x = 0.12;
	sphere->position.y = 0.0;
	sphere->position.z = 0.0;
	sphere->height = 0;
	sphere->rgb.x = 1;
	sphere->rgb.y = 0;
	sphere->rgb.z = 0;
	return (sphere);
}

static t_ray* generate_ray(int x, int y, t_camera *camera, t_ray *ray)
{
    ray->origin = camera->position;
    
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
    float aspect_ratio = (float)WIDTH / (float)HEIGHT;
    float viewport_height = 2.0f * tan(fov / 2.0f);
    float viewport_width = viewport_height * aspect_ratio;
    
    // Convert pixel coordinates to viewport coordinates
    float px = (((2.0f * (float)x) / WIDTH) - 1.0f) * viewport_width *0.5;
    float py = (1.0f - ((2.0f * (float)y) / HEIGHT)) * viewport_height *0.5;
    
    // Calculate ray direction using camera basis vectors
    t_vec3 direction;
    direction.x = px * right.x + py * up.x + forward.x;
    direction.y = px * right.y + py * up.y + forward.y;
    direction.z = px * right.z + py * up.z + forward.z;
    
    ray->direction = normalize(&direction);
    return ray;
}

int hit_sphere(t_object *sphere, t_ray *ray)
{
	t_vec3 oc;
	oc.x = ray->origin.x - sphere->position.x;
	oc.y = ray->origin.y - sphere->position.y;
	oc.z = ray->origin.z - sphere->position.z;
    float a = dot_product(ray->direction, ray->direction);
    float b = 2.0 * dot_product(ray->direction, oc);
    float c = dot_product(oc, oc) - sphere->radius*sphere->radius;
    float discriminant = b*b - 4*a*c;
	printf("%f\n", discriminant);
    return (discriminant >= 0);
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
