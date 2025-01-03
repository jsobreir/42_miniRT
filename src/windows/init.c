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
}

/// @brief Initiallize mlx.
/// @param scene 
void	init(t_scene *scene)
{
	init_vars(scene);
	scene->mlx_win = mlx_new_window(scene->mlx, 800, 800, "MiniRT");
	if (scene->mlx_win == NULL)
	{
		ft_putstr_fd("Error creating window\n", 2);
		exit(EXIT_FAILURE);
	}
	scene->img.img = mlx_new_image(scene->mlx, HEIGHT, WIDTH);
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
