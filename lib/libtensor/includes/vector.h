/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:53:14 by jgo               #+#    #+#             */
/*   Updated: 2023/06/07 16:45:08 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

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

t_vec3	vec3_init(double x, double y, double z);
t_vec4	vec4_init(double x, double y, double z, double w);

#endif
