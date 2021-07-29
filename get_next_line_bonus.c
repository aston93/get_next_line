/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:00:13 by dmazurki          #+#    #+#             */
/*   Updated: 2021/05/25 21:38:32 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		*(p + i) = '\0';
		i++;
	}
}

char	*concatenate_lines(char *line1, char *line2)
{
	char	*result;
	size_t	i;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(line1);
	len2 = ft_strlen(line2);
	result = (char *)malloc(len1 + len2 + 1);
	i = 0;
	while (i < len1)
	{
		*(result + i) = *(line1 + i);
		i++;
	}
	i = 0;
	while (i < len2)
	{
		*(result + len1 + i) = *(line2 + i);
		i++;
	}
	*(result + len1 + len2) = '\0';
	free(line1);
	free(line2);
	return (result);
}

int	read_line(char *buff, char **line)
{
	int		len;
	char	*temp_arr;

	len = get_line_length(buff);
	temp_arr = ft_strdup_GNL(buff, len);
	if (*line == 0)
		*line = temp_arr;
	else
		*line = concatenate_lines(*line, temp_arr);
	return (len);
}

ssize_t	else_engine(char *buff, char **line, int *flag)
{
	int		len;
	ssize_t	result;

	len = 0;
	result = 1;
	len = read_line(buff, line);
	if (len != BUFFER_SIZE && *(buff + len) != '\0')
	{
		ft_memmove(buff, buff + len + 1, BUFFER_SIZE - (len + 1));
		result = 1;
		*flag = 1;
	}
	else
		*buff = 0;
	return (result);
}

int	get_next_line(int fd, char **line)
{
	static char	buff[1024][BUFFER_SIZE] = {{0}};
	ssize_t		result;
	int			flag;

	result = 1;
	flag = 0;
	*line = 0;
	while (flag == 0)
	{
		if (*buff[fd] == 0)
		{
			ft_bzero(buff[fd], BUFFER_SIZE);
			result = read(fd, buff[fd], BUFFER_SIZE);
			if (result <= 0)
			{
				read_line(buff[fd], line);
				flag = 1;
			}
		}
		else
			result = else_engine(buff[fd], line, &flag);
	}
	return (result);
}
