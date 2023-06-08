/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_atod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:29:33 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/08 16:36:42 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"

double	check_to_double(char *str)
{
	int		len;
	int		i;
	int		dot_cnt;

	len = ft_strlen(str);
	i = -1;
	dot_cnt = 0;
	if (ft_strncmp(&str[i], "+", 1) || ft_strncmp(&str[i], "-", 1))
		i++;
	while (++i < len)
	{
		if (!ft_isdigit(str[i]) && ft_strncmp(&str[i], ".", 1))
			parser_error("Invaild information");
		if (!ft_strncmp(&str[i], ".", 1))
			dot_cnt++;
	}
	if (dot_cnt > 1)
		parser_error("Invaild information");
	return (atod(str));
}
