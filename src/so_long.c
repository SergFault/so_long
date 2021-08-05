#include "../includes/so_long.h"

#include <mlx.h>

void init_game(t_game *game)
{
	game->x = 400;
	game->y = 400;
}

//int render_frame(t_img_and_game *data)
//{
//	int y = 1080+1;
//	int x;
//	int color = get_color(data);
//	while (y-- > 0)
//	{
//		x = 1920+1;
//		while (x-- > 0)
//			put_pixel(data->img, x, y, color);
//	}
//	mlx_put_image_to_window(data->game->mlx, data->game->win, data->img->img, 0,
//							0);
//	return (0);
//}

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc == 2)
	{
		t_img	img;
		t_game 	game;
		map_init(&game, argv);

		int i = 0;
		while (i < 10)
		{
			ft_putstr_fd(game.map[i++] ,1);
			ft_putstr_fd("\n" ,1);
		}

		t_dataset dataset;
		dataset.img = &img;
		dataset.game = &game;

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

		t_img spr_img;

		spr_img.img = mlx_xpm_file_to_image(game.mlx, "./assets/floor.xpm", &
		(spr_img.width), & (spr_img.height));
		spr_img.address = mlx_get_data_addr(spr_img.img, &spr_img.bpp,
											&spr_img.line_length, &spr_img.endian);
		img_on_img(&img, &spr_img, 0, 0);
		img_on_img(&img, &spr_img, 64, 0);

		mlx_put_image_to_window(game.mlx, game.win, img.img, 0, 0);
		mlx_key_hook(game.win, process_key, (void *)0);

		mlx_hook(game.win, 2, 1L<<0, move, &dataset);
		//	mlx_loop_hook(game.mlx, draw_circle, &img_and_game);
		mlx_loop(game.mlx);
	}
	else
		ft_putstr_fd("Number of arguments is incorrect.\n", 2);
}