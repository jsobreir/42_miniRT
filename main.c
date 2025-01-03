#include "./includes/minirt.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_scene scene;
	init(&scene);
	setup_hooks(&scene);
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
