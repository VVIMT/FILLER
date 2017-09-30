#include "filler.h"

int	*ft_intnew(size_t size)
{
	int		*x;
	size_t	i;

	if (!(x = (int *)malloc(sizeof(*x) * (size + 1))))
		return (NULL);
	i = 0;
	while (i <= size)
	{
		x[i] = 0;
		i++;
	}
	return (x);
}
