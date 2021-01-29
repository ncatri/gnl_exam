/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:55:51 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/29 16:55:56 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <strings.h>

int get_next_line(int fd, char **line);

int	main(int argc, char **argv)
{	
	if (argc != 2)
	{
		printf("Usage: a.out <fichier>\n");
		return (0);
	}
	int fd;
	int gnl;
	char *line;

	fd = open(argv[1], O_RDONLY);
	while ((gnl = get_next_line(fd, &line)) == 1)
	{
		printf("%d:%s\n", gnl, line);
	}
	gnl = get_next_line(fd, &line);
	printf("%d:%s\n", gnl, line);
	return (0);
}
