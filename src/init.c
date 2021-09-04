#include "../includes/so_long.h"

void	set_img_null(t_img *img)
{
	img->img = NULL;
	img->address = NULL;
	img->bpp = 0;
	img->line_length = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
}

void	init_data(t_dataset *set)
{
	set->rend->mlx = NULL;
	set->rend->win = NULL;
	set_img_null(&set->rend->main_img);
	set_img_null(&set->rend->floor);
	set_img_null(&set->rend->floor);
	set_img_null(&set->rend->collectible);
	set_img_null(&set->rend->exit);
	set_img_null(&set->rend->hero);
	set->game->hero_pos.x = 0;
	set->game->hero_pos.y = 0;
	set->game->map_width = 0;
	set->game->map_height = 0;
	set->game->map = NULL;
	set->game->exits = NULL;
	set->game->collectibles = NULL;
}

void	game_init(t_game *game)
{
	t_coordinates	pos;

	pos = get_pos(HERO_CH, game);
	game->movements = 0;
	game->win = 0;
	game->collectibles = scan_objects(game, COLL_CH);
	game->exits = scan_objects(game, EXIT_CH);
	game->hero_pos.x = pos.x;
	game->hero_pos.y = pos.y;
	game->map[pos.y][pos.x] = FLOOR_CH;
}
