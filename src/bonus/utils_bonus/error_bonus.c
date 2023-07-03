/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:52:57 by jgo               #+#    #+#             */
/*   Updated: 2023/07/03 17:44:38 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "defs_bonus.h"
#include "design_patterns_bonus.h"
#include "utils_bonus.h"

static inline void	_print_error_msg(const char *msg)
{
	printf("Error\n%s\n", msg);
}

static inline void	_free_all(void)
{
	t_meta	*meta;

	meta = singleton();
	ft_lstclear(&meta->spot_lights, free);
	objs_clear(&meta->objs, free);
	mlx_delete_image(meta->mlx_assets.mlx, meta->mlx_assets.img);
	mlx_terminate(meta->mlx_assets.mlx);
	if (meta->fd != -1)
		close(meta->fd);
	free(meta);
}

static inline void	_error_parser(t_error_type type)
{
	const char	*error_msgs[] = {[ARGS_ERR] = ERR_ARGS, [OPEN_ERR] = ERR_OPEN,
	[EX_ERR] = ERR_INVALID_EX, [TYPE_ERR] = ERR_INVALID_TYPE,
	[AMB_ERR] = ERR_AMB, [LIGHT_ERR] = ERR_LIGHT, [CAM_ERR] = ERR_CAM,
	[SP_ERR] = ERR_SP, [PL_ERR] = ERR_PL, [CY_ERR] = ERR_CY, [CO_ERR] = ERR_CO,
	[POINT_ERR] = ERR_POINT, [VEC_ERR] = ERR_VEC, [RGB_ERR] = ERR_RGB,
	[THD_ERR] = ERR_THD, [OPT_ERR] = ERR_OPT
	};

	if (type >= 0 && type < sizeof(error_msgs) / sizeof(error_msgs[0])
		&& error_msgs[type] != NULL)
		_print_error_msg(error_msgs[type]);
	_free_all();
	exit(EXIT_FAILURE);
}

void	error_handler(t_error_type type)
{
	if (type == ARGS_ERR)
		_print_error_msg(ERR_ARGS);
	else if (type == EX_ERR)
		_print_error_msg(ERR_INVALID_EX);
	else if (type == OPEN_ERR)
		_print_error_msg(ERR_OPEN);
	else
		_error_parser(type);
	exit(EXIT_FAILURE);
}
