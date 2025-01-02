#include "./includes/minirt.h"

// init_vars(solid)
// {}

// void	init(t_solid *solid)
// {
// 	// init_vars(solid);
// 	solid->mlx_win = mlx_new_window(solid->mlx, 800, 800, "Fract-ol");
// 	if (solid->mlx_win == NULL)
// 	{
// 		ft_putstr_fd("Error creating window\n", 2);
// 		exit(EXIT_FAILURE);
// 	}
// 	solid->img.img = mlx_new_image(solid->mlx, HEIGHT, WIDTH);
// 	if (solid->img.img == NULL)
// 	{
// 		ft_putstr_fd("Error creating image\n", 2);
// 		exit(EXIT_FAILURE);
// 	}
// 	solid->img.addr = mlx_get_data_addr(solid->img.img,
// 			&solid->img.bpp, &solid->img.line_len, &solid->img.endian);
// 	if (solid->img.addr == NULL)
// 	{
// 		ft_putstr_fd("Error getting data address\n", 2);
// 		mlx_destroy_image(solid->mlx, solid->img.img);
// 		mlx_destroy_window(solid->mlx, solid->mlx_win);
// 		exit(EXIT_FAILURE);
// 	}
// }

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	//t_solid solid;
	ft_putstr_fd("Error getting data address\n", 2);
	// init(&solid);

}
