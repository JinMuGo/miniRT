/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:52:43 by jgo               #+#    #+#             */
/*   Updated: 2023/06/15 12:29:30 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// render
void			render(t_meta *meta);

// sphere
double			get_sphere_dist(t_obj *obj, const t_ray *ray);
t_rgba			get_sphere_color(union u_obj *obj, t_meta *meta, t_record *record);
t_object_type	get_sphere_record(t_obj *obj, t_ray *ray, t_record *record);

// plane
double			get_plane_dist(t_obj *obj, const t_ray *ray);
t_rgba			get_plane_color(union u_obj *obj, t_meta *meta, t_record *record);
t_object_type	get_plane_record(t_obj *obj, t_ray *ray, t_record *record);

// cylinder
double			get_cylinder_dist(t_obj *obj, const t_ray *ray);
t_rgba			get_cylinder_color(union u_obj *obj, t_meta *meta, t_record *record);
t_object_type	get_cylinder_record(t_obj *obj, t_ray *ray, t_record *record);

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
