#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>

# define MODEL_SIZE 64
# define BUFFER_SIZE 40

# define HERO_CH 'P'
# define WALL_CH '1'
# define FLOOR_CH '0'
# define COLL_CH 'C'
# define EXIT_CH 'E'

# define MEM_ERR "Memory allocation error."
# define BAD_FD "Bad file descriptor error."
# define BAD_FILE "File read error."
# define GRASS_PATH "./assets/grass.XPM"
# define WALL_PATH "./assets/wall.XPM"
# define COLL_PATH "./assets/weapon_sword_1.XPM"
# define HERO "./assets/knight_run_anim_f0.XPM"
# define ESC 65307
# define LEFT 97
# define UP 119
# define RIGHT 100
# define DOWN 115
# define TRANSPARENCY 0xFF000000
#include <stdio.h>
//#include "mlx_int.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef struct	s_img{
	void	*img;
	char	*address;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;


typedef struct	s_rend
{
	void	*mlx;
	void	*win;
	t_img main_img;
	t_img floor;
	t_img wall;
	t_img collectible;
	t_img exit;
	t_img hero;
}				t_rend;

typedef struct s_coordinates
{
	int x;
	int y;
} t_coordinates;

typedef struct s_env
{
	t_coordinates pos;
} t_env;

typedef struct s_game{
	t_coordinates hero_pos;
	int		map_width;
	int		map_height;
	char 	**map;
	t_list *collectibles;
}				t_game;

typedef struct s_draw_data
{
	int x;
	int y;
	float off_x;
	float off_y;
	int s_x;
	int s_y;
	int d_x;
	int d_y;
	int color;
} t_draw_data;

typedef struct s_dataset{
	t_rend *rend;
	t_game *game;
} 				t_dataset;

void	put_pixel(t_img *data, int x, int y, unsigned color);
int process_key(int key, t_dataset *set);
int leave_game(t_dataset *set);
int resize_attempt(int keycode, t_game *vars);
void	img_on_img(t_img *img, t_img *s_img, int startX, int startY);
int map_init(t_game *game, char **argv);


void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int			get_next_line(int fd, char **line);
int			ft_strdup_free(const char *s1, char **dest);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
int			ft_sj_ff_dt(const char *s1, const char *s2, char **dest);
t_list		*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void ft_lst_del_str(void *str);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void free_str_array(char **str_arr, int index);
void *ft_error_null(char *message);
void free_str_ptr(void *str);
int game_loop(t_dataset *set);
void init_data(t_dataset *set);
void set_img_null(t_img *img);
void free_data(t_dataset *set);
int leave_game(t_dataset *set);
void game_init(t_game *game);
t_coordinates get_pos(char obj, t_game *game);
void move(int direction, t_coordinates *coordinates, char **map);
t_list *scan_objects(t_game *game, char obj);
int game_loop(t_dataset *set);
void check_collisions(t_dataset *set);
void	ft_lstdelone(t_list **lst, int c, void (*del)(void*));

#endif