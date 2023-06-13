/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:43:06 by jgo               #+#    #+#             */
/*   Updated: 2023/06/13 15:24:07 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "utils.h"

bool	clip_dot(const int x, const int y)
{
	if (x < 0 || x > WIN_WIDTH)
		return (true);
	if (y < 0 || y > WIN_HEIGHT)
		return (true);
	return (false);
}

int	delta_init(t_vec3 *delta, t_vec3 start, t_vec3 end)
{
	int	dis;

	*delta = vec3_minus(end, start);
	dis = sqrt((delta->x * delta->x) + (delta->y * delta->y));
	*delta = vec3_scalar_divide(*delta, dis);
	return (dis);
}

void	connect_vec3_between(t_meta *meta, t_vec3 start, t_vec3 end, t_rgba color)
{
	t_vec3	delta;
	t_vec3	index;
	int		len;

	len = delta_init(&delta, start, end);
	index = start;
	while (len)
	{
		if (clip_dot(index.x, index.y))
			return ;
		mlx_put_pixel(meta->mlx_assets.img, index.x, index.y, rgba_to_color(color));
		index.x += delta.x;
		index.y += delta.y;
		len--;
	}
}

void	draw_axis(t_meta *meta)
{
	const t_vec3	axis_vec3[AXIS_SIZE] = {vec3_init(AXIS_OFFSET, 0, 0), vec3_init(-AXIS_OFFSET, 0, 0), vec3_init(0, AXIS_OFFSET, 0), vec3_init(0, -AXIS_OFFSET, 0), vec3_init(0, 0, AXIS_OFFSET), vec3_init(0, 0, -AXIS_OFFSET), vec3_init(0, 0, 0)};
	const t_rgba	axis_color3[3] = {rgba_init(255, 0, 0, 255), rgba_init(0, 255, 0, 255), rgba_init(0, 0, 255, 255)};
	const t_vec3	src_vec3 = vec3_init(WIN_WIDTH / 2, WIN_HEIGHT / 2, 0);
	t_rgba			put_color;
	int		i;

	i = 0;
	while (i < 6)
	{
		if (i < 2)
			put_color = axis_color3[0];
		else if (2 <= i && i < 4)
			put_color = axis_color3[1];
		else
			put_color = axis_color3[2];
		connect_vec3_between(meta, vec3_plus(src_vec3, axis_vec3[6]), vec3_plus(src_vec3, axis_vec3[i]), put_color);
		i++;
	}
}

