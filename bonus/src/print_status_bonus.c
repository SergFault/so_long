#include "../../includes/so_long_bonus.h"

static char	*itoa(int i)
{
	int		ranks;
	int		c;
	char	*str;

	ranks = 0;
	c = i;
	while (c > 0)
	{
		c /= 10;
		ranks++;
	}
	str = (char *) malloc(sizeof(char) * (ranks + 1));
	if (!(str))
		return (NULL);
	str[ranks] = '\0';
	while (ranks--)
	{
		str[ranks] = i % 10 + '0';
		i /= 10;
	}
	return (str);
}

void	print_status(t_dataset *set)
{
	char	*str_num;

	str_num = itoa(set->game->movements);
	mlx_string_put(set->rend->mlx, set->rend->win, 20, 20, RED, "Moves:");
	if (!(str_num))
	{
		mlx_string_put(set->rend->mlx, set->rend->win, 60, 20, RED,
			"no data");
		ft_putstr_fd(MEM_ERR, STDERR_FILENO);
	}
	else
		mlx_string_put(set->rend->mlx, set->rend->win, 60, 20, RED,
					   str_num);
	free(str_num);
}

static void	print_central(t_dataset *set, char *msg)
{
	int	x;
	int	y;

	x = set->game->map_width * MODEL_SIZE / 2 - ft_strlen(msg) / 2;
	y = set->game->map_height * MODEL_SIZE / 2;
	mlx_string_put(set->rend->mlx, set->rend->win, x, y, WHITE, msg);
}

void	print_end(t_dataset *set, int c, char *message)
{
	int				width;
	int				height;
	t_rend			*r;
	unsigned int	counter;

	counter = 500;
	r = set->rend;
	while (counter--)
	{
		height = set->game->map_height * MODEL_SIZE;
		while (height >= 0)
		{
			width = set->game->map_width * MODEL_SIZE;
			while (width >= 0)
			{
				put_pixel(&(r->main_img), width, height, c);
				width--;
			}
			height--;
		}
		mlx_put_image_to_window(r->mlx, r->win, (r->main_img.img), 0, 0);
		print_central(set, message);
	}
	mlx_put_image_to_window(r->mlx, r->win, (r->main_img.img), 0, 0);
	print_central(set, message);
}
