#include "../../includes/so_long_bonus.h"

t_coordinates	*coordinates_init(t_coordinates *pos_p, int x, int y)
{
	pos_p->x = x;
	pos_p->y = y;
	return (pos_p);
}
