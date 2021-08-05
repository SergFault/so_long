#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>

# define MOD_S 64
# define BUFFER_SIZE 40

# define MEM_ERR "Memory allocation error."
# define BAD_FD "Bad file descriptor error."
# define BAD_FILE "File read error."

#include <stdio.h>
//#include "mlx_int.h"

typedef struct	s_img{
	void	*img;
	char	*address;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

//typedef struct s_data {
//	void	*img;
//	char	*addr;
//	int		bits_per_pixel;
//	int		line_length;
//	int		endian;
//	int		width;
//	int		height;
//}				t_data;

typedef struct s_game{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		map_width;
	int		map_height;
	char 	**map;
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
	t_img *img;
	t_game *game;
} 				t_dataset;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void	put_pixel(t_img *data, int x, int y, int color);
int		process_key(int key, void *param);
int leave_game(t_game *vars);
int resize_attempt(int keycode, t_game *vars);
int move(int keycode, t_dataset *data);
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

#endif