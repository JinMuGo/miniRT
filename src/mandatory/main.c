/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:19 by jgo               #+#    #+#             */
/*   Updated: 2023/05/25 18:25:06 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "design_patterns.h"
#include "utils.h"

int	main(int ac, char **av)
{
	t_meta	*meta;

	(void)ac;
	(void)av;
	meta = singleton();
	hooks(meta);
	mlx_put_image_to_window(\
		meta->mlx.mlx, meta->mlx.win, meta->mlx.img.img, 0, 0);
	mlx_loop(meta->mlx.mlx);
	return (EXIT_SUCCESS);
}
