/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:59:02 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/08 14:51:26 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"
#include "parser.h"

// static bool	is_rtfile(char *file)
// {
// 	const int	len = ft_strlen(file);
// 	const char	*str = ".rt";

// 	if (ft_strcmp(&file[len - 3], str))
// 		return (false);
// 	return (true);
// }

// static void	parser_router(char **temp)
// {
// 	if (!ft_strcmp(temp[0], "A"))
// 		parse_ambient(temp);
// 	else if (!ft_strcmp(temp[0], "C"))
// 		parse_camera(temp);
// 	else if (!ft_strcmp(temp[0], "L"))
// 		init_light(temp);
// 	else if (!ft_strcmp(temp[0], "sp"))
// 		init_sphere(temp);
// 	else if (!ft_strcmp(temp[0], "pl"))
// 		init_plane(temp);
// 	else if (!ft_strcmp(temp[0], "cy"))
// 		init_cylinder(temp);
// 	else
// 		parser_error("Invalid identifier\n");
// }

// void	parser(char *file)
// {
// 	const	int	fd = open(file, O_RDONLY);
// 	char		*line;
// 	char		**temp;

// 	line = 0;
// 	if (fd < 0)
// 		parser_error("File can't open\n");
// 	if (!is_rtfile(file))
// 		parser_error("File doesn't \".rt\" extension\n");
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		temp = ft_split_whitespace(line);
// 		parser_router(temp);
// 		line = get_next_line(fd);
// 	}
// }
