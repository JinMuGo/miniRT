/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lights_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:33:33 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/29 16:11:00 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "design_patterns_bonus.h"
#include "utils_bonus.h"

static bool	_vaildation_light(t_spot_light *light)
{
	if (light->type != LIGHT
		|| !check_0_to_1(light->ratio)
		|| !check_rgb(&light->rgb))
		return (false);
	return (true);
}

void	parser_light(char **line)
{
	t_meta			*meta;
	t_spot_light	*light;

	if (ft_arrlen((void **)line) != 4)
		error_handler(LIGHT_ERR);
	light = ft_malloc(sizeof(t_spot_light));
	light->type = LIGHT;
	light->light_point = parser_vec3(line[1], POINT_ERR);
	light->ratio = check_to_double(line[2]);
	light->rgb = parser_vec3(line[3], RGB_ERR);
	meta = singleton();
	if (!_vaildation_light(light))
	{
		free(light);
		ft_free_all_arr(line);
		error_handler(LIGHT_ERR);
	}
	ft_lstadd_back(&(meta->spot_lights), ft_lstnew(light));
}
