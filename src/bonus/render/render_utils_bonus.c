/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:03:21 by jgo               #+#    #+#             */
/*   Updated: 2023/06/28 16:05:50 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "defs_bonus.h"
#include "utils_bonus.h"

static inline t_rgba	get_cb_color(const t_rgba rgba, t_obj_option *option, t_point3 *point)
{
	const t_cb	cb = option->op.cb;
	const float	radian = degree_to_radian(cb.degree);
	const float	s = point->x * cos(radian) - point->y * sin(radian);
	const float	t = point->y * cos(radian) + point->x * sin(radian);
	const bool	pattern = (float_modulo(s * 1 / cb.scale_s) < 0.5) ^ (float_modulo(t * 1 / cb.scale_t) < 0.5);

	if (pattern)
		return (rgba);
	else
		return (cb.rgba);
}

static inline t_rgba	get_img_pixel(mlx_image_t *img, const int u, const int v)
{
	const size_t	bpp = sizeof(uint32_t);
	uint8_t			*color;

	color = img->pixels + ((v * img->width + u) * bpp);
	return (color_to_rgba(color));
}

static inline t_rgba _get_tx_img_color(t_tx *tx, mlx_image_t *img)
{
	const int u = clamp(tx->uv.u * img->width, 0, img->width - 1);
	const int v = clamp((1.0 - tx->uv.v) * img->height, 0, img->height -1);

	return (get_img_pixel(img, u, v));
}

static inline t_vec3 _normal_mapping(t_tx *tx, t_record *record)
{
	const t_mat3 tbn = mat3_init(tx->right, tx->up, record->normal_vec3);
	const t_rgba bump_rgba = _get_tx_img_color(tx, tx->bp->img);
	const t_rgba rgba = rgba_scalar_minus(rgba_scalar_multi(bump_rgba, 2), 1);
	const t_vec3 pixel_normal = vec3_init(rgba.r, rgba.g, rgba.b);

	return (vec3_unit(mat3_vec3_multi(&tbn, &pixel_normal)));
}

void	apply_option(t_obj_option *option, t_record *record, t_rgba origin)
{
	if (option->type == CB)
		record->rgba = get_cb_color(origin, option, &record->point);
	else if (option->type == TX)
	{
		record->rgba = _get_tx_img_color(&option->op.tx, option->op.tx.img.img);
		if (option->op.tx.bp)
			record->normal_vec3 = _normal_mapping(&option->op.tx, record);
	}
}
