/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:35:24 by dmazurki          #+#    #+#             */
/*   Updated: 2021/05/25 21:34:28 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

char	*concatenate_lines(char *line1, char *line2);
int		get_next_line(int fd, char **line);
char	*ft_strdup_GNL(const char *src, int len);
void	*ft_memcpy(void *dest, const void *src, unsigned int n);
int		get_line_length(char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memmove(void *destination, const void *source, size_t num);
size_t	ft_strlen(char *s);
void	ft_bzero(void *s, size_t n);

#endif