/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:07:55 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/08 16:56:31 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser.h"

t_rgb	parse_rgb(char *str)
{
	t_rgb	rgb;
	int		i;

	if (!check_comma(str))
		parser_error("Invaild information in RGB");
	i = 0;
	rgb.r = get_point(str, &i);
	i++;
	rgb.g = get_point(str, &i);
	i++;
	rgb.b = get_point(str, &i);
	return (rgb);
}
