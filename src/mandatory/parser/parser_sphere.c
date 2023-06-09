/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:00:17 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/09 16:14:34 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "design_patterns.h"

static bool	vaildation_sphere(t_sphere *sphere)
{
	if (sphere->type != SP)
		return (false);
	if (!check_rgb(sphere->rgb))
		return (false);
	return (true);
}

void	parser_sphere(char **line)
{
	t_meta		*meta;
	t_sphere	*sphere;

	if (ft_arrlen((void **)line) != 4)
		parser_error("Incorrect number of light information\n");
	sphere = ft_malloc(sizeof(t_sphere));
	sphere->type = SP;
	sphere->center_point = parser_point3(line[1]);
	sphere->diameter = check_to_double(line[2]);
	sphere->rgb = parser_rgb(line[3]);
	if (!vaildation_sphere(sphere))
	{
		free(sphere);
		parser_error("Invaild sphere\n");
	}
	meta = singleton();
	ft_lstadd_back(&(meta->objs), ft_lstnew(sphere));
}