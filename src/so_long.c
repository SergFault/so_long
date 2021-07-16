#include "../includes/so_long.h"

#include <mlx.h>

void init_game(t_game *game)
{
	game->r = 0;
	game->g = 0;
	game->b = 0;
	game->color = 0x00000000;
}

int get_color(t_img_and_game *data)
{
	int color = data->game->color;
	if (color == 0x0000FF00)
		data->game->color = 0x00000000;
	else
	{
		int temp = (color >> 8);
		temp++;
		temp = temp << 8;
		data->game->color = temp & 0x0000FF00;
	}
	return data->game->color;
}

int render_frame(t_img_and_game *data)
{
	int y = 1080+1;
	int x;
	int color = get_color(data);
	while (y-- > 0)
	{
		x = 1920+1;
		while (x-- > 0)
			put_pixel(data->img, x, y, color);
	}
	mlx_put_image_to_window(data->game->mlx, data->game->win, data->img->img, 0,
							0);
	return (0);
}

int	main(void)
{

	t_img	img;
	t_game 	game;
	t_img_and_game img_and_game;
	img_and_game.img = &img;
	img_and_game.game = &game;

	init_game(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(game.mlx, 1920, 1080);
	img.address = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
								 &img.endian);

	int y = 20;
	int x;
	while (y-- > 0)
	{
		x = 20;
		while (x-- > 0)
			put_pixel(&img, x, y, 0x00FF0000);
	}
	//return (0);


	mlx_put_image_to_window(game.mlx, game.win, img.img, 0, 0);
	mlx_key_hook(game.win, process_key, (void *)0);
	mlx_hook(game.win, 2, 1L<<0, leave_game, &game);
	mlx_loop_hook(game.mlx, render_frame, &img_and_game);
	mlx_loop(game.mlx);
}