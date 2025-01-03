#include "minirt.h"

int	clean_exit(t_scene *scene)
{
	ft_putstr_fd("Exiting program cleanly.\n", 1);
	if (!scene)
		exit(0);
	if (scene->img.img)
		mlx_destroy_image(scene->mlx, scene->img.img);
	if (scene->mlx_win && scene->mlx)
		mlx_destroy_window(scene->mlx, scene->mlx_win);
	if (scene->mlx)
	{
		mlx_loop_end(scene->mlx);
		mlx_destroy_display(scene->mlx);
		free(scene->mlx);
	}
	exit(0);
	return (0);
}