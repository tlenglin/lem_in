/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:10:10 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/21 14:17:04 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlenint(char *str)
{
	int	i;
	int	nbr;
	int count;

	i = 0;
	count = 0;
	if (is_number(str) == 0)
		return (-1);
	nbr = ft_atoi(str);
	if (str[0] == '-')
	{
		count++;
		i++;
	}
	while (str[i] == '0' && str[i])
	{
		i++;
		count++;
	}
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

int	strlen_tab_int(int *tab, int stop)
{
	int i;

	i = 0;
	while (tab[i] != stop)
		i++;
	return (i);
}
