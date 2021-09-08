#include "../../includes/so_long_bonus.h"

int	random_g(long *seed, int lim)
{
	*seed = (*seed * 32719 + 3) % 32749;
	return ((*seed % lim) + 1);
}
