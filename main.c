#include "./includes/minirt.h"

// apagar depois do parser estar pronto
// static void init_camera(t_camera *c)
// {
// 	c->fov = 60;
// 	c->position.x = 0.0;
// 	c->position.y = 0.0;
// 	c->position.z = 0.0;
// 	c->orientation.x = 0.0;
// 	c->orientation.y = 0.0;
// 	c->orientation.z = 1.0;
// 	c->focal_length = 1.0;
// 	c->viewport_width = 2 * tan(c->fov/2)/c->focal_length;
// 	c->viewport_height = ASPECT_RATIO * c->viewport_width;
// }

int main(int argc, char **argv)
{
	(void)argv;
	t_scene scene;
	t_camera camera;

	init(&scene);
	parse_file(argc, argv, &scene);
	// init_camera(&camera);
	scene.camera = &camera;
	setup_hooks(&scene);
	render_img(&scene, &camera);
	mlx_loop(scene.mlx);
}
