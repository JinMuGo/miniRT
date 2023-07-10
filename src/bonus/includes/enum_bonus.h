/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:12:08 by jgo               #+#    #+#             */
/*   Updated: 2023/07/10 11:33:24 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_BONUS_H
# define ENUM_BONUS_H

typedef enum e_object_type		t_object_type;
typedef enum e_error_type		t_error_type;
typedef enum e_cy_type			t_cy_type;
typedef enum e_co_type			t_co_type;
typedef enum e_coeff			t_coeff;
typedef enum e_obj_option_type	t_obj_option_type;
typedef enum e_mlx_image_type	t_mlx_image_type;

enum							e_win
{
	WIN_WIDTH = 1080,
	WIN_HEIGHT = 720
};

enum							e_mlx_image_type
{
	XPM,
	PNG
};

enum							e_object_type
{
	NONE,
	AMB,
	CAM,
	LIGHT,
	SP,
	PL,
	CY,
	CO
};

enum							e_obj_option_type
{
	CB = 1,
	BP,
	TX
};

enum							e_axis
{
	X,
	Y,
	Z
};

enum							e_coeff
{
	A,
	B,
	C
};

enum							e_cy_type
{
	TOP,
	BOT,
	TUBE
};

enum							e_co_type
{
	SIDE,
	BASE
};

enum							e_error_type
{
	ARGS_ERR,
	OPEN_ERR,
	EX_ERR,
	TYPE_ERR,
	AMB_ERR,
	LIGHT_ERR,
	CAM_ERR,
	SP_ERR,
	PL_ERR,
	CY_ERR,
	CO_ERR,
	POINT_ERR,
	VEC_ERR,
	RGB_ERR,
	THD_ERR,
	OPT_ERR,
	MAN_ERR,
	HOOK_ERR
};

#endif
