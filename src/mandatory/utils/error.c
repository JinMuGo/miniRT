/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:52:57 by jgo               #+#    #+#             */
/*   Updated: 2023/06/09 20:07:16 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"

static inline void	print_error_msg(char *msg)
{
	printf("miniRT: %s\n", msg);
}

bool	error_handler(t_error_type type)
{
	if (type == ARGS_ERR)
		print_error_msg(ERR_ARGS);
	return (EXIT_FAILURE);
}