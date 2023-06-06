/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:59:02 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/06 18:01:56 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"
#include "parser.h"

static void	is_rtfile(char *file)
{
	const int	len = ft_strlen(file);
	const char	*str = ".rt";

	if (ft_strcmp(&file[len - 3], str))
		parser_error("File doesn't \".rt\" extension\n");
}

static void	parser_router(char **temp)
{
	if (!ft_strcmp(temp[0], "A"))
		init_ambient(temp);
	else if (!ft_strcmp(temp[0], "C"))
		init_camera(temp);
	else if (!ft_strcmp(temp[0], "L"))
		init_light(temp);
	else if (!ft_strcmp(temp[0], "sp"))
		init_sphere(temp);
	else if (!ft_strcmp(temp[0], "pl"))
		init_plane(temp);
	else if (!ft_strcmp(temp[0], "cy"))
		init_cylinder(temp);
	else
		parser_error("Invalid identifier\n");
}

void	parser(char *file)
{
	const	int	fd = open(file, O_RDONLY);
	char		*line;
	char		**temp;

	line = 0;
	if (fd < 0)
		parser_error("File can't open\n");
	is_rtfile(file);
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_split_whitespace(line);
		parser_router(temp);
		line = get_next_line(fd);
	}
}
