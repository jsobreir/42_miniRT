/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:56:12 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/03/05 15:27:16 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define HEIGHT 800
# define WIDTH 800
# define PI 3.14159265358979323846
# define EPSILON  0.0001

typedef enum e_obj_type
{
	NONE ,
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
	union
	{
		struct
		{
			float	x;
			float	y;
			float	z;
		};
		struct
		{
			float	r;
			float	g;
			float	b;
		};
	} ;
}	t_vec3;

typedef t_vec3	t_point3;

typedef struct s_matrix
{
	int		n_rows;
	int		n_cols;
	float	**matrix;
}	t_matrix;

typedef struct s_object
{
	t_matrix		*cached_transform;
	t_obj_type		type;
	t_vec3			rgb;
	t_point3		position;
	t_point3		orientation;
	float			radius;
	float			height;
	struct s_object	*next;
}	t_object;

typedef struct s_camera
{
	bool		cam_set;
	t_point3	position;
	t_vec3		orientation;
	float		viewport_height;
	float		viewport_width;
	float		focal_length;
	int			fov;
}	t_camera;

typedef struct s_light
{
	bool		ambient_set;
	bool		light_set;
	float		ambient_lighting_ratio;
	t_vec3		ambient_color_rgb;
	t_point3	position;
	float		brightness;
	t_vec3		color_rgb;
}	t_light;

typedef struct s_intersections
{
	t_point3				point;
	t_point3				poriginal;
	float					t[2];
	t_object				*object;
	struct s_intersections	*next;
	struct s_intersections	*prev;
}	t_intersections;

typedef struct s_ray
{
	t_point3			origin;
	t_vec3				direction;
	t_intersections		*intersections;
	t_vec3				forward;
	t_vec3				up;
	t_vec3				right;
	float				px;
	float				py;
}	t_ray;

typedef struct s_scene
{
	void		*mlx_win;
	void		*mlx;
	int			num_objects;
	t_img		img;
	t_light		*light;
	t_object	*objects;
	t_camera	*camera;
}	t_scene;

typedef struct s_mtx_minor
{
	int	i;
	int	j;
	int	k;
	int	m;
}	t_mtx_minor;

typedef struct s_atof
{
	float	ret;
	int		int_part;
	float	frac_part;
	int		frac_pow;
	int		neg;
}	t_atof;

// Windows
int					handle_keys(int key, t_scene *scene);
int					clean_exit(t_scene *solid, char *msg);
void				init_vars(t_scene *scene);
void				init(t_scene *scene);
void				setup_hooks(t_scene *scene);

// Init
void				init_intersections(t_intersections *inter);

// Parser
int					parse_file(int argc, char **argv, t_scene *scene);
void				fill_ambient(char **args, t_scene *scene);
void				fill_light(char **args, t_scene *scene);
void				fill_camera(char **args, t_scene *scene);
void				fill_sphere(char **args, t_object *sphere);
void				fill_cylinder(char **args, t_object *cylinder);
void				fill_plane(char **args, t_object *plane);

// Free
int					free_array(char	**arr, int len);

// Maths
t_vec3				add_vectors(t_vec3 *one, t_vec3 *two);
t_vec3				subtract_vec3s(t_vec3 one, t_vec3 two);
t_vec3				multiply_vectors(t_vec3 *one, t_vec3 *two);
t_vec3				divide_vectors(t_vec3 *one, t_vec3 *two);
float				dot_product(t_vec3 a, t_vec3 b);
t_vec3				normalize(t_vec3 *a);
t_vec3				mult_byscalar(t_vec3 *vec, float scalar);
t_vec3				cross_product(t_vec3 a, t_vec3 b);
t_vec3				normal_object(t_intersections *inter, t_object *object);
t_vec3				reflect(t_vec3 in, t_vec3 normal);
t_point3			point_on_vec3(float t, t_ray *ray);
t_vec3				fill_vec3(t_vec3 *vector, float x, float y, float z);
float				magnitude(t_vec3 a);

// Matrices
t_matrix			*new_mtx(int rows, int cols);
void				mtx_free(t_matrix *mtx);
t_matrix			*mtx_create_fill(float **data, int rows, int cols);
t_matrix			*mtx_identity(int rows, int cols);
t_matrix			*mtx_multiply(t_matrix a, t_matrix b);
t_matrix			*mtx_minor(int row, int col, t_matrix *mtx);
t_matrix			*mtx_transpose(t_matrix *mtx);
t_matrix			*mtx_cofactor(t_matrix *mtx);
t_matrix			*mtx_add(t_matrix a, t_matrix b);
t_vec3				mtx_mult_vec3(t_matrix *mtx, t_vec3 *vec);
t_point3			mtx_mult_point3(t_matrix *mtx, t_point3 *point);
void				mtx_print(t_matrix *mtx);
void				mtx_rotate_x(t_matrix *mtx, float degrees);
void				mtx_rotate_y(t_matrix *mtx, float degrees);
void				mtx_rotate_z(t_matrix *mtx, float degrees);
t_matrix			*translate(float dx, float dy, float dz);
t_matrix			*mtx_inverse(t_scene *scene, t_matrix *mtx);
float				mtx_determinant(t_matrix *mtx);
t_matrix			*mtx_mult_by_float(t_matrix *mtx, float value);
t_matrix			*mtx_skew_symmetric(t_vec3	axis);
t_matrix			*mtx_skew_symmetric_squared(t_vec3 axis);

//Camera
t_ray				*generate_ray(int x, int y, t_camera *camera, t_ray *ray);

//Intersections
int					hit_sphere(t_object *sphere, t_ray *ray, t_ray *trans_ray,
						t_intersections **inter);
void				hit_cylinder(t_object *cyl, t_ray *trans_ray,
						t_intersections **inters, t_ray *ray);
int					hit_plane(t_object *plane, t_ray *original,
						t_ray *ray, t_intersections **inter);
t_intersections		*intersect(t_ray *ray, t_scene *world);
t_intersections		*intersect_light(t_ray *ray, t_scene *world);
t_intersections		*add_intersect_list(t_intersections **intersections,
						t_object *object, float *t, t_ray *ray);
t_intersections		*new_inters_node(t_object *object, float *t, t_ray *ray);
t_intersections		*last_inters_node(t_intersections *inters);
void				free_t(t_intersections *intersections);
int					check_intersections(float t1[], t_intersections **inter,
						t_object *object, t_ray *ray);
t_ray				*transform_ray(t_object *obj, t_scene *scen, t_ray *ray);
t_matrix			*rotation_matrix(t_object *obj);
int					cyl_cap_plane_check(t_ray *ray, float cap_y, float t[2]);
float				cyl_cap_inters(t_ray *ray, t_object *cyl, float cap_y);

// Utils
int					arr_len(char **arr);
void				my_mlx_pixel_put(t_img *img, int x, int y, int color);
void				print_intersect_ray(int x, int y, t_intersections *inter);
void				print_vec3(t_vec3 *vector);
char				**ft_split_multiple(char *s, char *tokens);
float				ft_atof1(char *nbr);
void				ft_swap(float *a, float *b);

// Rendering
void				render_img(t_scene *scene);
t_vec3				calculate_diffuse(t_intersections *inter, t_scene world);
t_vec3				calculate_specular(t_intersections *inter,
						t_scene world, t_ray *ray);
int					is_shadow(t_intersections *inter1, t_scene *world);
int					color_pixel(int x, int y, t_scene *world);

// Colors
int					rgb_to_hex(t_vec3 *rgb);
t_vec3				change_brightness(t_vec3 *color, float factor);
t_vec3				add_colors(t_vec3 *color1, t_vec3 *color2);
void				set_color(t_vec3 *color, int red, int green, int blue);
t_vec3				multiply_colors(t_vec3 *color1, t_vec3 *color2);
t_vec3				get_light_vec(t_intersections *intersection, t_scene world);

#endif