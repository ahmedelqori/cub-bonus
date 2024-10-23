/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_the_wall_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:06:34 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/23 18:18:23 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

void	check_hit(t_container *container)
{
	container->player.open = FALSE;
	while (container->player.hit == 0)
	{
		if (container->player.sidedist.horz < container->player.sidedist.vert)
		{
			container->player.sidedist.horz += container->player.delta.horz;
			container->player.mapx += container->player.stepx;
			container->player.side = 0;
		}
		else
		{
			container->player.sidedist.vert += container->player.delta.vert;
			container->player.mapy += container->player.stepy;
			container->player.side = 1;
		}
		if (container->player.mapx < 0 || container->player.mapy < 0 || \
			container->player.mapy >= container->height || \
			container->player.mapx >= container->width)
			container->player.hit = 2;
		else if (container->data->map[container->player.mapy] \
		[container->player.mapx] == '1')
			container->player.hit = 1;
		else if (container->data->map[container->player.mapy] \
		[container->player.mapx] == 'C')
			container->player.hit = 3;
		else if (container->data->map[container->player.mapy] \
		[container->player.mapx] == 'O')
		{
			container->player.hit = 4;
			container->player.open = TRUE;
		}
	}
}