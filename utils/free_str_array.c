#include "../includes/so_long.h"

void free_str_array(char **str_arr, int index)
{
	int	i;
	i = 0;
	while (i < index)
		free(str_arr[index++]);
}