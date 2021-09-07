#include "../../includes/so_long_bonus.h"

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
	set_img_null(&set->rend->hero0);
	set_img_null(&set->rend->hero1);
	set_img_null(&set->rend->hero2);
	set_img_null(&set->rend->hero3);
	set_img_null(&set->rend->hero4);
	set_img_null(&set->rend->hero5);
	set_img_null(&set->rend->enemy0);
	set_img_null(&set->rend->enemy1);
	set_img_null(&set->rend->enemy2);
	set_img_null(&set->rend->enemy3);
	set_img_null(&set->rend->enemy4);
	set_img_null(&set->rend->enemy5);
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

	game->time =  0;
	pos = get_pos(HERO_CH, game);
	game->movements = 0;
	game->win = 0;
	game->collectibles = scan_objects(game, COLL_CH);
	game->exits = scan_objects(game, EXIT_CH);
	game->hero_pos.x = pos.x;
	game->hero_pos.y = pos.y;
	game->map[pos.y][pos.x] = FLOOR_CH;
}

static t_coordinates get_rnd_space(char **map, int height, int m)
{
	int c;
	int h;
	int j;
	t_coordinates pos;

	pos.x = 0;
	pos.y = 0;
	h = height - 1;
	c = P_SEED + m % 200;
	while(h)
	{
		if (h == 1)
			h = height - 1;
		j = 0;
		while(map[h][j])
		{
			if (map[h][j] == FLOOR_CH)
			{
				c--;
				if (c <= 0)
				{
					pos.x = j;
					pos.y = h;
					return pos;
				}
			}
			j++;
		}
		h--;
	}
	return pos;
}

void	enemy_init(t_dataset *set)
{
	int	c;
	int m;
	t_list *lst;
	t_env  *enemy;

	m = 400;
	c = ENEMIES_NUM;
	while (c)
	{
		enemy = (t_env *)malloc(sizeof(t_env));
		enemy->pos = get_rnd_space(set->game->map, set->game->map_height, m);
		ft_lstadd_back(&lst, ft_lstnew(enemy));
		c--;
		m += 255;
	}
	set->game->enemies = lst;
}