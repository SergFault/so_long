#include "../../includes/so_long_bonus.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!(dup))
		return (0);
	ft_strlcpy(dup, s, (len + 1));
	return (dup);
}
