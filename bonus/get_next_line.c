/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:23:46 by aychikhi          #+#    #+#             */
/*   Updated: 2025/05/26 09:44:40 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	str = (char *)s;
	len = ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		if (str[i] == (char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}

static char	*read_line(int fd, char *buffer, char *remainder)
{
	char	*temp;
	ssize_t	bytes_read;

	temp = NULL;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(remainder, buffer);
		free(remainder);
		remainder = temp;
		if (ft_strchr(remainder, '\n') || bytes_read < BUFFER_SIZE)
			break ;
	}
	return (remainder);
}

static char	*extract_line(char **remainder)
{
	char	*line;
	char	*newline_pos;
	char	*temp;

	newline_pos = ft_strchr(*remainder, '\n');
	if (newline_pos)
	{
		line = ft_substr(*remainder, 0, newline_pos - *remainder + 1);
		temp = ft_strdup(newline_pos + 1);
		free(*remainder);
		*remainder = temp;
	}
	else
	{
		if (!**remainder)
			return (free(*remainder), *remainder = NULL, NULL);
		line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(remainder), remainder = NULL, NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(remainder), remainder = NULL, NULL);
	remainder = read_line(fd, buffer, remainder);
	if (!remainder)
		return (free(buffer), NULL);
	return (free(buffer), extract_line(&remainder));
}
