/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:14:58 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/20 15:16:34 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "render.h"

double			get_cone_dist(t_obj *obj, const t_ray *ray);
t_object_type	get_cone_record(t_obj *obj, t_ray *ray, t_record *record);

