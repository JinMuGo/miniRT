/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:59:02 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/09 18:45:20 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

static bool	is_rtfile(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (!ext || ext == file)
		return (false);
	if (ft_strcmp(ext, ".rt"))
		return (false);
	return (true);
}

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
		parser_error("Invalid identifier\n");
}

void	parser(char *file)
{
	const int	fd = open(file, O_RDONLY);
	char		*line;
	char		**temp;

	line = 0;
	if (fd < 0)
		parser_error("File can't open\n");
	if (!is_rtfile(file))
		parser_error("File doesn't \".rt\" extension\n");
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
}
