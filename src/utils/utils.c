#include "minirt.h"

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

//TODO: void	convert_color()

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = ((y * img->line_len) + (x * (img->bpp / 8)));
	*(unsigned int *)(img->addr + offset) = color;
}

void	print_intersect_ray(int x, int y, t_intersections *intersections)
{
	while (intersections != NULL)
	{
		printf("x = %i | y = %i: t[0] = %f, t[1] = %f\n", x, y, intersections->t[0], intersections->t[1]);
		intersections = intersections->next;
	}
	// if (intersections && intersections->t && x == WIDTH/2 && y == HEIGHT/2)
	// 	printf("xxx = %i | y = %i: t[0] = %f, t[1] = %f\n", x, y, intersections->t[0], intersections->t[1]);
}