#include "minirt.h"

void	setup_hooks(t_scene *scene)
{
	mlx_hook(scene->mlx_win, 17, 0, clean_exit, scene);
	mlx_key_hook(scene->mlx_win, handle_keys, scene);
}
