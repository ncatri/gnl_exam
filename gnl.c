/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:08:25 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/29 16:51:38 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		free_ret(void *ptr, int value)
{
	free(ptr);
	return (value);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *dst_ptr;
	size_t i;

	if (dst == 0 && src == 0)
		return (NULL);
	dst_ptr = (char*)dst;
	i = -1;
	while (++i < n)
	{
		*dst_ptr = *((char*)src + i);
		dst_ptr++;
	}
	return (dst);
}

int		append(char **buf, size_t size, char c)
{
	char *tmp;

	if (!(tmp = malloc(sizeof(char) * size + 1)))
		return (free_ret(*buf, 0));
	ft_memcpy(tmp, *buf, size);
	free(*buf);
	*buf = tmp;
	(*buf)[size] = c;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char *buf;
	char c;
	size_t l;
	int ret;

	buf = 0;
	if (fd < 0 || !line || read(fd, buf, 0) < 0 || !(buf = malloc(sizeof(char) * 1)))
		return (-1);
	l = 0;
	while ((ret = read(fd, &c, 1)) > 0 && c != '\n')
	{
		if (append(&buf, l, c) == 0)
			free_ret(buf, -1);
		l++;
	}
	append(&buf, l, '\0');
	*line = buf;
	free(buf);
	return (ret);
}
