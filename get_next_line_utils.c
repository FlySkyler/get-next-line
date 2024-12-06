/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:15:17 by antbonin          #+#    #+#             */
/*   Updated: 2024/12/06 04:48:45 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_check_end_line(char	*str)
{
	size_t	i;

	i = 0;
	if (ft_strlen(str + i) == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_strlcpy(char *s1, const char *s2, size_t size)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	if (size == 0)
		return (ft_strlen(s2));
	i = 0;
	while (s2[i] && (i < (size - 1)))
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (ft_strlen(s2));
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*copy;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = 0;
	while (s2[len2] != '\n' && s2[len2] != 0)
		len2++;
	if (s2[len2] == '\n')
		len2++;
	copy = malloc(len1 + len2 + 1);
	if (!copy)
		return (free(s1), NULL);
	ft_strlcpy(copy, s1, len1 + 1);
	ft_strlcpy(copy + len1, s2, len2 + 1);
	free(s1);
	return (copy);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	i;
	size_t	len;

	len = 0;
	while (str[len] != '\n' && str[len] != 0)
		len++;
	if (str[len] == '\n')
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
