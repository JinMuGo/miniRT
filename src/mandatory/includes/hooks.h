/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:33:48 by jgo               #+#    #+#             */
/*   Updated: 2023/07/13 14:14:43 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

void	camera_key_hooks(const int keydata, t_meta *meta);
void	camera_mouse_hooks(const int pos[2], t_meta *meta);
int		mouse_move(int xpos, int ypos, t_meta *meta);

void	hooks(t_meta *meta);

t_vec3	*get_init_forward_pos(void);

#endif
