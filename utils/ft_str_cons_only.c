#include "../includes/so_long.h"

int	ft_str_cons_only(char *str, char ch)
{
	while (*str)
	{
		if (*str != ch)
			return (0);
		str++;
	}
	return (1);
}
