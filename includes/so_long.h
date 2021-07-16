#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx.h"
//#include "mlx_int.h"

typedef struct	s_img{
	void	*img;
	char	*address;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_game{
	void	*mlx;
	void	*win;
	int r;
	int g;
	int b;
	int color;
}				t_game;

typedef struct s_img_and_game{
	t_img *img;
	t_game *game;
} 				t_img_and_game;


void	put_pixel(t_img *data, int x, int y, int color);
int		process_key(int key, void *param);
int		leave_game(int keycode, t_game *vars);

#endif