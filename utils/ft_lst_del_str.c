#include "../includes/so_long.h"

void	ft_lst_del_str(void *str)
{
	free(str);
	str = NULL;
}
