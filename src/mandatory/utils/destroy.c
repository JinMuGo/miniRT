/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:38:15 by jgo               #+#    #+#             */
/*   Updated: 2023/06/06 18:51:35 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"

void	destroy(const t_meta *meta)
{
	mlx_close_window(meta->mlx_assets.mlx);
	mlx_terminate(meta->mlx_assets.mlx);
	exit(EXIT_SUCCESS);
}
