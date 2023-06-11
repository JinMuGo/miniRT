/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:19 by jgo               #+#    #+#             */
/*   Updated: 2023/06/11 18:31:48 by jgo              ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_meta	*meta;

	atexit(check_leaks);
	if (ac != 2)
		return (error_handler(ARGS_ERR));
	parser(av[1]);
	meta = singleton();
	print_objs(meta);
	setup_scene(meta);
	render(meta);
	mlx_image_to_window(meta->mlx_assets.mlx, meta->mlx_assets.img, 0, 0);
	mlx_loop_hook(meta->mlx_assets.mlx, hooks, meta);
	mlx_loop(meta->mlx_assets.mlx);
	ft_lstclear(&meta->spot_lights, free);
	objs_clear(&meta->objs, free);
	return (EXIT_SUCCESS);
}
