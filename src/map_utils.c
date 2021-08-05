#include "../includes/so_long.h"


int gnl_map(int fd, t_list **lines)
{
	int read_flag;
	char *line;
	line = NULL;

	read_flag = 1;
	while (read_flag)
	{
		read_flag = get_next_line(fd, &line);
		if (read_flag == -1)
		{
			ft_lstclear(lines, ft_lst_del_str);
			ft_putstr_fd(BAD_FILE, 1);
			close(fd);
			return (-1);
		}
		ft_lstnew(line);
		ft_lstadd_back(lines, ft_lstnew(line));
	}
	close(fd);
	return (1);
}

void count_lines_and_chars(t_list *lines, int *lines_cnt, int *max_len)
{
	int tmp;

	*max_len = 0;
	*lines_cnt = 0;
	while(lines)
	{
		*lines_cnt += 1;
		tmp = ft_strlen((char*)lines->content);
		if (tmp > *max_len)
			*max_len = tmp;
		lines = lines->next;
	}
}

char **str_lines_to_arr(t_list *lines)
{
	int lines_cnt;
	int max_len;
	char **str_arr;
	int tmp;
	t_list *start;

	start = lines;
	count_lines_and_chars(lines, &lines_cnt, &max_len);
	str_arr = (char**) malloc((sizeof (char*)) * lines_cnt);
	if (str_arr == NULL)
		ft_error_null(MEM_ERR);
	tmp = 0;
	lines = start;
	while (lines)
	{
		str_arr[tmp] = ft_strdup(lines->content);
		if (!(str_arr[tmp++]))
		{
			free_str_array(str_arr, --tmp);
			free(str_arr);
			return (ft_error_null(MEM_ERR));
		}
		lines = lines->next;
	}
	return str_arr;
}

int map_init(t_game *game, char **argv)
{
	(void) game;
	int fd;
	t_list *lines;

	lines = NULL;
	fd = open(argv[1], O_RDONLY);
	if 	((read(fd, NULL, 0) < 0) || fd < 0)
	{
		ft_putstr_fd( BAD_FD, 2);
		exit(EXIT_FAILURE);
	}
	fd = gnl_map(fd, &lines);
	if (fd == -1)
		return (-1);
	game->map = str_lines_to_arr(lines);
	if (!(game->map))
	{
		ft_lstclear(&lines, free_str_ptr);
		return (-1);
	}
	return (1);
}
