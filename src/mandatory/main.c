/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:19 by jgo               #+#    #+#             */
/*   Updated: 2023/07/09 14:43:12 by jgo              ###   ########.fr       */
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

static bool	_is_rtfile(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (!ext || ext == file)
		return (false);
	if (ft_strcmp(ext, ".rt"))
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_meta	*meta;

	if (ac != 2)
		error_handler(ARGS_ERR);
	if (!_is_rtfile(av[1]))
		error_handler(EX_ERR);
	parser(open(av[1], O_RDONLY));
	meta = singleton();
	setup_scene(meta, WIN_WIDTH, WIN_HEIGHT);
	render(meta);
	mlx_image_to_window(meta->mlx_assets.mlx, meta->mlx_assets.img, 0, 0);
	hooks(meta);
	mlx_loop(meta->mlx_assets.mlx);
	destroy(meta);
	return (EXIT_SUCCESS);
}
