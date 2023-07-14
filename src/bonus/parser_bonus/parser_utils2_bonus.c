/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:47:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/14 11:14:35 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "parser_bonus.h"
#include "utils_bonus.h"
#include "design_patterns_bonus.h"

bool	check_normal_vec(t_vec3 vector)
{
	if (!check_minus1_to_1(vector.x) || !check_minus1_to_1(vector.y)
		|| !check_minus1_to_1(vector.z) || (vector.x == 0 && vector.y == 0
			&& vector.z == 0))
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
	const size_t	start = ft_strlen(path) - 4;

	if (ft_strnstr(path + start, ".xpm", 4))
		img->type = XPM;
	else if (ft_strnstr(path + start, ".png", 4))
		img->type = PNG;
	else
		error_handler(err);
	img->texture = ft_malloc(sizeof(t_texture));
	if (img->type == PNG)
		img->texture->img.img = mlx_png_file_to_image(
				singleton()->mlx_assets.mlx,
				(char *)path, &img->texture->width, &img->texture->height);
	else if (img->type == XPM)
		img->texture->img.img = mlx_xpm_file_to_image(
				singleton()->mlx_assets.mlx,
				(char *)path, &img->texture->width, &img->texture->height);
	else
		error_handler(err);
	if (img->texture->img.img == NULL)
		error_handler(err);
	img->texture->img.addr = mlx_get_data_addr(img->texture->img.img,
			&img->texture->img.bits_per_pixel,
			&img->texture->img.line_length, &img->texture->img.endian);
}
