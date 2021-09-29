#include "../../includes/so_long_bonus.h"

int	random_g(int *seed, int lim)
{
	int i = 0;

	if (*seed > 1000000)
		*seed = 300;
	*seed = (*seed * 32719 + 3) % 32749;
	i = ((*seed % lim) + 1);
	return i;
}
