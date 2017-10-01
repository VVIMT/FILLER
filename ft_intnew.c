/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:38:21 by vinvimo           #+#    #+#             */
/*   Updated: 2017/10/01 18:38:24 by vinvimo          ###   ########.fr       */
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
