/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_point_vec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:24:25 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/18 20:38:35 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "utils_bonus.h"

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

t_point3	parser_point3(char *str)
{
	int	i;

	if (!check_comma(str))
		error_handler(POINT_ERR);
	i = 0;
	return (vec3_init(
			get_point(str, &i),
			get_point(str, &i),
			get_point(str, &i)));
}

t_vec3	parser_vec3(char *str)
{
	int	i;

	if (!check_comma(str))
		error_handler(VEC_ERR);
	i = 0;
	return (vec3_init(
			get_point(str, &i),
			get_point(str, &i),
			get_point(str, &i)));
}
