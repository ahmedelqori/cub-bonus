/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:51:58 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/23 11:02:53 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h" // fix this
void	draw_square(t_container *container, int start_x, int start_y, int size);
void	draw_mini_map(t_container *container)
{
	draw_square(container, 0,0,10);
}
void	paint_on_screen_by_pixela(t_texturedata *img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0x00980088)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_square(t_container *container, int start_x, int start_y, int size)
{
    int current_x;
    int current_y;
    int end_x = start_x + size;
    int end_y = start_y + size;

    current_x = start_x;
    while (current_x < end_x)
    {
        current_y = start_y; 
        while (current_y < end_y)
        {
            paint_on_screen_by_pixela(&container->bundles.background, current_x, current_y, 0xFFFFFF);
            current_y++; 
        }
        current_x++;
    }
}