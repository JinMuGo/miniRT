/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:33:48 by jgo               #+#    #+#             */
/*   Updated: 2023/07/10 14:05:53 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_BONUS_H
# define HOOKS_BONUS_H

void	camera_key_hooks(mlx_key_data_t *keydata, t_meta *meta,
			const t_vec3 init_forward, const t_vec3 init_pos);
void	camera_cursor_hooks(const double pos[2], t_meta *meta);

void	hooks(t_meta *meta);

t_vec3	*get_init_forward_pos(void);

#endif
