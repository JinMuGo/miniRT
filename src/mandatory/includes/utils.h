/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:09:46 by jgo               #+#    #+#             */
/*   Updated: 2023/06/11 16:11:04 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "defs.h"

void		destroy(const t_meta *meta);
void		hooks(void *param);

// color.c
t_rgba		rgba_init(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
uint32_t	rgba_to_color(t_rgba rgba);

// atod.c
double		atod(char *str);

// error.c
bool		error_handler(t_error_type type);

// objs.c
void		objsadd_back(t_obj **objs, t_obj *new);
void		objs_clear(t_obj **objs, void (*del)(void *));

#endif
