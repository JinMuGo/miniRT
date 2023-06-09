/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:19 by jgo               #+#    #+#             */
/*   Updated: 2023/06/09 19:00:14 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "design_patterns.h"
#include "utils.h"
#include "parser.h"

void	check_leaks(void)
{
	system("leaks miniRT");
}

int	main(int ac, char **av)
{
	t_meta	*meta;

	atexit(check_leaks);
	if (ac != 2)
		return (0);
	parser(av[1]);
	meta = singleton();

	print_ambient(meta);
	print_camera(meta);
	print_light(meta);
	print_objs(meta);

	mlx_image_to_window(meta->mlx_assets.mlx, meta->mlx_assets.img, 0, 0);
	mlx_loop_hook(meta->mlx_assets.mlx, hooks, meta);
	mlx_loop(meta->mlx_assets.mlx);
	ft_lstclear(&meta->spot_lights, free);
	ft_lstclear(&meta->objs, free);
	return (EXIT_SUCCESS);
}
