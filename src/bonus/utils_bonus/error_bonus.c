/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:52:57 by jgo               #+#    #+#             */
/*   Updated: 2023/06/30 19:35:15 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "defs_bonus.h"
#include "design_patterns_bonus.h"
#include "utils_bonus.h"

static inline void	print_error_msg(const char *msg)
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
	const char	*error_msgs[] = {[ARGS_ERR] = ERR_ARGS, [OPEN_ERR] = ERR_OPEN,
	[EX_ERR] = ERR_INVALID_EX, [TYPE_ERR] = ERR_INVALID_TYPE,
	[AMB_ERR] = ERR_AMB, [LIGHT_ERR] = ERR_LIGHT, [CAM_ERR] = ERR_CAM,
	[SP_ERR] = ERR_SP, [PL_ERR] = ERR_PL, [CY_ERR] = ERR_CY, [CO_ERR] = ERR_CO,
	[POINT_ERR] = ERR_POINT, [VEC_ERR] = ERR_VEC, [RGB_ERR] = ERR_RGB
	};

	if (type >= 0 && type < sizeof(error_msgs) / sizeof(error_msgs[0])
		&& error_msgs[type] != NULL)
		print_error_msg(error_msgs[type]);
	free_all();
	exit(EXIT_FAILURE);
}

void	error_handler(t_error_type type)
{
	if (type == ARGS_ERR)
		print_error_msg(ERR_ARGS);
	if (type == OPEN_ERR)
		print_error_msg(ERR_OPEN);
	if (type == THD_ERR)
		print_error_msg(ERR_THD);
	if (type == OPT_ERR)
		print_error_msg(ERR_OPT);
	else
		error_parser(type);
	exit(EXIT_FAILURE);
}
