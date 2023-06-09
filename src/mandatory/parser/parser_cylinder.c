/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:50:54 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/09 17:09:05 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "design_patterns.h"

static bool	vaildation_cylinder(t_cylinder *cylinder)
{
	if (cylinder->type != CY)
		return (false);
	if (!check_minus1_to_1(cylinder->normal_vec3.x)
		|| !check_minus1_to_1(cylinder->normal_vec3.y)
		|| !check_minus1_to_1(cylinder->normal_vec3.z)
		|| !check_rgb(cylinder->rgb))
		return (false);
	return (true);
}

void	parser_cylinder(char **line)
{
	t_meta		*meta;
	t_cylinder	*cylinder;

	if (ft_arrlen((void **)line) != 6)
		parser_error("Incorrect number of cylinder information\n");
	cylinder = ft_malloc(sizeof(t_cylinder));
	cylinder->type = CY;
	cylinder->center_point = parser_point3(line[1]);
	cylinder->normal_vec3 = parser_vec3(line[2]);
	cylinder->diameter = check_to_double(line[3]);
	cylinder->height = check_to_double(line[4]);
	cylinder->rgb = parser_rgb(line[5]);
	if (!vaildation_cylinder(cylinder))
	{
		free(cylinder);
		parser_error("Invaild cylinder\n");
	}
	meta = singleton();
	ft_lstadd_back(&(meta->objs), ft_lstnew(cylinder));
}
