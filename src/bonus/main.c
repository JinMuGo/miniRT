/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:19 by jgo               #+#    #+#             */
/*   Updated: 2023/06/20 15:12:44 by sanghwal         ###   ########seoul.kr  */
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

int	main(int ac, char **av)
{
	t_meta		*meta;

	if (ac != 2)
		return (error_handler(ARGS_ERR));
	parser(av[1]);
	meta = singleton();
	print_objs(meta);
	setup_scene(meta, WIN_WIDTH, WIN_HEIGHT);
	render(meta);
	hooks(meta);
	mlx_loop(meta->mlx_assets.mlx);
	destroy(meta);
	return (EXIT_SUCCESS);
}
