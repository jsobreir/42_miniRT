#include "minirt.h"

int main(int argc, char **argv)
{
	(void)argv;
	t_scene scene;

	init(&scene);
	if (parse_file(argc, argv, &scene))
		return (0);
	printf("num objects = %d\n", scene.num_objects);
	setup_hooks(&scene);
	render_img(&scene);
	// printf("Here\n");
	mlx_loop(scene.mlx);
	clean_exit(&scene, NULL);
}

/*
	------------------
	For Matrix testing
	------------------
*/


// float **fill_data(void)
// {
// 	int i = 0;
// 	int	j = 0;
// 	float dt[3][3] = {
//     {1, 2.3f, 2},
//     {23, 2, 1},
// 	{3, 2.4, 65}};
// 	float **data;

// 	data = malloc(sizeof(float *) * 3);
// 	while (i < 3)
// 	{
// 		data[i] = malloc(3 * sizeof(float));
// 		j = 0;
// 		while (j < 3)
// 		{
// 			data[i][j] = dt[i][j];
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (data);
// }

// int main(void)
// {
// 	t_matrix *a;
// 	float **data;
// 	t_scene scene;

// 	init(&scene);
// 	data = fill_data();
// 	a = mtx_create_fill(data, 3, 3);
// 	// t_matrix *b = mtx_transpose(a);
// 	// printf("Matrix A:\n");
// 	mtx_print(a);
// 	// printf("\n\n");
// 	// printf("Transpose of matrix A:\n");
// 	// mtx_print(b);
// 	// t_matrix *minor = mtx_minor(2, 1, a);
// 	// mtx_print(minor);
// 	// t_matrix *cof = mtx_cofactor(a);
// 	// mtx_print(cof);
// 	t_matrix *inv = mtx_inverse(&scene, a);
// 	printf("Inverse of A:\n");
// 	mtx_print(inv);
// }