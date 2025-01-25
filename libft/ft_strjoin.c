/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:03:31 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/24 20:35:16 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	*ft_strcat(char *str, char *s2, size_t start, size_t l)
{
	size_t	i;

	i = 0;
	while (l > start)
	{
		str[start] = s2[i];
		i++;
		start++;
	}
	str[start] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	l;
	size_t	i;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	l = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((l + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	return (free(s1), ft_strcat(str, s2, i, l));
}
