#include "../../includes/so_long_bonus.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*iter;
	t_list	*todel;

	if (!lst || !*lst)
		return ;
	iter = *lst;
	while (iter)
	{
		todel = iter;
		iter = iter->next;
		if (del)
			del(todel->content);
		free(todel);
	}
	*lst = 0;
}
