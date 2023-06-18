/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:55:28 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/18 20:10:22 by sanghwal         ###   ########seoul.kr  */
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
		error_handler(AMB_ERR);
	amb.type = AMB;
	amb.ratio = check_to_double(line[1]);
	amb.rgba = parser_rgba(line[2]);
	meta = singleton();
	if (!vaildation_ambient(amb) || meta->ambient.type == AMB)
	{
		ft_free_all_arr(line);
		error_handler(AMB_ERR);
	}
	meta->ambient = amb;
}
