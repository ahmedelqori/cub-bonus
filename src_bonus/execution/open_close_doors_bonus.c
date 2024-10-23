/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_doors_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:23:30 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/23 13:00:24 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

static int	get_size_of_matrix(char **str);
void	open_or_close_doors(t_container *container) // Fix this
{
	int mapx;
	int mapy;
	
	double deltaX, deltaY;
	double sideX, sideY;
	int stepx = 0, stepy = 0;

	
	mapx = floor(container->player.pos.horz);
	mapy = floor(container->player.pos.vert);
	if (container->player.dir.horz == 0)
		deltaX = MAXDOUBLE;
	else
		deltaX = fabs(1 / container->player.dir.horz);
	if (container->player.dir.vert == 0)
		deltaY = MAXDOUBLE;
	else
		deltaY = fabs(1 / container->player.dir.vert);
	if (container->player.dir.horz < 0)
	{
		stepx = -1;
		sideX = (container->player.pos.horz - mapx) * deltaX;
	}
	else
	{
		stepx = 1;
		sideX = (mapx + 1.0f - container->player.pos.horz) * deltaX;
	}
	if (container->player.dir.vert < 0)
	{
		stepy = -1;
		sideY = (container->player.pos.vert - mapy) * deltaY;
	}
	else
	{
		stepy = 1;
		sideY = (mapy + 1.0f - container->player.pos.vert)
			* deltaY;
	}
	while (1)
	{
		if (sideX < sideY)
		{
			sideX += deltaX;
			mapx += stepx;
		}
		else
		{
			sideY += deltaY;
			mapy += stepy;
		}
		if (mapx < 0 || mapy < 0 || \
			mapy >= \
				get_size_of_matrix(container->data->map) || \
			mapx >= (int)ft_strlen(
				container->data->map[mapy]))
			break;
		else if (container->data->map[mapy][mapx] == '1')
			break;
		else if (container->data->map[mapy][mapx] == 'C')
		{
			container->data->map[mapy][mapx] = 'O';
			break;
		}
		else if (container->data->map[mapy][mapx] == 'O')
		{
			container->data->map[mapy][mapx] = 'C';
			break;
		}
		
	}
	container->mouvements[7] = FALSE;
}

static int	get_size_of_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
