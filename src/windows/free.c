#include "minirt.h"

static void	clean_objects(t_object *obj)
{
	t_object	*temp;

	while (obj)
	{
		temp = obj;
		if (obj->cached_transform)
			mtx_free(obj->cached_transform);
		obj = obj->next;
		free(temp);
	}
	free(obj);
}
/// @brief Window clean exit.
/// @param scene 
/// @return 
int	clean_exit(t_scene *scene, char *msg)
{
	if (!msg)
		ft_putstr_fd("Exiting program cleanly.\n", 1);
	else
		ft_putstr_fd(msg, 2);
	if (!scene)
		exit(0);
	if (scene->objects)
		clean_objects(scene->objects);
	if (scene->camera)
		free(scene->camera);
	if (scene->light)
		free(scene->light);
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
	if (!msg)
		exit(0);
	else
		exit(1);
	return (0);
}

int handle_keys(int key, t_scene *scene)
{
	if (key == XK_Escape)
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
	// render image again !!
	return (0);
}

int	free_array(char	**arr, int len)
{
	while (len--)
	{
		free(arr[len]);
	}
	free(arr);
	return (0);
}