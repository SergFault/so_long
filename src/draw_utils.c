#include "../includes/so_long.h"

void put_pixel(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->address + (y * data->line_length + x * (data->bpp/8));
	*(unsigned int*)dst = color;
}
