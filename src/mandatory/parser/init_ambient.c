/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ambient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:55:28 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/06 18:17:02 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "defs.h"
#include "utils.h"
#include "design_patterns.h"

double	check_and_to_double(char *str);

void	init_ambient(char **line)
{
	t_meta	*meta;
	t_ambient	amb;
	char		**temp;

	if (ft_arrlen(line) != 3)
		parser_error("Incorrect number of ambient information\n");
	amb.type = AMB;
	amb.ratio = check_and_to_double(line[1]);
	temp = check_and_split(line[2]);

	meta = singleton();
	meta->ambient = amb;
}