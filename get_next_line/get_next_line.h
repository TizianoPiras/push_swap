/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:47:13 by tpiras            #+#    #+#             */
/*   Updated: 2023/02/16 13:41:09 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <limits.h>
# include <stdio.h>

char	*ft_next_line(int fd, char *buff);
char	*get_next_line(int fd);
char	*ft_strchr_onlynl(char *s);
char	*fclear(char *s);
char	*ft_check_nline(char *s);
char	*ft_join(char *s1, char *s2);

#endif
