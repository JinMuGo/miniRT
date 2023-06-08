/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:56:30 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/08 13:55:55 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

void	parser(char *file);
void	parser_error(char *str);
char	**ft_split_whitespace(char const *s);
t_rgb	parse_rgb(char *str);

double	check_to_double(char *str);
bool	check_minus1_to_1(double data);
bool	check_rgb(t_rgb rgb);
bool	check_0_to_1(double data);

#endif
