#include "../../includes/so_long_bonus.h"

void	*ft_error_null(char *message)
{
	ft_putstr_fd(message, 2);
	return (NULL);
}
