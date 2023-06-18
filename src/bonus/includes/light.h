/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:19:04 by jgo               #+#    #+#             */
/*   Updated: 2023/06/16 18:07:33 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

// phong_lighting.c
t_rgba	phong_lighting(t_meta *meta, t_record *record);

// lighting_utils.c
t_vec3	reflect(t_vec3 a, t_vec3 b);
bool	in_shadow(t_obj *objs, t_record *_record, t_vec3 light_dir,
			double light_len);

#endif
