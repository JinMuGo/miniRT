/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:10:23 by jgo               #+#    #+#             */
/*   Updated: 2023/06/11 20:11:29 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# include "const.h"
# include "enum.h"
# include "struct.h"

typedef double	(*t_get_obj_dist)(t_obj *, const t_ray *, t_record *);
typedef t_rgba	(*t_get_obj_color)(union u_obj *, const t_ray *, t_record *);

#endif
