/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:19 by jgo               #+#    #+#             */
/*   Updated: 2023/07/14 11:01:13 by jgo              ###   ########.fr       */
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
	t_meta		*meta;

	if (ac != 2)
		error_handler(ARGS_ERR);
	if (!_is_rtfile(av[1]))
		error_handler(EX_ERR);
	parser(open(av[1], O_RDONLY));
	meta = singleton();
	setup_scene(meta, WIN_WIDTH, WIN_HEIGHT);
	start_thread_render(meta);
	hooks(meta);
	mlx_loop(meta->mlx_assets.mlx);
	destroy(meta);
	return (EXIT_SUCCESS);
}
