/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:52:43 by jgo               #+#    #+#             */
/*   Updated: 2023/06/11 12:04:36 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

void	render(t_meta *meta);

double get_sphere_dist(t_list *obj, t_vec3 origin, t_ray dir);

// ray
t_ray	ray_init(t_camera *camera, double ratio[2]);

// hit
bool find_obj_in_pixel(t_obj	*objs, t_ray *ray, t_hit_record *record);

#endif
