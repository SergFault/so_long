#include "../includes/so_long.h"

void set_img_null(t_img *img)
{
	img->img = NULL;
	img->address = NULL;
	img->bpp = 0;
	img->line_length = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
}


void free_data(t_dataset *set)
{
	int cnt;
	cnt = 0;
	while (cnt < set->game->map_height)
	{
		free(set->game->map[cnt++]);
	}
	free(set->game->map);
	set->game->map = NULL;
}

void free_env_obj(void *obj)
{
	free(obj);
}