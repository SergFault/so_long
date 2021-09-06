#include "../includes/so_long.h"

void	ft_lstdelone(t_list **lst, int c, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*start;

	start = *lst;
	if (lst != NULL && *lst)
	{
		if (c == 0)
			start = start->next;
		while (c-- > 0)
			*lst = (*lst)->next;
		if (del != NULL)
			(del)((*lst)->content);
		if ((*lst)->prev)
			(*lst)->prev->next = (*lst)->next;
		if ((*lst)->next)
			(*lst)->next->prev = (*lst)->prev;
		tmp = *lst;
		*lst = start;
		free(tmp);
	}
}
