/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:41:42 by stapioca          #+#    #+#             */
/*   Updated: 2021/11/30 19:41:42 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int ch)
{
	if (!str)
		return ((void *)0);
	while (*str != '\0')
	{
		if (*str == (char)ch)
			return ((char *)str);
		str++;
	}
	if (ch == '\0' && str)
		return ((char *)str);
	return ((void *)0);
}

static char	*do_s1(char *s1, size_t size_s1, char *str)
{
	size_t	i;

	i = 0;
	while (i < size_s1)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}

static char	*do_s2(char *s2, size_t size_s2, size_t i, char *str)
{
	size_t	j;

	j = 0;
	while (j < size_s2)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	size_t		size_s1;
	size_t		size_s2;

	if (!s1)
	{
		s1 = malloc(1);
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	str = malloc(size_s1 + size_s2 + 1);
	if (str == NULL)
		return (NULL);
	str = do_s1(s1, size_s1, str);
	str = do_s2(s2, size_s2, size_s1, str);
	free(s1);
	return (str);
}
