#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include "./libft/printf/ft_printf.h"
# include <X11/keysym.h>
# include <X11/X.h>
// # include "keys.h"

# define HEIGHT 800
# define WIDTH 800

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_scene
{
	void 	*mlx_win;
	void	*mlx;
	t_img 	img;
} 	t_scene ;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
} 	t_point;

typedef struct s_vector
{
	t_point start;
	float	x;
	float	y;
	float	z;
}	t_vector;


int			clean_exit(t_scene *solid);
void		setup_hooks(t_scene *scene);
t_vector 	add_vectors(t_vector *one, t_vector *two);
t_vector 	subtract_vectors(t_vector *one, t_vector *two);
t_vector 	multiply_vectors(t_vector *one, t_vector *two);
t_vector 	divide_vectors(t_vector *one, t_vector *two);

#endif