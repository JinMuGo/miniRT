/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:52:57 by jgo               #+#    #+#             */
/*   Updated: 2023/06/18 20:12:25 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "design_patterns.h"
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
	if (type == EX_ERR)
		print_error_msg(ERR_INVALID_EX);
	if (type == TYPE_ERR)
		print_error_msg(ERR_INVALID_TYPE);
	free_all();
	exit(EXIT_FAILURE);
}

bool	error_handler(t_error_type type)
{
	if (type == ARGS_ERR)
		print_error_msg(ERR_ARGS);
	if (type == OPEN_ERR)
		print_error_msg(ERR_OPEN);
	else
		error_parser(type);
	return (EXIT_FAILURE);
}
