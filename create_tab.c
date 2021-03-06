/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:37:31 by vinvimo           #+#    #+#             */
/*   Updated: 2017/10/01 18:37:34 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**create_tab(int i, int j)
{
	char	**data;
	int		counter;

	counter = 0;
	if (!(data = (char**)malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	while (counter < i)
	{
		data[counter] = (char*)malloc(sizeof(char) * (j + 2));
		if (!(data[counter]))
			return (NULL);
		ft_bzero(data[counter], j + 2);
		counter++;
	}
	data[counter] = NULL;
	return (data);
}
