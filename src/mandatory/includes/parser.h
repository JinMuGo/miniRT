/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:56:30 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/08 16:56:16 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "defs.h"

void		parser(char *file);
char		**ft_split_whitespace(char const *s);
void		parse_ambient(char **line);
void		parse_camera(char **line);

t_rgb		parse_rgb(char *str);
t_point3	parse_point3(char *str);
t_vec3		parse_vec3(char *str);
double		get_point(char *str, int *i);

double		check_to_double(char *str);

bool		check_minus1_to_1(double data);
bool		check_0_to_1(double data);
bool		check_0_to_180(double data);
bool		check_rgb(t_rgb rgb);
bool		check_comma(char *str);

void		parser_error(char *str);
#endif
