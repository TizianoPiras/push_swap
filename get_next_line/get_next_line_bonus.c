/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:06:34 by tpiras            #+#    #+#             */
/*   Updated: 2023/02/16 13:52:05 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(int fd, char *buff)
{
	char	*tmp;
	int		flag;

	tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	flag = 1;
	while (!ft_check_nline(buff) && flag != 0)
	{
		flag = read(fd, tmp, BUFFER_SIZE);
		if (flag < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[flag] = '\0';
		buff = ft_join(buff, tmp);
	}
	free(tmp);
	return (buff);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*stmp[OPEN_MAX];

	if (fd < 0 || fd == 1000 || BUFFER_SIZE <= 0)
		return (NULL);
	stmp[fd] = ft_next_line(fd, stmp[fd]);
	if (!stmp[fd] || !*stmp[fd])
	{
		free(stmp[fd]);
		return (NULL);
	}
	str = ft_strchr_onlynl(stmp[fd]);
	stmp[fd] = fclear(stmp[fd]);
	return (str);
}
