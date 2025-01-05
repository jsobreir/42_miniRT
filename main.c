#include "./includes/minirt.h"

//apagar depois do parser estar pronto
static void init_camera(t_camera *c)
{
	c->fov = 60;
	c->position.x = -50.0;
	c->position.x = 0.0;
	c->position.x = 20.0;
	c->orientation.x = 0.0;
	c->orientation.y = 0.0;
	c->orientation.z = 1.0;
}

static void render_img(t_scene *scene, t_camera *camera)
{
	int			x;
	int			y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mlx_pixel_put(scene->mlx, scene->mlx_win, x, y, make_sphere(x, y, camera));
			y++;
		}
		x++;
	}
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_scene scene;
	t_camera camera;
	init(&scene);
	init_camera(&camera);
	setup_hooks(&scene);
	render_img(&scene, &camera);
	mlx_loop(scene.mlx);
	/*
	Render Scene {
		For each Pixel {
			Calculate ray from origin to pixel {
				if ray hits object && its the closest object {
					Calculate ambient lighting: material * light ambient
					Calulate diffuse lighting {
						Calculate light vector
						Calculate Normal to surface
						if (Compute dot product between Light and Normal vectors < 0)
							set pixel black
						else
							diffuse = light_intensity * material_diffuse (color of material) * light_dot_normal (still a bit confusing)
					}
					Calculate shadows: inverse of Light Ray that intersects object
					if (shadow)
						paint ambient color (think there is a factor of how much to paint...)
				}
			}
		}
	*/
}
