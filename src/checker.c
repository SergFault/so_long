#include "../includes/so_long.h"

int check_extension(char *argv)
{
	if (ft_strlen(argv) < 5)
		return (0);
	while (argv[4])
	{
		if (argv[1] == '.' && argv[2] == 'b' && argv[3] == 'e' && argv[4]
		=='r' && argv[5] =='\0')
			return (1);
		argv++;
	}
	return 0;
}

//int validate_map(t_list *map)
//{
//
//}
