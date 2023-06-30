/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ambient_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:55:28 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/29 16:10:48 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "utils_bonus.h"
#include "design_patterns_bonus.h"

static bool	_vaildation_ambient(t_ambient amb)
{
	if (amb.type != AMB || !check_0_to_1(amb.ratio) || !check_rgb(&amb.rgb))
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
	if (!_vaildation_ambient(amb) || meta->ambient.type == AMB)
	{
		ft_free_all_arr(line);
		error_handler(AMB_ERR);
	}
	meta->ambient = amb;
}
