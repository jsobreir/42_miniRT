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

void	print_vec3(t_vec3 *vector)
{
	printf("%f\n", vector->x);
	printf("%f\n", vector->y);
	printf("%f\n", vector->z);
}

float	ft_atof1(char *nbr)
{
	float	ret;
	int		int_part;
	float	frac_part;
	int		frac_pow;
	int		i;

	i = 0;
	frac_part = 0.1;
	int_part = 0;
	frac_pow = 1;
	int_part = ft_atoi(nbr);
	while (*nbr && *nbr != '.')
	{
		if (!nbr)
			return (printf("%i\n", int_part), (float) int_part);
		nbr++;
	}
	if (nbr && *nbr && *nbr == '.')
		nbr++;
	else
		return (printf("%i\n", int_part), (float) int_part);
	frac_part = ft_atoi(nbr);
	while (nbr && *nbr && (*nbr >= '0' && *nbr <= '9'))
	{
		nbr++;
		frac_pow *= 10;
	}
	ret = int_part + frac_part/frac_pow;
	printf("%f\n", ret);
	return (ret);
}
