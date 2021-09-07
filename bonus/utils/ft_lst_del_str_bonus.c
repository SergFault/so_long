#include "../../includes/so_long_bonus.h"

void	ft_lst_del_str(void *str)
{
	free(str);
	str = NULL;
}
