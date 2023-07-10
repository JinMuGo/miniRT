/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lights_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:33:33 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/10 10:28:01 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "utils_bonus.h"
#include "design_patterns_bonus.h"

static inline bool	_vaildation_light(t_spot_light *light)
{
	if (light->type != LIGHT || !check_0_to_1(light->ratio)
		|| !check_rgb(&light->rgb))
		return (false);
	return (true);
}

static inline void	_set_spot_light_info(t_spot_light *light, char **line)
{
	light->type = LIGHT;
	light->light_point = parser_vec3(line[1], POINT_ERR);
	light->ratio = check_to_double(line[2]);
	light->rgb = parser_vec3(line[3], RGB_ERR);
}

void	parser_light(char **line)
{
	t_meta			*meta;
	t_spot_light	*light;

	if (ft_arrlen((void **)line) != 4)
		error_handler(LIGHT_ERR);
	light = ft_malloc(sizeof(t_spot_light));
	_set_spot_light_info(light, line);
	meta = singleton();
	if (!_vaildation_light(light))
	{
		free(light);
		ft_free_all_arr(line);
		error_handler(LIGHT_ERR);
	}
	ft_lstadd_back(&(meta->spot_lights), ft_lstnew(light));
}
