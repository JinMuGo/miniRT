/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:19 by jgo               #+#    #+#             */
/*   Updated: 2023/06/26 21:49:19 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "design_patterns.h"
#include "utils.h"
#include "scene.h"
#include "parser.h"
#include "render.h"
#include "hooks.h"
#include "thread.h"

void	chec(void)
{
	system("leaks miniRT_bonus");
}

int	main(int ac, char **av)
{
	t_meta		*meta;

	if (ac != 2)
		error_handler(ARGS_ERR);
	atexit(chec);
	parser(av[1]);
	meta = singleton();
	print_objs(meta);
	print_camera(meta);
	setup_scene(meta, WIN_WIDTH, WIN_HEIGHT);
	start_thread_render(meta);
	mlx_image_to_window(meta->mlx_assets.mlx, meta->mlx_assets.img, 0, 0);
	hooks(meta);
	mlx_loop(meta->mlx_assets.mlx);
	destroy(meta);
	return (EXIT_SUCCESS);
}
