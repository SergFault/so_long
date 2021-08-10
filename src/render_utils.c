#include "../includes/so_long.h"

t_img *get_img(t_rend *rend,char ch)
{
	if (ch == '1')
		return (&rend->wall);
	if (ch == '0')
		return (&rend->floor);
	if (ch == 'P')
		return (&rend->hero);
	if (ch == 'C')
		return (&rend->collectible);
	return (&rend->floor);
}

static void draw_title(t_dataset *set, t_img *ti_img, int x, int y)
{
	img_on_img(&set->rend->main_img, ti_img,
			   x *
			   MODEL_SIZE,
			   y *
			   MODEL_SIZE);
}

static int map_on_img(t_dataset *set)
{
	int i;
	int j;
	t_rend *rend;

	rend = set->rend;
	i = 0;
	while (i < set->game->map_height)
	{
		j = 0;
		while (j < set->game->map_width)
		{
				draw_title(set, get_img(rend, set->game->map[j][i]), i, j);
			j++;
		}
		i++;
	}
	return (1);
}

static void obj_on_img(t_dataset *set, char obj)
{
	t_coordinates pos;

	if (obj == HERO_CH)
		pos = set->game->hero_pos;
	draw_title(set, get_img(set->rend, obj), pos.x, pos.y);
}

static void objs_on_img(t_dataset *set, t_list *objs, char type)
{
	while(objs)
	{
		t_env *env = (t_env*)objs->content;
		draw_title(set, get_img(set->rend, type), env->pos.x, env->pos.y);
		objs = objs->next;
	}
}


int game_loop(t_dataset *set)
{
	(void)  set;
	t_rend *rend = set->rend;

	check_collisions(set);

	map_on_img(set);
	obj_on_img(set, HERO_CH);
	objs_on_img(set, set->game->collectibles, COLL_CH);

	mlx_put_image_to_window(rend->mlx, rend->win, (rend->main_img
	.img),0, 0);
	return (1);
}
