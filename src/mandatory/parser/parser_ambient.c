/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:55:28 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/10 09:45:37 by jgo              ###   ########.fr       */
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
	if (!check_rgba(amb.rgba))
		return (false);
	return (true);
}

void	parser_ambient(char **line)
{
	t_meta		*meta;
	t_ambient	amb;

	if (ft_arrlen((void **)line) != 3)
		parser_error("Incorrect number of ambient information\n");
	amb.type = AMB;
	amb.ratio = check_to_double(line[1]);
	amb.rgba = parser_rgba(line[2]);
	if (!vaildation_ambient(amb))
	{
		ft_free_all_arr(line);
		parser_error("Invaild ambient\n");
	}
	meta = singleton();
	meta->ambient = amb;
}
