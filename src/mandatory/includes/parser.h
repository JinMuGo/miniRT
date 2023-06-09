/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:56:30 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/09 17:20:27 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "defs.h"

void		parser(char *file);
char		**ft_split_whitespace(char const *s);

void		parser_ambient(char **line);
void		parser_camera(char **line);
void		parser_light(char **line);
void		parser_sphere(char **line);
void		parser_plane(char **line);
void		parser_cylinder(char **line);

t_rgb		parser_rgb(char *str);
t_point3	parser_point3(char *str);
t_vec3		parser_vec3(char *str);
double		get_point(char *str, int *i);

double		check_to_double(char *str);

bool		check_minus1_to_1(double data);
bool		check_0_to_1(double data);
bool		check_0_to_180(double data);
bool		check_rgb(t_rgb rgb);
bool		check_comma(char *str);

void		parser_error(char *str);

void		print_ambient(t_meta *meta);
void		print_camera(t_meta *meta);
void		print_light(t_meta *meta);
void		print_objs(t_meta *meta);
#endif
