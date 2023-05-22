/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:51:13 by tpiras            #+#    #+#             */
/*   Updated: 2023/02/01 14:20:27 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = (unsigned int) len;
	if (ft_strlen(s) <= (int)len)
		str = (char *) malloc(ft_strlen(s) + 1);
	else
		str = (char *)malloc(j + 1);
	if (!str)
		return (NULL);
	if (!((unsigned int) ft_strlen(s) < start))
	{
		while (s[start] != '\0' && i < j)
		{
			str[i] = s[start];
			i++;
			start++;
		}
	}
	str[i] = '\0';
	return (str);
}
