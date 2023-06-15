/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:09:46 by jgo               #+#    #+#             */
/*   Updated: 2023/06/15 09:07:14 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "defs.h"

void		destroy(t_meta *meta);
void		hooks(void *param);

// color.c
t_rgba		rgba_init(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
uint32_t	rgba_to_color(t_rgba rgba);
t_rgba		rgba_scalar_multi(t_rgba rgba, double scalar);
t_rgba		rgba_multi(t_rgba a, t_rgba b);

// atod.c
double		atod(char *str);

// error.c
bool		error_handler(t_error_type type);

// objs.c
void		objsadd_back(t_obj **objs, t_obj *new);
void		objs_clear(t_obj **objs, void (*del)(void *));

#endif
