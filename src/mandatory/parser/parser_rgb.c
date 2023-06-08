/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:07:55 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/08 13:23:35 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "utils.h"
#include "parser.h"

static bool	check_comma(char *str)
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
	if (com_cnt > 2)
		return (false);
	return (true);
}

static int	get_rgb(char *str, int *i)
{
	int		len;
	char	*tmp;
	int		j;

	if (str[*i] == '\0')
		return (0);
	len = 0;
	while (str[*i] != ',' && str[*i] != '\0')
	{
		len++;
		(*i)++;
	}
	if (len == 0)
		return (0);
	tmp = ft_malloc(len + 1);
	tmp[len] = '\0'; 
	j = 0;
	while (len > 0)
		tmp[j++] = str[(*i) - (len--)];
	return ((int)(check_to_double(tmp) + 0.5));
}

t_rgb	parse_rgb(char *str)
{
	t_rgb	rgb;
	int		i;

	if (!check_comma(str))
		parser_error("Invaild information in RGB");
	i = 0;
	rgb.r = get_rgb(str, &i);
	i++;
	rgb.g = get_rgb(str, &i);
	i++;
	rgb.b = get_rgb(str, &i);
	printf("r: %d, g: %d, b: %d\n", rgb.r, rgb.g, rgb.b);
	return (rgb);
}
