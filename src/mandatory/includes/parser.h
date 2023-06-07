/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:56:30 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/07 15:30:11 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

void	parser(char *file);
void	parser_error(char *str);
char	**ft_split_whitespace(char const *s);


double	check_to_double(char *str);
double	atod(char *str);

#endif
