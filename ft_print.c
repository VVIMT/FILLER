/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:59:05 by vinvimo           #+#    #+#             */
/*   Updated: 2017/09/18 22:59:07 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
