/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:30:37 by tlenglin          #+#    #+#             */
/*   Updated: 2016/11/03 19:31:18 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_strdel(char **as)
{
	void **buffer;

	if (as == NULL)
		return ;
	buffer = (void**)as;
	ft_memdel(buffer);
}
