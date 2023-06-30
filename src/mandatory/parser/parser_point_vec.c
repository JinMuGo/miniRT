/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_point_vec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:24:25 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/29 09:56:20 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"

double	get_point(char *str, int *i)
{
	char	*tmp;
	int		start;
	double	res;

	if (str[*i] == '\0')
		return (0);
	start = *i;
	res = 0;
	while (str[*i] != ',' && str[*i] != '\0')
		(*i)++;
	if (*i != start)
	{
		tmp = ft_substr(str, start, *i - start);
		res = check_to_double(tmp);
		free(tmp);
	}
	(*i)++;
	return (res);
}

t_vec3	parser_vec3(char *str, t_error_type err)
{
	int	i;

	if (!check_comma(str))
		error_handler(err);
	i = 0;
	if (err == RGB_ERR)
		return (rgba_init_int(
				get_point(str, &i),
				get_point(str, &i),
				get_point(str, &i)));
	else
		return (vec3_init(
				get_point(str, &i),
				get_point(str, &i),
				get_point(str, &i)));
}
