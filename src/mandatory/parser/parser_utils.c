/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:29:33 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/09 15:27:42 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	check_0_to_1(double data)
{
	return (data >= 0.0 && data <= 1.0);
}

bool	check_rgb(t_rgb rgb)
{
	return ((rgb.r >= 0.0 && rgb.r <= 255.0) \
		&& (rgb.g >= 0.0 && rgb.g <= 255.0) \
		&& (rgb.b >= 0.0 && rgb.b <= 255.0));
}

bool	check_minus1_to_1(double data)
{
	return (data >= -1.0 && data <= 1.0);
}

bool	check_0_to_180(double data)
{
	return (data >= 0 && data <= 180);
}

bool	check_comma(char *str)
{
	int	com_cnt;
	int	i;

	i = -1;
	com_cnt = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			com_cnt++;
	}
	if (com_cnt != 2)
		return (false);
	return (true);
}
