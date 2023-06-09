/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:33:33 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/09 15:07:51 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "design_patterns.h"
#include "utils.h"

// - `L -40.0,50.0,0.0 0.6 10,0,255`
// - 유형 4개
// - 식별자
// - 빛 점의 좌표
// - [0.0, 1.0] 내의 빛 밝기 비율
// - (보너스)[0~255]의 RGB 색상

static bool	vaildation_light(t_spot_light *light)
{
	if (light->type != LIGHT)
		return (false);
	if (!check_0_to_1(light->ratio)
		|| !check_rgb(light->rgb))
		return (false);
	return (true);
}

void	parser_light(char **line)
{
	t_meta			*meta;
	t_spot_light	*light;

	if (ft_arrlen((void **)line) != 4)
		parser_error("Incorrect number of light information\n");
	light = ft_malloc(sizeof(t_spot_light));
	light->type = LIGHT;
	light->light_point = parser_point3(line[1]);
	light->ratio = check_to_double(line[2]);
	light->rgb = parser_rgb(line[3]);
	if (!vaildation_light(light))
	{
		free(light);
		parser_error("Invaild light\n");
	}
	meta = singleton();
	ft_lstadd_back(&(meta->spot_lights), ft_lstnew(light));
}
