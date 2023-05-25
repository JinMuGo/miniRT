/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:08:41 by jgo               #+#    #+#             */
/*   Updated: 2023/05/25 18:25:27 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "utils.h"

static inline int	key_press(int key, t_meta *meta)
{
	if (key == KEY_ESC)
		destroy(meta);
	return (0);
}

static inline int	destroy_notify(t_meta *meta)
{
	destroy(meta);
	return (0);
}

void	hooks(t_meta *meta)
{
	mlx_hook(meta->mlx.win, KEY_PRESS, 0, key_press, meta);
	mlx_hook(meta->mlx.win, DESTROY_NOTIFY, 0, destroy_notify, meta);
}
