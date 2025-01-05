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
# include <X11/keysym.h>

# define HEIGHT 800
# define WIDTH 800
# define PI 3.14159265358979323846

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef enum e_obj_type
{
	SPHERE ,
	PLANE ,
	CYLINDER
}	t_obj_type;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
} 	t_point;

typedef struct s_vec3
{
	t_point start;
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_object
{
	t_obj_type	type;
	t_point		rgb;
	t_point		position; // centro?
	t_point		orientation; // ??
	float		radius; // Spheres and cylinders
	float		height; // Only cylinders
}	t_object;


typedef struct s_camera
{
	t_point		position;
	t_vec3	orientation;
	int			fov;
}	t_camera;

typedef struct s_light
{
	float		ambient_lighting_ratio;
	int			ambient_color_rgb[3];
	t_point		position;
	float		brightness;
	int			color_rgb[3]; // isto é so para o bonus :)
}	t_light;

typedef struct s_ray
{
	t_point		origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_scene
{
	void 		*mlx_win;
	void		*mlx;
	t_img 		img;
	t_camera 	camera;
	t_light		light;
	t_object	*objects;

} 	t_scene ;

// Windows
int			handle_keys(int key, t_scene *scene);
int			clean_exit(t_scene *solid);
void		init_vars(t_scene *scene);
void		init(t_scene *scene);
void		setup_hooks(t_scene *scene);

// Free
int			free_array(char	**arr, int len);

// Maths
t_vec3 		add_vectors(t_vec3 *one, t_vec3 *two);
t_vec3 		subtract_vec3s(t_vec3 *one, t_vec3 *two);
t_vec3 		multiply_vectors(t_vec3 *one, t_vec3 *two);
t_vec3 		divide_vectors(t_vec3 *one, t_vec3 *two);
float		dot_product(t_vec3 a, t_vec3 b);
t_vec3 		normalize(t_vec3 *a);
t_vec3 		mult_byscalar(t_vec3 *vec, float scalar);
t_vec3 		cross_product(t_vec3 a, t_vec3 b);

// Utils
int			arr_len(char **arr);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);

// Rendering
int make_sphere(int x, int y, t_camera *camera);

#endif