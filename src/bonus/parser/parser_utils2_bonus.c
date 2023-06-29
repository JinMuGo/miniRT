/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:47:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/29 16:11:10 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "design_patterns_bonus.h"
#include "utils_bonus.h"

bool	check_normal_vec(t_vec3 vector)
{
	if (!check_minus1_to_1(vector.x)
		|| !check_minus1_to_1(vector.y)
		|| !check_minus1_to_1(vector.z)
		|| (vector.x == 0 && vector.y == 0 && vector.z == 0))
		return (false);
	return (true);
}

bool	vaildation_option(t_obj_option *option)
{
	if (option == NULL)
		return (true);
	if (option->type == CB)
	{
		if (option->op.cb.degree < 0 || !check_rgb(&option->op.cb.rgb)
			|| !check_0_to_1(option->op.cb.scale_s)
			|| !check_0_to_1(option->op.cb.scale_t))
			return (false);
	}
	return (true);
}

void	open_mlx_image(t_mlx_image *img, t_error_type err, const char *path)
{
	const size_t	path_len = ft_strlen(path);
	const size_t	xpm_start = path_len - 6;
	const size_t	png_start = path_len - 4;
	mlx_texture_t	*texture;

	if (ft_strnstr(path + xpm_start, ".xpm42", 6))
		img->type = XPM;
	else if (ft_strnstr(path + png_start, ".png", 4))
		img->type = PNG;
	else
		error_handler(err);
	texture = NULL;
	if (img->type == PNG)
		texture = mlx_load_png(path);
	else if (img->type == XPM)
		texture = &mlx_load_xpm42(path)->texture;
	else
		error_handler(err);
	if (texture == NULL)
		error_handler(err);
	img->img = mlx_texture_to_image(singleton()->mlx_assets.mlx, texture);
	mlx_delete_texture(texture);
	if (img->img == NULL)
		error_handler(err);
}
