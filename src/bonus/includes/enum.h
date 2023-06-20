/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:12:08 by jgo               #+#    #+#             */
/*   Updated: 2023/06/20 17:19:43 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_object_type	t_object_type;
typedef enum e_error_type	t_error_type;
typedef enum e_cy_type		t_cy_type;
typedef enum e_co_type		t_co_type;
typedef enum e_coeff		t_coeff;

enum						e_win
{
	WIN_WIDTH = 400,
	WIN_HEIGHT = 400
};

enum						e_object_type
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

enum						e_axis
{
	X,
	Y,
	Z
};

enum						e_coeff
{
	A,
	B,
	C
};

enum						e_cy_type
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

enum						e_error_type
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
	RGB_ERR
};

#endif
