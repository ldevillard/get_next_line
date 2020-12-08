/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:03:48 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/07 16:03:52 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ralloc_line(char *current)
{
	char				*str;
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	if (!current)
		return (NULL);
	while (current[i] && current[i] != '\n')
		i++;
	if (!current[i])
	{
		free(current);
		return (NULL);
	}
	str = ft_substr(current, i + 1, (size_t)(ft_strlen(current) - i));
	free(current);
	return (str);
}

char	*alloc_line(char *current)
{
	int		i;
	char	*str;

	i = 0;
	if (!current)
		return (NULL);
	while (current[i] && current[i] != '\n')
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	return (ft_strcpy_nl(str, current));
}

int		get_next_line(int fd, char **line)
{
	char			*tmp;
	static char		*current;
	int				i;

	i = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_ccheck(current, '\n') && i != 0)
	{
		if ((i = read(fd, tmp, BUFFER_SIZE)) == -1)
		{
			free(tmp);
			return (-1);
		}
		tmp[i] = '\0';
		current = ft_strjoin(current, tmp);
	}
	free(tmp);
	line[0] = alloc_line(current);
	current = ralloc_line(current);
	if (i == 0)
		return (0);
	return (1);
}
