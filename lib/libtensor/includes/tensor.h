/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:49:21 by jgo               #+#    #+#             */
/*   Updated: 2023/06/12 18:51:40 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENSOR_H
#define TENSOR_H

#include <math.h>
#include <stdbool.h>

# define EPSILON 1e-6

typedef struct s_vec3	t_vec3;
typedef struct s_vec4	t_vec4;

struct					s_vec3
{
	double				x;
	double				y;
	double				z;
};

struct					s_vec4
{
	double				x;
	double				y;
	double				z;
	double				w;
};

// oper
t_vec3	vec3_init(double x, double y, double z);
t_vec4	vec4_init(double x, double y, double z, double w);
t_vec3	vec3_plus(t_vec3 a, t_vec3 b);
t_vec3	vec3_minus(t_vec3 a, t_vec3 b);
t_vec3	vec3_multi(t_vec3 a, t_vec3 b);
t_vec3	vec3_cross_product(t_vec3 a, t_vec3 b);
double	vec3_inner_product(t_vec3 a, t_vec3 b);

// oper2
t_vec3	vec3_scalar_divide(t_vec3 vec3, double scalar);
t_vec3	vec3_scalar_multi(t_vec3 vec3, double scalar);

// utils
double	vec3_square_length(t_vec3 vec3);
double	vec3_length(t_vec3 vec3);
t_vec3	vec3_unit(t_vec3 vec3);


double	degree_to_radian(double degree);

bool	root_formula(double a, double b, double c, double root[2]);

#endif
