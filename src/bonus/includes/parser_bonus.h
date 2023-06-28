/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:56:30 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/26 20:31:39 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_BONUS_H
# define PARSER_BONUS_H

# include "defs_bonus.h"

void		parser(char *file);

// utils
char		**ft_split_whitespace(char const *s);

// parser scene
void		parser_ambient(char **line);
void		parser_camera(char **line);
void		parser_light(char **line);
void		parser_sphere(char **line);
void		parser_plane(char **line);
void		parser_cylinder(char **line);
void		parser_cone(char **line);

// parser double
t_rgba		parser_rgba(char *str);
t_point3	parser_point3(char *str);
t_vec3		parser_vec3(char *str);
double		get_point(char *str, int *i);
double		check_to_double(char *str);

// vaildation
bool		check_minus1_to_1(double data);
bool		check_0_to_1(double data);
bool		check_0_to_180(double data);
bool		check_rgba(t_rgba rgba);
bool		check_comma(char *str);
bool		check_normal_vec(t_vec3 vector);
bool		vaildation_option(t_obj_option *option);
void		open_mlx_image(t_mlx_image *img, t_error_type err,
				const char *path);
t_obj_option	*option_allocator(char **line, int idx, t_error_type err);

// print
void		print_ambient(t_meta *meta);
void		print_camera(t_meta *meta);
void		print_light(t_meta *meta);
void		print_objs(t_meta *meta);
#endif
