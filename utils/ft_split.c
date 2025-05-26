/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:51:11 by aychikhi          #+#    #+#             */
/*   Updated: 2025/05/26 09:43:26 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count(const char *str, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str && str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			res++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (res);
}

static int	len(const char *str, char c, int i)
{
	int	j;

	j = 0;
	while (str[i] && str[i] != c)
	{
		j++;
		i++;
	}
	return (j);
}

static char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	free_2d_arr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		l;
	int		i;
	int		j;

	i = 0;
	l = 0;
	j = 0;
	if (!s)
		return (NULL);
	ptr = malloc((count(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (ptr && i < count(s, c))
	{
		j += l;
		while (s[j] == c)
			j++;
		l = len(s, c, j);
		ptr[i] = malloc((l + 1) * sizeof(char));
		if (!ptr[i])
			return (free_2d_arr(ptr), free(ptr), NULL);
		ft_strncpy(ptr[i++], s + j, l);
	}
	return (ptr[i] = NULL, ptr);
}
