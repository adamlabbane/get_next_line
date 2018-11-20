/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gln.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlabban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 01:21:47 by adlabban          #+#    #+#             */
/*   Updated: 2018/03/24 23:43:49 by adlabban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		larg(char *str, char c)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != c && str[i])
		i++;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str;
	char			*c;
	char			buffer[BUFF_SIZE + 1];
	int				i;

	if (!str)
		str = ft_strnew(1);
	while (!(ft_strchr(str, '\n')))
	{
		if ((i = read(fd, buffer, BUFF_SIZE)) == 0)
			break ;
		if (i == -1)
			return (-1);
		buffer[i] = '\0';
		c = ft_strjoin(str, buffer);
		ft_strdel(&str);
		str = c;
	}
	if (ft_strlen(str) == 0)
		return (0);
	*line = ft_strsub(str, 0, larg(str, '\n'));
	c = ft_strsub(str, larg(str, '\n') + 1, ft_strlen(&str[larg(str, '\n')]));
	ft_strdel(&str);
	str = c;
	return (1);
}
