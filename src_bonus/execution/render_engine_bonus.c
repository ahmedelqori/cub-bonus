/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_engine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:39:31 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/23 10:56:38 by ael-qori         ###   ########.fr       */
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
	draw_gun_to_window(container, &container->bundles.walls.gun);
	long frame_end_time = get_time_in_ms();
    long frame_duration = frame_end_time - frame_start_time;

    if (frame_duration < FRAME_TIME_MS)
    {
        usleep((FRAME_TIME_MS - frame_duration) * 1000); 
    }
	return (SUCCESS);
}
