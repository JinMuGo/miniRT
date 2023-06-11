/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:12:08 by jgo               #+#    #+#             */
/*   Updated: 2023/06/11 14:53:39 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_object_type	t_object_type;
typedef enum e_error_type	t_error_type;

enum						e_win
{
	WIN_WIDTH = 1280,
	WIN_HEIGHT = 720
};

enum						e_object_type
{
	AMB,
	CAM,
	LIGHT,
	SP,
	PL,
	CY,
	NONE
};

enum						e_axis
{
	X,
	Y,
	Z
};

enum						e_error_type
{
	ARGS_ERR
};

#endif