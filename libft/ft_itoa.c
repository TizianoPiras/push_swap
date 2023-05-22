/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:35:43 by tpiras            #+#    #+#             */
/*   Updated: 2023/01/31 11:40:27 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static unsigned int	ft_counter(long int n)
{
	long int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int			i;
	char				*str;
	long int			len;
	long int			longnbr;

	i = -1;
	longnbr = (long int)n;
	len = ft_counter(longnbr);
	str = (char *)malloc((len + 1) * sizeof (char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (longnbr < 0)
	{
		str[0] = '-';
		longnbr *= -1;
		i = 0;
	}
	while (len > i)
	{
		str[len] = (longnbr % 10) + 48;
		longnbr /= 10;
		len--;
	}
	return (str);
}
