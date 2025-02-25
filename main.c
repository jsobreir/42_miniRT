#include "minirt.h"

int main(int argc, char **argv)
{
	(void)argv;
	t_scene scene;

	init(&scene);
	if (parse_file(argc, argv, &scene))
		return (clean_exit(&scene, "Error parsing file!\n"), 0);
	setup_hooks(&scene);
	render_img(&scene);
	mlx_loop(scene.mlx);
	clean_exit(&scene, NULL);
}
