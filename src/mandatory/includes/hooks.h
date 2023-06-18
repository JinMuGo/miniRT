/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:33:48 by jgo               #+#    #+#             */
/*   Updated: 2023/06/18 17:45:34 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

void	camera_key_hooks(mlx_key_data_t keydata, t_meta *meta);
void	camera_cursor_hooks(const double pos[2], t_meta *meta);

void	hooks(t_meta *meta);

#endif
