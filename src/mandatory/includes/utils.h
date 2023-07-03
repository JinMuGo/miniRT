/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:09:46 by jgo               #+#    #+#             */
/*   Updated: 2023/07/03 14:53:01 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "defs.h"

void		destroy(t_meta *meta);

// color.c
t_rgb		rgba_init_int(const int r, const int g, const int b);
uint32_t	rgba_to_color(t_rgb rgb);
t_rgb		rgba_min(t_rgb a, t_rgb b);

// atod.c
double		atod(char *str);

// error.c
void		error_handler(t_error_type type);

// objs.c
void		objsadd_back(t_obj **objs, t_obj *new);
void		objs_clear(t_obj **objs, void (*del)(void *));

// number.c
double		clamp(const double x, const double min, const double max);

#endif
