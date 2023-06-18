/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:49:21 by jgo               #+#    #+#             */
/*   Updated: 2023/06/17 16:00:29 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENSOR_H
# define TENSOR_H

# include <math.h>
# include <stdbool.h>

# define EPSILON 1e-6

typedef struct s_vec3	t_vec3;
typedef struct s_vec4	t_vec4;
typedef struct s_mat4	t_mat4;
typedef struct s_mat3	t_mat3;

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

struct					s_mat4
{
	t_vec4				a;
	t_vec4				b;
	t_vec4				c;
	t_vec4				d;
};

struct					s_mat3
{
	t_vec3				a;
	t_vec3				b;
	t_vec3				c;
};

// oper
t_vec3					vec3_init(double x, double y, double z);
t_vec4					vec4_init(double x, double y, double z, double w);
t_vec3					vec3_plus(t_vec3 a, t_vec3 b);
t_vec3					vec3_minus(t_vec3 a, t_vec3 b);
t_vec3					vec3_multi(t_vec3 a, t_vec3 b);
t_vec3					vec3_cross_product(t_vec3 a, t_vec3 b);
double					vec3_inner_product(t_vec3 a, t_vec3 b);

// oper2
t_vec3					vec3_scalar_divide(t_vec3 vec3, double scalar);
t_vec3					vec3_scalar_multi(t_vec3 vec3, double scalar);

// utils
double					vec3_square_length(t_vec3 vec3);
double					vec3_length(t_vec3 vec3);
t_vec3					vec3_unit(t_vec3 vec3);
t_vec3					vec3_scale(t_vec3 vec3, float s);

double					degree_to_radian(double degree);

bool					root_formula(double a, double b, double c,
							double root[2]);

// vec4_oper

t_vec4					vec4_plus(t_vec4 a, t_vec4 b);
t_vec4					vec4_scalar_multi(t_vec4 vec4, double scalar);

//  vec4_utils
t_vec3					vec4_to_vec3(t_vec4 from);

// mat
t_mat4					mat4_init(t_vec4 a, t_vec4 b, t_vec4 c, t_vec4 d);
t_mat4					mat4_init_one_val(double val);
t_mat3					mat3_init(t_vec3 a, t_vec3 b, t_vec3 c);
t_mat3					mat3_init_one_val(double val);

// mat oper
t_mat4					rotate(t_mat4 m, double radian, t_vec3 v);
t_mat4					mat4_multi(t_mat4 m1, t_mat4 m2);
t_vec4					mat4_vec4_multi(t_mat4 matrix, t_vec4 vector);

#endif
