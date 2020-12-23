/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:30:15 by oelkhams          #+#    #+#             */
/*   Updated: 2019/06/20 17:31:54 by oelkhams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gety(int fd, char **str, int *res)
{
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;

	if (!str[fd])
		str[fd] = ft_strdup("");
	while (!ft_strchr(str[fd], '\n')
			&& (*res = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[*res] = '\0';
		tmp = str[fd];
		str[fd] = ft_strjoin(str[fd], buffer);
		free(tmp);
	}
}

int		get_next_line(const int fd, char **line)
{
	static char		*str[FD_SIZE];
	int				res;
	int				i;
	char			*tmp;

	i = 0;
	res = 0;
	if (fd < 0 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	gety(fd, str, &res);
	if (res < 1 && !*str[fd])
	{
		ft_strdel(&str[fd]);
		return (0);
	}
	while (str[fd][i] != '\0' && str[fd][i] != '\n')
		i++;
	*line = ft_strsub(str[fd], 0, i);
	tmp = str[fd];
	if (str[fd][i] == '\0')
		str[fd] = ft_strnew(0);
	else
		str[fd] = ft_strdup(str[fd] + i + 1);
	ft_strdel(&tmp);
	return (1);
}
