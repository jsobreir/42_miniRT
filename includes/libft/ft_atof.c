#include "libft.h"

float	ft_atof(char *nbr)
{
	float	ret;
	int		int_part;
	int		frac_part;
	int		frac_pow;
	int		i;

	i = 0;
	frac_part = 0;
	frac_pow = 1;
	int_part = ft_atoi(nbr);
	while (nbr && *nbr && *nbr != '.')
		nbr++;
	if (nbr && *nbr && *nbr == '.')
		nbr++;
	printf("Here\n");
	while (nbr && *nbr && (*nbr >= '0' && *nbr <= '9'))
	{
		nbr++;
		frac_pow *= 10;
	}
	frac_part = ft_atoi(nbr);
	ret = int_part + frac_part/frac_pow;
	return (ret);
}
