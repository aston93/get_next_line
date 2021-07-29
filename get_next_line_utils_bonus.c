/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:00:06 by dmazurki          #+#    #+#             */
/*   Updated: 2021/05/25 21:39:30 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	get_line_length(char *src)
{
	int	i;

	i = 0;
	while ((src[i] != '\n') && (i < BUFFER_SIZE) && (src[i] != 0))
		i++;
	return (i);
}

char	*ft_strdup_GNL(const char *src, int len)
{
	int		i;
	char	*dest;

	dest = NULL;
	i = 0;
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	while (src[i] && (i < len))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	while (n)
	{
		*d = *s;
		s++;
		d++;
		n--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dst;

	dst = (char *) dest;
	i = 0;
	while (i < n)
	{
		*(dst + i) = *((char *) src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (dst);
}
