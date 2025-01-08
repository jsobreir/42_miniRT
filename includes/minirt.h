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
# include <stdbool.h>

# define HEIGHT 400
# define WIDTH 800
# define PI 3.14159265358979323846
#define ASPECT_RATIO ((float)HEIGHT / (float)WIDTH)

typedef enum e_obj_type
{
	SPHERE ,
	PLANE ,
	CYLINDER
}	t_obj_type;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef t_vec3 t_point3;

typedef struct s_object
{
	t_obj_type	type;
	t_point3	rgb;
	t_point3	position; // centro?
	t_point3	orientation; // ??
	float		radius; // Spheres and cylinders
	float		height; // Only cylinders
}	t_object;


typedef struct s_camera
{
	t_point3		position;
	t_vec3		orientation;
	float		viewport_height;
	float		viewport_width;
	float		focal_length;
	int			fov;
}	t_camera;

typedef struct s_light
{
	float		ambient_lighting_ratio;
	int			ambient_color_rgb[3];
	t_point3		position;
	float		brightness;
	int			color_rgb[3]; // isto é so para o bonus :)
}	t_light;

/// Livro pagina 64
typedef struct s_intersections
{
	float					t[2];
	t_object 				*object;
	struct s_intersections	*next;
	struct s_intersections	*prev;
}	t_intersections;

typedef struct s_ray
{
	t_point3			origin;
	t_vec3			direction;
	t_intersections *intersections;
}	t_ray;


typedef struct s_scene
{
	void 		*mlx_win;
	void		*mlx;
	t_img 		img;
	t_light		light;
	t_object	**objects;
	t_camera	*camera;
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

//Camera
t_ray*		generate_ray(int x, int y, t_camera *camera, t_ray *ray);

//Intersections
int				hit_sphere(t_object *sphere, t_ray *ray);
t_intersections	*intersect(t_ray *ray, t_scene *world);
void			add_intersect_list(t_ray *ray, t_object *object, float *t);

// Utils
int			arr_len(char **arr);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		print_intersect_ray(t_intersections *intersections);

// Rendering
void		render_img(t_scene *scene, t_camera *camera);
int			make_sphere(int x, int y, t_camera *camera);

#endif