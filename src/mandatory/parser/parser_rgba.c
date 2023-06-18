/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_rgba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:07:55 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/18 18:03:09 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"

t_rgba	parser_rgba(char *str)
{
	int	i;

	if (!check_comma(str))
		error_handler(RGB_ERR);
	i = 0;
	return (rgba_init_int(
			get_point(str, &i),
			get_point(str, &i),
			get_point(str, &i),
			255));
}
