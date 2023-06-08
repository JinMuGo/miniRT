/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:55:28 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/08 16:36:31 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "design_patterns.h"

static bool	vaildation_ambient(t_ambient amb)
{
	if (amb.type != AMB)
		return (false);
	if (!check_0_to_1(amb.ratio))
		return (false);
	if (!check_rgb(amb.rgb))
		return (false);
	return (true);
}

void	parse_ambient(char **line)
{
	t_meta		*meta;
	t_ambient	amb;

	if (ft_arrlen((void **)line) != 3)
		parser_error("Incorrect number of ambient information\n");
	amb.type = AMB;
	amb.ratio = check_to_double(line[1]);
	amb.rgb = parse_rgb(line[2]);
	if (!vaildation_ambient(amb))
		parser_error("Invaild ambient\n");
	meta = singleton();
	meta->ambient = amb;
}
