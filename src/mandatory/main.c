/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:19 by jgo               #+#    #+#             */
/*   Updated: 2023/06/15 17:38:04 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "design_patterns.h"
#include "utils.h"
#include "scene.h"
#include "parser.h"
#include "render.h"

void check_leaks(void)
{
	system("leaks miniRT");
}

void	resize_hook(int32_t width, int32_t height, void *param)
{
	const t_meta *meta = param;
	printf("width %d height %d\n", width, height);

	setup_scene(meta, width, height);
	render(meta);
	mlx_image_to_window(meta->mlx_assets.mlx, meta->mlx_assets.img, 0, 0);
}

int	main(int ac, char **av)
{
	t_meta	*meta;

	atexit(check_leaks);
	if (ac != 2)
		return (error_handler(ARGS_ERR));
	parser(av[1]);
	meta = singleton();
	print_camera(meta);
	setup_scene(meta, WIN_WIDTH, WIN_HEIGHT);
	render(meta);
	mlx_image_to_window(meta->mlx_assets.mlx, meta->mlx_assets.img, 0, 0);
	mlx_resize_hook(meta->mlx_assets.mlx, resize_hook, meta);
	mlx_loop_hook(meta->mlx_assets.mlx, hooks, meta);
	mlx_loop(meta->mlx_assets.mlx);
	destroy(meta);
	return (EXIT_SUCCESS);
}
