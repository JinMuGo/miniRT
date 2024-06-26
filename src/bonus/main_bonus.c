/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:19 by jgo               #+#    #+#             */
/*   Updated: 2023/06/30 20:13:29 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "defs_bonus.h"
#include "design_patterns_bonus.h"
#include "utils_bonus.h"
#include "scene_bonus.h"
#include "parser_bonus.h"
#include "render_bonus.h"
#include "hooks_bonus.h"
#include "thread_bonus.h"

int	main(int ac, char **av)
{
	t_meta		*meta;

	if (ac != 2)
		error_handler(ARGS_ERR);
	parser(av[1]);
	meta = singleton();
	setup_scene(meta, WIN_WIDTH, WIN_HEIGHT);
	start_thread_render(meta);
	mlx_image_to_window(meta->mlx_assets.mlx, meta->mlx_assets.img, 0, 0);
	hooks(meta);
	mlx_loop(meta->mlx_assets.mlx);
	destroy(meta);
	return (EXIT_SUCCESS);
}
