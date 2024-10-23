/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_engine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:39:31 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/23 10:09:09 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"
 void draw_xpm_image_with_transparency(t_container *container);

#include <sys/time.h> 

long get_time_in_ms()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}
int	update_render(t_container *container)
{
    long frame_start_time = get_time_in_ms(); 

	draw_floor_ceil(container);
	digital_differential_analysis(container);
	handle_movement(container);
	draw_mini_map(container);
	draw_xpm_image_with_transparency(container);
	long frame_end_time = get_time_in_ms();
    long frame_duration = frame_end_time - frame_start_time;

    if (frame_duration < FRAME_TIME_MS)
    {
        usleep((FRAME_TIME_MS - frame_duration) * 1000); 
    }
	return (SUCCESS);
}

void draw_xpm_image_with_transparency(t_container *container)
{
	int start_horz = SCREEN_WIDTH / 2 - (container->bundles.walls.gun.width / 2);
	int start_vert = SCREEN_HEIGHT / 2 - (container->bundles.walls.gun.height / 2) + 250;
	
    for (int y = 0; y < container->bundles.walls.gun.height; y++)
    {
        for (int x = container->bundles.walls.gun.width/ 2; x < container->bundles.walls.gun.width; x++)
        {
            int pixel_index = (y * container->bundles.walls.gun.line_length) + (x * (container->bundles.walls.gun.bits_per_pixel / 8));
            unsigned int color = *(int *)(container->bundles.walls.gun.addr + pixel_index);

            if (color == 0xFF000000) 
                continue; 

            mlx_pixel_put(container->mlx, container->win, x + start_horz, y + start_vert , color);
        }
    }
}