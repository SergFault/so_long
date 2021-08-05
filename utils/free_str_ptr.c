#include "../includes/so_long.h"

void free_str_ptr(void *str)
{
	free(str);
	str = NULL;
}