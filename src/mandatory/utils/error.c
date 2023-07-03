/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:52:57 by jgo               #+#    #+#             */
/*   Updated: 2023/07/03 14:52:48 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "design_patterns.h"
#include "minirt.h"
#include "utils.h"

static inline void	print_error_msg(char *msg)
{
	printf("Error\n%s\n", msg);
}

static inline void	free_all(void)
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

static inline void	error_parser(t_error_type type)
{
	if (type == AMB_ERR)
		print_error_msg(ERR_AMB);
	if (type == LIGHT_ERR)
		print_error_msg(ERR_LIGHT);
	if (type == CAM_ERR)
		print_error_msg(ERR_CAM);
	if (type == SP_ERR)
		print_error_msg(ERR_SP);
	if (type == PL_ERR)
		print_error_msg(ERR_PL);
	if (type == CY_ERR)
		print_error_msg(ERR_CY);
	if (type == POINT_ERR)
		print_error_msg(ERR_POINT);
	if (type == VEC_ERR)
		print_error_msg(ERR_VEC);
	if (type == RGB_ERR)
		print_error_msg(ERR_RGB);
	if (type == TYPE_ERR)
		print_error_msg(ERR_INVALID_TYPE);
	free_all();
	exit(EXIT_FAILURE);
}

void	error_handler(t_error_type type)
{
	if (type == ARGS_ERR)
		print_error_msg(ERR_ARGS);
	else if (type == EX_ERR)
		print_error_msg(ERR_INVALID_EX);
	else if (type == OPEN_ERR)
		print_error_msg(ERR_OPEN);
	else
		error_parser(type);
	exit(EXIT_FAILURE);
}
