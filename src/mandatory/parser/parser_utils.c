/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:29:33 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/29 10:00:44 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	check_0_to_1(double data)
{
	return (0.0 <= data && data <= 1.0);
}

bool	check_rgb(t_rgb *rgb)
{
	return (check_0_to_1(rgb->x) && check_0_to_1(rgb->y)
		&& check_0_to_1(rgb->z));
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
