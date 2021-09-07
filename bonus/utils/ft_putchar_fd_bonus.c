#include "../../includes/so_long_bonus.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
