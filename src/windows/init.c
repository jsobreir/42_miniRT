#include "minirt.h"

/// @brief Initialize the structs.
/// @param scene 
void	init_vars(t_scene *scene)
{
	scene->mlx = NULL;
	scene->mlx_win = NULL;
	scene->img.img = NULL;
	scene->mlx = mlx_init();
	if (scene->mlx == NULL)
	{
		ft_putstr_fd("Error initializing MiniLibX\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_memset(scene->objects, 0, sizeof(scene->objects));
	scene->num_objects = 0;
	scene->objects->next = NULL;
	scene->camera = malloc(sizeof(t_camera));
	scene->light = malloc(sizeof(t_light));
	// scene->camera->position = malloc(sizeof(t_vec3));
	// scene->objects = malloc(2 * sizeof(t_object));
	// scene->objects[0].type = SPHERE;
	// scene->objects[0].radius = 1;
	// scene->objects[0].position.x = 0.0;
	// scene->objects[0].position.y = 0.0;
	// scene->objects[0].position.z = 0.0;
	// set_color(&scene->objects[0].rgb, 255, 1, 1);
	// set_color(&scene->light.ambient_color_rgb, 255, 255, 255);
	// scene->light.ambient_lighting_ratio = 0.2;
	// scene->light.position.x = 0;
	// scene->light.position.y = 0;
	// scene->light.position.z = -10;
	// scene->num_objects = 1;
}

/// @brief Initiallize mlx.
/// @param scene 
void	init(t_scene *scene)
{
	init_vars(scene);
	scene->mlx_win = mlx_new_window(scene->mlx, WIDTH, HEIGHT, "MiniRT");
	if (scene->mlx_win == NULL)
	{
		ft_putstr_fd("Error creating window\n", 2);
		exit(EXIT_FAILURE);
	}
	scene->img.img = mlx_new_image(scene->mlx, WIDTH, HEIGHT);
	if (scene->img.img == NULL)
	{
		ft_putstr_fd("Error creating image\n", 2);
		exit(EXIT_FAILURE);
	}
	scene->img.addr = mlx_get_data_addr(scene->img.img,
			&scene->img.bpp, &scene->img.line_len, &scene->img.endian);
	if (scene->img.addr == NULL)
	{
		ft_putstr_fd("Error getting data address\n", 2);
		mlx_destroy_image(scene->mlx, scene->img.img);
		mlx_destroy_window(scene->mlx, scene->mlx_win);
		exit(EXIT_FAILURE);
	}
}

void	init_intersections(t_intersections *inter)
{
	(*inter).t[0] = INFINITY;
	(*inter).t[1] = INFINITY;
	(*inter).next = NULL;
	(*inter).object = NULL;
}
