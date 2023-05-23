/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:53:03 by tpiras            #+#    #+#             */
/*   Updated: 2023/02/16 13:54:06 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char	*ft_strchr_onlynl(char *s)
{
	size_t		i;
	char		*str;

	i = 0;
	while (s[i] && s[i] != '\n')
		++i;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		++i;
	}
	if (s[i] == '\n')
	{
		str[i] = '\n';
		++i;
	}
	str[i] = '\0';
	return (str);
}

char	*fclear(char *s)
{
	size_t	i;
	size_t	j;
	char	*resto;

	i = 0;
	while (s[i] && s[i] != '\n')
	++i;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	j = 0;
	while (s[j])
		++j;
	resto = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!resto)
		return (NULL);
	++i;
	j = 0;
	while (s[i])
		resto[j++] = s[i++];
	resto[j] = '\0';
	free(s);
	return (resto);
}

char	*ft_check_nline(char *s)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (s + i);
		i++;
	}
	return (NULL);
}

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s_final;

	if (!s1 && (!s2 || !*s2))
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
			++i;
	}
	j = 0;
	while (s2[j])
		++j;
	s_final = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!s_final)
		return (NULL);
	s_final[i + j] = '\0';
	while (--j >= 0)
		s_final[i + j] = s2[j];
	while (--i >= 0)
		s_final[i] = s1[i];
	free(s1);
	return (s_final);
}
