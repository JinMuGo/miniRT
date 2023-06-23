/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:12:08 by jgo               #+#    #+#             */
/*   Updated: 2023/06/22 18:28:03 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_object_type		t_object_type;
typedef enum e_error_type		t_error_type;
typedef enum e_cy_type			t_cy_type;
typedef enum e_co_type		t_co_type;
typedef enum e_coeff			t_coeff;
typedef enum e_obj_option_type	t_obj_option_type;

enum							e_win
{
	WIN_WIDTH = 1080,
	WIN_HEIGHT = 720
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
	BP
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
	INF
};


enum						e_co_type
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
	POINT_ERR,
	VEC_ERR,
	RGB_ERR,
	THD_ERR
};

#endif
