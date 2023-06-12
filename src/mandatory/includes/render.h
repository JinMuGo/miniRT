/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:52:43 by jgo               #+#    #+#             */
/*   Updated: 2023/06/12 14:58:20 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

void	render(t_meta *meta);

double get_sphere_dist(t_obj *obj, const t_ray *ray);
t_rgba get_sphere_color(union u_obj *obj, const t_ray *ray, t_record *record);

// ray
t_ray	ray_init(t_camera *camera, const double ratio[2]);

// hit
bool find_obj_in_pixel(t_obj	*objs, const t_ray *ray, t_record *record);

#endif
