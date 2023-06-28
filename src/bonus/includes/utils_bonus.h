/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:09:46 by jgo               #+#    #+#             */
/*   Updated: 2023/06/25 23:08:11 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "defs_bonus.h"

void		destroy(t_meta *meta);

// color.c
t_rgba		rgba_init_int(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
t_rgba		rgba_init_double(double r, double g, double b, double a);
t_rgba		rgba_scalar_minus(t_rgba a, double scalar);
uint32_t	rgba_to_color(t_rgba rgba);
t_rgba		color_to_rgba(uint8_t *color);
t_rgba		rgba_scalar_multi(t_rgba rgba, double scalar);
t_rgba		rgba_scalar_divide(t_rgba rgba, double scalar);
t_rgba		rgba_multi(t_rgba a, t_rgba b);
t_rgba		rgba_plus(t_rgba a, t_rgba b);
t_rgba		rgba_min(t_rgba a, t_rgba b);

// atod.c
double		atod(char *str);

// error.c
void		error_handler(t_error_type type);

// objs.c
void		objsadd_back(t_obj **objs, t_obj *new);
void		objs_clear(t_obj **objs, void (*del)(void *));

// number.c
double		clamp(const double x, const double min, const double max);
float		float_modulo(const float x);

#endif
