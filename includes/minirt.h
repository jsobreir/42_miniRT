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

typedef struct s_solid
{
	void 	*mlx_win;
	void	*mlx;
	t_img 	img;
} t_solid ;

#endif