/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:55:28 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/08 14:49:11 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "defs.h"
#include "utils.h"
#include "design_patterns.h"

static void	vaildation_ambient(t_ambient amb)
{
	if (amb.type != AMB)
		return (false);
	if (!check_range_0_to_1(amb.ratio))
		return (false);
	if (!check_rgb(amb.rgb))
		return (false);
	return (true);
}

void	parse_ambient(char **line)
{
	t_meta		*meta;
	t_ambient	amb;

	if (ft_arrlen(line) != 3)
		parser_error("Incorrect number of ambient information\n");
	amb.type = AMB;
	amb.ratio = check_to_double(line[1]);
	amb.rgb = parse_rgb(line[2]);
	if (!validation_ambient(amb))
		parser_error("Invaild ambient\n");
	meta = singleton();
	meta->ambient = amb;
}