/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:29:33 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/10 09:42:04 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	check_0_to_1(double data)
{
	return (data >= 0.0 && data <= 1.0);
}

bool	check_rgba(t_rgba rgba)
{
	return ((rgba.r >= 0.0 && rgba.r <= 255.0) \
		&& (rgba.g >= 0.0 && rgba.g <= 255.0) \
		&& (rgba.b >= 0.0 && rgba.b <= 255.0) \
		&& (rgba.a >= 0.0 && rgba.a <= 255.0));
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
