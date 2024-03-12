/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcano-mu <mcano-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:01:42 by mcano-mu          #+#    #+#             */
/*   Updated: 2024/03/12 11:24:43 by mcano-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_buffer(char *buffer)
{
	int		len;
	int		i;
	char	*new_buffer;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (!buffer[len])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - len + 1));
	if (!new_buffer)
		return (NULL);
	len++;
	i = 0;
	while (buffer[len])
		new_buffer[i++] = buffer[len++];
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = buffer[i];
	if (str[i] == '\n')
		str[i + 1] = '\0';
	return (str);
}

char	*ft_read_fd(int fd, char *str)
{
	char	*read_buffer;
	int		len;

	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	len = 1;
	while (!ft_strchr(str, '\n') && len != 0)
	{
		len = read(fd, read_buffer, BUFFER_SIZE);
		if (len == -1)
		{
			free(read_buffer);
			return (NULL);
		}
		read_buffer[len] = '\0';
		str = ft_strjoin(str, read_buffer);
	}
	free(read_buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read_fd(fd, buffer);
	if (!buffer)
		return (NULL);
	next_line = ft_get_line(buffer);
	buffer = ft_new_buffer(buffer);
	return (next_line);
}
