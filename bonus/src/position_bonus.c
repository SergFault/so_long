#include "../../includes/so_long_bonus.h"

static int	check_wall(int x, int y, char **map)
{
	if (map[y][x] == WALL_CH)
		return (1);
	return (0);
}

static void	change_pos(char axis, int val, t_game *game)
{
	if (axis == 'x')
		game->hero_pos.x += val;
	else if (axis == 'y')
		game->hero_pos.y += val;
	game->movements++;
	ft_putstr_fd("\rNumber of movements: ", STDOUT_FILENO);
	ft_putnbr_fd(game->movements, STDOUT_FILENO);
}

void	move(int direction, t_coordinates *pos, t_game *game)
{
	if (direction == UP && (!check_wall(pos->x, pos->y - 1, game->map)))
		change_pos('y', -1, game);
	if (direction == DOWN && (!check_wall(pos->x, pos->y + 1, game->map)))
		change_pos('y', 1, game);
	if (direction == LEFT && (!check_wall(pos->x - 1, pos->y, game->map)))
		change_pos('x', -1, game);
	if (direction == RIGHT && (!check_wall(pos->x + 1, pos->y, game->map)))
		change_pos('x', 1, game);
}

t_list	*scan_objects(t_game *game, char obj)
{
	t_list			*objs;
	t_env			*env_objs;
	t_coordinates	pos;

	objs = NULL;
	pos.y = 0;
	while (pos.y < game->map_height)
	{
		pos.x = 0;
		while (pos.x < game->map_width)
		{
			if (game->map[pos.y][pos.x] == obj)
			{
				env_objs = malloc(sizeof(t_env));
				env_objs->pos.x = pos.x;
				env_objs->pos.y = pos.y;
				ft_lstadd_back(&objs, ft_lstnew(env_objs));
				game->map[pos.y][pos.x] = FLOOR_CH;
			}
			pos.x++;
		}
		pos.y++;
	}
	return (objs);
}

t_coordinates	get_pos(char obj, t_game *game)
{
	t_coordinates	pos;

	pos.x = 0;
	pos.y = 0;
	while (pos.y < game->map_height)
	{
		pos.x = 0;
		while (pos.x < game->map_width)
		{
			if (game->map[pos.y][pos.x] == obj)
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}
