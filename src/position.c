#include "../includes/so_long.h"

static int check_wall(int x, int y, char **map)
{
	if (map[y][x] == WALL_CH)
		return (1);
	return (0);
}

void move(int direction, t_coordinates *pos, char** map)
{
	if (direction == UP && (!check_wall(pos->x, pos->y-1, map)))
		pos->y--;
	if (direction == DOWN && (!check_wall(pos->x, pos->y+1, map)))
		pos->y++;
	if (direction == LEFT && (!check_wall(pos->x-1, pos->y, map)))
		pos->x--;
	if (direction == RIGHT && (!check_wall(pos->x+1, pos->y, map)))
		pos->x++;
}

t_list *scan_objects(t_game *game, char obj)
{
	t_list *objs;
	t_env *collectible;
	t_coordinates pos;

	objs = NULL;
	pos.y = 0;
	while (pos.y < game->map_height)
	{
		pos.x = 0;
		while (pos.x < game->map_width)
		{
			if (game->map[pos.y][pos.x] == obj)
			{
				collectible = malloc(sizeof(t_env *));
				collectible->pos.x = pos.x;
				collectible->pos.y = pos.y;
				ft_lstadd_back(&objs, ft_lstnew(collectible));
				game->map[pos.y][pos.x] = FLOOR_CH;
			}
			pos.x++;
		}
		pos.y++;
	}
	return objs;
}

t_coordinates get_pos(char obj, t_game *game)
{
	t_coordinates pos;

	pos.x = 0;
	pos.y = 0;
	while (pos.y < game->map_height)
	{
		pos.x = 0;
		while (pos.x < game->map_width)
		{
			if (game->map[pos.y][pos.x] == obj)
				return pos;
			pos.x++;
		}
		pos.y++;
	}
	pos.x = -1;
	pos.y = -1;
	return pos;
}