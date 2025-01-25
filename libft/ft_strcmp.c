/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:46:07 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/21 10:20:31 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	skip(unsigned char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	size_t			j;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	j = 0;
	if (str1[i] == '+')
		i = skip(str1);
	if (str2[i] == '+')
		j = skip(str2);
	while ((str1[i] || str2[j]))
	{
		if (str1[i] < str2[j])
			return (-1);
		else if (str1[i] > str2[j])
			return (1);
		i++;
		j++;
	}
	return (0);
}
