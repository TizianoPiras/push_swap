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

#include "./get_next_line.h"

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
	static char	*stmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stmp = ft_next_line(fd, stmp);
	if (!stmp || !*stmp)
	{
		free(stmp);
		return (NULL);
	}
	str = ft_strchr_onlynl(stmp);
	stmp = fclear(stmp);
	return (str);
}
