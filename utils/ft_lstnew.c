#include "../includes/so_long.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newl;

	newl = malloc(sizeof(t_list));
	if (!(newl))
		return (0);
	newl->content = content;
	newl->next = 0;
	return (newl);
}
