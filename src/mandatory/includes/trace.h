/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:56:36 by jgo               #+#    #+#             */
/*   Updated: 2023/05/28 21:57:07 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "struct.h"
# include "utils.h"

// trace/ray/
t_ray		ray(t_point3 orig, t_vec3 dir);
t_point3	ray_at(t_ray *ray, double t);
t_ray		ray_primary(t_camera *cam, double u, double v);
t_color3	ray_color(t_scene *scene);

// trace/hit/
bool		hit(t_object *obj, t_ray *ray, t_hit_record *rec);
bool		hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);
bool		hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);
void		set_face_normal(t_ray *r, t_hit_record *rec);

t_color3	phong_lighting(t_scene *scene);
t_color3	point_light_get(t_scene *scene, t_light *light);
bool		in_shadow(t_object *objs, t_ray light_ray, double light_len);

#endif