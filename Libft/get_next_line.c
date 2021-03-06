/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:47:31 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/21 13:44:10 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

int		buffer_to_stock(int fd, char **stock, int *bytes_read)
{
	char	*buffer;
	char	*tmp;

	buffer = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (buffer == NULL)
		return (0);
	*bytes_read = read(fd, buffer, BUFF_SIZE);
	if (*bytes_read == -1)
	{
		free(buffer);
		return (0);
	}
	buffer[*bytes_read] = '\0';
	tmp = ft_strjoin(*stock, buffer);
	free(*stock);
	*stock = tmp;
	free(buffer);
	return (1);
}

void	cut_stock(char **stock, char *str)
{
	char		*tmp;

	tmp = ft_strdup(str + 1);
	ft_strdel(stock);
	*stock = tmp;
}

int		file_end(char **line, char **stock)
{
	if (ft_strlen(*stock) || stock[0] == '\0')
	{
		*line = ft_strdup(*stock);
		ft_strdel(stock);
		return (1);
	}
	return (0);
}

int		error_handling(char **stock)
{
	if (stock)
		ft_strdel(stock);
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*stock = NULL;
	char			*str;
	int				bytes_read;

	if (fd < 0 || !(line) || BUFF_SIZE < 0)
		return (-1);
	if (!(stock))
		stock = ft_strnew(0);
	while (!(ft_strchr(stock, '\n')))
	{
		if (!(buffer_to_stock(fd, &stock, &bytes_read)))
			return (error_handling(&stock));
		if (bytes_read == 0)
			return (file_end(line, &stock));
	}
	str = ft_strchr(stock, '\n');
	*line = ft_strsub(stock, 0, str - stock);
	cut_stock(&stock, str);
	return (1);
}
