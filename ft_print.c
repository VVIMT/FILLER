#include "filler.h"

long	ft_print(char **data, int fd)
{
	long	i;
	long	j;

	i = 0;
	while (data[i])
	{
		j = 0;
		while (data[i][j])
			ft_putchar_fd(data[i][j++], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
	return (0);
}
