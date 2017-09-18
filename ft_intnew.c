/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 22:56:27 by vinvimo           #+#    #+#             */
/*   Updated: 2017/09/18 22:56:29 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
