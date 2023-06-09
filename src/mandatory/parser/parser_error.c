/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:41:28 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/09 17:29:54 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"
#include "defs.h"
#include "design_patterns.h"

void	parser_error(char *str)
{
	t_meta	*meta;

	printf("Error\n%s", str);

	meta = singleton();
	ft_lstclear(&meta->spot_lights, free);
	ft_lstclear(&meta->objs, free);
	free(meta);
	system("leaks miniRT");
	exit(1);
}
