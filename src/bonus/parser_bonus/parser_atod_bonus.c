/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_atod_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:29:33 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/30 19:14:27 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "utils_bonus.h"

double	check_to_double(char *str)
{
	int	len;
	int	i;
	int	dot_cnt;

	if (str == NULL)
		return (0);
	len = ft_strlen(str);
	i = -1;
	dot_cnt = 0;
	if (!ft_strncmp(&str[0], "+", 1) || !ft_strncmp(&str[0], "-", 1))
		i++;
	while (++i < len)
	{
		if (!ft_isdigit(str[i]) && ft_strncmp(&str[i], ".", 1))
			error_handler(POINT_ERR);
		if (!ft_strncmp(&str[i], ".", 1))
			dot_cnt++;
	}
	if (dot_cnt > 1)
		error_handler(POINT_ERR);
	return (atod(str));
}
