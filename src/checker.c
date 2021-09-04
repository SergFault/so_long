#include "../includes/so_long.h"

int	check_extension(char *argv)
{
	if (ft_strlen(argv) < 5)
		return (0);
	while (argv[4])
	{
		if (argv[1] == '.' && argv[2] == 'b' && argv[3] == 'e' && argv[4]
			=='r' && argv[5] == '\0')
			return (1);
		argv++;
	}
	return (0);
}

static int	check_rect(t_list *map)
{
	size_t	width;

	width = ft_strlen((char *)map->content);
	map = map->next;
	while (map)
	{
		if (ft_strlen((char *)map->content) != width)
			return (0);
		map = map->next;
	}
	return (1);
}

static int	check_chars(t_list *map)
{
	char	*line;
	char	*valid;

	valid = VALID_CHARS;
	while (map)
	{
		line = (char *)map->content;
		while (*line)
		{
			if (!(ft_strchr(valid, *line)))
				return (0);
			line++;
		}
		map = map->next;
	}
	return (1);
}

static int	check_walls(t_list *map)
{
	char	*line;

	line = (char *)map->content;
	if (!(ft_str_cons_only(line, WALL_CH)))
		return (0);
	map = map->next;
	while (map->next)
	{
		line = (char *)map->content;
		if (*(line++) != WALL_CH)
			return (0);
		while (*line)
		{
			if (*(line) != WALL_CH && (*(line + 1) == '\0'))
				return (0);
			line++;
		}
		map = map->next;
	}
	line = (char *)map->content;
	if (!(ft_str_cons_only(line, WALL_CH)))
		return (0);
	return (1);
}

int	validate_map(t_list *map)
{
	if (!(check_chars(map)) || !(check_rect(map)) || !(check_map_content(map))
		||!(check_walls(map)))
		return (0);
	return (1);
}
