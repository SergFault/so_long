/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:26:22 by sergey            #+#    #+#             */
/*   Updated: 2021/09/29 17:30:34 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>

# define MODEL_SIZE 64
# define BUFFER_SIZE 40
# define ENEMIES_NUM 30
# define TICK 7

# define WIN 1
# define LOOSE 0
# define LEAVE 2
# define HERO_CH 'P'
# define WALL_CH '1'
# define FLOOR_CH '0'
# define COLL_CH 'C'
# define EXIT_CH 'E'
# define ENEMY_CH 'H'

# define WIN_MSG "You`ve won!"
# define LOOSE_MSG "You`ve lost. :< Try again!"
# define LEAVE_MSG "You`ve left this awesome game. :o Come back"
# define VALID_CHARS "01CEP"
# define ARGS_ERROR "Error\nNumber of arguments is incorrect.\n"
# define MEM_ERR "Error\nMemory allocation error.\n"
# define MAP_EXT_ERR "Error\nWrong file extension.\n"
# define BAD_FD "Error\nBad file descriptor error.\n"
# define MAP_VALID_ERR "Error\nMap validation error.\n"
# define BAD_FILE "Error\nFile read error.\n"
# define GRASS_PATH "./assets/grass.XPM"
# define WALL_PATH "./assets/wall.XPM"
# define COLL_PATH "./assets/weapon_sword_1.XPM"
# define HERO0 "./assets/knight_run_anim_f0.XPM"
# define HERO1 "./assets/knight_run_anim_f1.XPM"
# define HERO2 "./assets/knight_run_anim_f2.XPM"
# define HERO3 "./assets/knight_run_anim_f3.XPM"
# define HERO4 "./assets/knight_run_anim_f4.XPM"
# define HERO5 "./assets/knight_run_anim_f5.XPM"
# define ENEMY0 "./assets/goblin_run_anim_f0.XPM"
# define ENEMY1 "./assets/goblin_run_anim_f1.XPM"
# define ENEMY2 "./assets/goblin_run_anim_f2.XPM"
# define ENEMY3 "./assets/goblin_run_anim_f3.XPM"
# define ENEMY4 "./assets/goblin_run_anim_f4.XPM"
# define ENEMY5 "./assets/goblin_run_anim_f5.XPM"

# define EXIT_PATH "./assets/exit.XPM"
# define ESC 65307
# define LEFT 97
# define UP 119
# define RIGHT 100
# define DOWN 115
# define TRANSPARENCY 0xFF000000
# define RED 0x00FF0000
# define DARK_RED 0x005F0000
# define DARK_GREEN 0x00005F00
# define WHITE 0xFFFFFFFF

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef struct s_objs_number
{
	int	collectable;
	int	exit;
	int	player;
}				t_objs_number;

typedef struct s_img
{
	void	*img;
	char	*address;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_rend
{
	void	*mlx;
	void	*win;
	t_img	main_img;
	t_img	floor;
	t_img	wall;
	t_img	collectible;
	t_img	exit;
	t_img	hero0;
	t_img	hero1;
	t_img	hero2;
	t_img	hero3;
	t_img	hero4;
	t_img	hero5;
	t_img	enemy0;
	t_img	enemy1;
	t_img	enemy2;
	t_img	enemy3;
	t_img	enemy4;
	t_img	enemy5;
}				t_rend;

typedef struct s_coordinates
{
	int	x;
	int	y;
}				t_coordinates;

typedef struct s_env
{
	t_coordinates	pos;
}				t_env;

typedef struct s_game{
	int				time;
	int				seed_g;
	t_coordinates	hero_pos;
	int				map_width;
	int				map_height;
	int				win;
	int				movements;
	char			**map;
	t_list			*exits;
	t_list			*collectibles;
	t_list			*enemies;
}				t_game;

typedef struct s_draw_data
{
	int		x;
	int		y;
	float	off_x;
	float	off_y;
	int		s_x;
	int		s_y;
	int		d_x;
	int		d_y;
	int		color;
}				t_draw_data;

typedef struct s_dataset{
	t_rend	*rend;
	t_game	*game;
}				t_dataset;

void			put_pixel(t_img *data, int x, int y, unsigned int color);
int				process_key(int key, t_dataset *set);
int				leave_game(t_dataset *set, int status);
void			img_on_img(t_img *img, t_img *s_img, int startX, int startY);
int				map_init(t_game *game, char **argv);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
int				get_next_line(int fd, char **line);
int				ft_strdup_free(const char *s1, char **dest);
size_t			ft_strlen(const char *s);
int				ft_sj_ff_dt(const char *s1, const char *s2, char **dest);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lst_del_str(void *str);
char			*ft_strdup(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
void			free_str_array(char **str_arr, int index);
void			*ft_error_null(char *message);
int				game_loop(t_dataset *set);
void			init_data(t_dataset *set);
void			free_data(t_dataset *set);
int				leave_game(t_dataset *set, int status);
void			game_init(t_game *game);
t_coordinates	get_pos(char obj, t_game *game);
void			move(int direction, t_coordinates *pos, t_dataset *set);
t_list			*scan_objects(t_game *game, char obj);
int				game_loop(t_dataset *set);
void			check_collisions(t_dataset *set);
void			ft_lstdelone(t_list **lst, int c, void (*del)(void*));
void			ft_putnbr_fd(int n, int fd);
int				check_extension(char *argv);
char			*ft_strchr(const char *s, int c);
int				validate_map(t_list *map);
int				ft_str_cons_only(char *str, char ch);
void			free_env_obj(void *obj);
int				check_map_content(t_list *map);
int				free_map(char **map, int index);
void			enemy_init(t_dataset *set);
t_img			*get_hero_image(t_rend *rend, int time);
t_img			*get_enemy_image(t_rend *rend, int time);
void			move_enemies(t_list *enemies, t_game *game);
int				check_wall(int x, int y, char **map);
int				random_g(int *seed, int lim);
void			print_status(t_dataset *set);
void			print_end(t_dataset *set, int c, char *message);
t_coordinates	*coordinates_init(t_coordinates *pos_p, int x, int y);

#endif