/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:51:08 by jgo               #+#    #+#             */
/*   Updated: 2023/07/03 14:50:32 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"
#include "utils.h"
#include "design_patterns.h"

static void	parser_router(char **temp)
{
	if (!ft_strcmp(temp[0], "A"))
		parser_ambient(temp);
	else if (!ft_strcmp(temp[0], "C"))
		parser_camera(temp);
	else if (!ft_strcmp(temp[0], "L"))
		parser_light(temp);
	else if (!ft_strcmp(temp[0], "sp"))
		parser_sphere(temp);
	else if (!ft_strcmp(temp[0], "pl"))
		parser_plane(temp);
	else if (!ft_strcmp(temp[0], "cy"))
		parser_cylinder(temp);
	else
		error_handler(TYPE_ERR);
}

void	parser(char *file)
{
	int			fd;
	char		*line;
	char		**temp;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_handler(OPEN_ERR);
	singleton()->fd = fd;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		temp = ft_split_whitespace(line);
		parser_router(temp);
		free(line);
		ft_free_all_arr(temp);
		line = get_next_line(fd);
	}
	close(fd);
}
