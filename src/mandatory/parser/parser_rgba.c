/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_rgba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:07:55 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/15 12:33:34 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"

t_rgba	parser_rgba(char *str)
{
	int	i;

	if (!check_comma(str))
		parser_error("Invaild information in RGB\n");
	i = 0;
	return (rgba_init_int(
			get_point(str, &i),
			get_point(str, &i),
			get_point(str, &i),
			255));
}
