/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:22:17 by jgo               #+#    #+#             */
/*   Updated: 2023/06/07 17:04:31 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "struct.h"
# include "utils.h"

t_canvas	canvas(int width, int height);
t_camera	camera(t_canvas *canvas, t_point3 origin);
t_object	*object(t_object_type type, void *element, t_color3 albedo);
t_sphere	*sphere(t_point3 center, double radius);
t_light		*light_point(t_point3 light_origin, t_color3 light_color,
				double bright_ratio);

#endif
