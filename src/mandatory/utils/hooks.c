/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:08:41 by jgo               #+#    #+#             */
/*   Updated: 2023/06/13 14:41:53 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "utils.h"
#include "render.h"

void	hooks(void *param)
{
	t_meta	*meta;

	meta = param;
	if (mlx_is_key_down(meta->mlx_assets.mlx, MLX_KEY_ESCAPE))
		destroy(meta);
	if (mlx_is_key_down(meta->mlx_assets.mlx, MLX_KEY_3))
		meta->key.axis = !meta->key.axis;
	render(meta);
}
