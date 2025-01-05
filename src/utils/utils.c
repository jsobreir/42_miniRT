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
