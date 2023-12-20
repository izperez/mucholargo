/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:00:41 by izperez           #+#    #+#             */
/*   Updated: 2023/12/05 11:40:03 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*gn_getline(char *line, char *buf)
{
	char	*result;
	size_t	line_len;
	size_t	buf_len;

	line_len = ft_strlen(line);
	buf_len = 0;
	while (buf[buf_len] != '\0' && buf[buf_len] != '\n')
		buf_len++;
	if (buf[buf_len] == '\n')
		buf_len += 1;
	result = (char *)malloc(sizeof(char) * (line_len + buf_len + 1));
	if (result == NULL)
		return (ft_free(line), NULL);
	ft_memcpy(result, line, line_len);
	ft_memcpy(result + line_len, buf, buf_len);
	result[line_len + buf_len] = '\0';
	return (ft_free(line), result);
}

static void	gn_saverest(char *buf)
{
	size_t	buf_len;
	size_t	rest_len;

	buf_len = 0;
	while (buf[buf_len] != '\0' && buf[buf_len] != '\n')
		buf_len++;
	if (buf[buf_len] == '\n')
	{
		buf_len += 1;
		rest_len = ft_strlen(buf + buf_len);
		ft_memcpy(buf, buf + buf_len, rest_len);
		buf[rest_len] = '\0';
	}
	else
		buf[0] = '\0';
}

static char	*gn_readline(int fd, char *buf)
{
	char	*line;
	ssize_t	bytes_read;

	line = gn_getline(NULL, buf);
	if (line == NULL)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(line, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, GNL_BUFSIZE);
		if (bytes_read == -1 || (bytes_read == 0 && ft_strlen(line) == 0))
			return (buf[0] = '\0', ft_free(line), NULL);
		buf[bytes_read] = '\0';
		line = gn_getline(line, buf);
		if (line == NULL)
			return (NULL);
	}
	gn_saverest(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[4096][GNL_BUFSIZE + 1];
	char		*line;

	if (fd < 0 || GNL_BUFSIZE <= 0)
		return (NULL);
	line = gn_readline(fd, buf[fd]);
	return (line);
}
