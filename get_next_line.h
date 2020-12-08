/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:36:50 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/07 12:25:09 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		ft_ccheck(const char *set, char c);
int		ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strcpy_nl(char *dest, char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
