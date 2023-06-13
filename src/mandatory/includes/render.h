/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:52:43 by jgo               #+#    #+#             */
/*   Updated: 2023/06/13 18:45:51 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// render
void			render(t_meta *meta);

// sphere
double			get_sphere_dist(t_obj *obj, const t_ray *ray);
t_rgba			get_sphere_color(union u_obj *obj);
t_object_type	get_sphere_record(t_obj *obj, t_ray *ray, t_record *record);

// ray
t_ray			ray_init(t_camera *camera, const double ratio[2]);
t_point3		ray_at(t_ray *ray, double t);
void			set_face_normal(t_ray *ray, t_record *record);

// hit
bool			find_obj_in_pixel(t_obj *objs, const t_ray *ray,
					t_record *record);

// utils
t_vec3			get_unit_normal_vec(t_vec3 a, t_vec3 b, double scalar);

#endif
