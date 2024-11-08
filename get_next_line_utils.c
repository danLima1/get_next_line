/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-lima <dde-lima@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:55:06 by dde-lima          #+#    #+#             */
/*   Updated: 2024/11/08 12:25:23 by dde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && (i < size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	char	*cs;

	cs = (char *)s;
	while (*cs)
	{
		if (*cs == (char)c)
			return (cs);
		cs++;
	}
	if (c == '\0')
		return (cs);
	return (NULL);
}
char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = -1;
	j = -1;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if(!dst)
		return (NULL);
	while (s1[++i] != '\0')
		dst[i] = s1[i];
	while (s2[++j] != '\0')
		dst[i++] = s2[j];
	dst[i] = '\0';
	free(s1);
	return (dst);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
