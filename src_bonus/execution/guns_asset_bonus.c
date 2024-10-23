/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guns_asset_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:18:04 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/23 12:02:36 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

void	guns_asset(t_container *container, t_texturedata *gun) // Fix this
{
	gun->img =  mlx_xpm_file_to_image(container->mlx,"./images/guns.xpm",\
	&gun->width, &gun->height);
	gun->addr = mlx_get_data_addr(gun->img, &gun->bits_per_pixel, \
	&gun->line_length, &gun->endian);
	gun->start_horz = SCREEN_WIDTH / 2 - (gun->width / 2);
	gun->start_vert = SCREEN_HEIGHT / 2 - (gun->height / 2) + 250;
}


void	draw_gun_to_window(t_container *container, t_texturedata *gun)
{
	unsigned int	color;
	int				x;
	int				y;
	int 			px;

	y = 0;
	while (y < gun->height)
	{
		x = gun->width / 2;
		while (x < gun->width)
		{
			px = (y * gun->line_length) + (x * (gun->bits_per_pixel / 8));
			color = *(int *)(gun->addr + px);
			if (color != 0xFF000000)
				mlx_pixel_put(container->mlx, \
				container->win, x + gun->start_horz + 100, y + gun->start_vert + 10 , color);	
			x++;
		}
		y++;
	}
}