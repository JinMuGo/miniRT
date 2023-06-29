/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:55:28 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/29 09:59:15 by jgo              ###   ########.fr       */
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
	if (!check_rgb(&amb.rgb))
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
	amb.rgb = parser_vec3(line[2], RGB_ERR);
	meta = singleton();
	if (!vaildation_ambient(amb) || meta->ambient.type == AMB)
	{
		ft_free_all_arr(line);
		error_handler(AMB_ERR);
	}
	meta->ambient = amb;
}
