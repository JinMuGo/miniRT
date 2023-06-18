/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:56:37 by jgo               #+#    #+#             */
/*   Updated: 2023/06/18 12:13:56 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"

double	clamp(const double x, const double min, const double max)
{
	if (x < min)
		return (min);
	else if (x > max)
		return (max);
	else
		return (x);
}