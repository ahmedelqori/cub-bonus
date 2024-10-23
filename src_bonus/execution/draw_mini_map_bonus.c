/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:51:58 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/23 18:19:22 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h" // fix this

void paint_on_screen_by_pixela(t_texturedata *img, int x, int y, int color)
{
  char *dst;

  if (color == (int)0x00980088 || color == (int)16711935)
    return;
  dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
  *(unsigned int *)dst = color;
}

void draw_circle(t_texturedata *img, int center_x, int center_y, int radius, int color)
{
  int x, y;
  int radius_squared = radius * radius;

  for (y = center_y - radius; y <= center_y + radius; y++)
  {
    for (x = center_x - radius; x <= center_x + radius; x++)
    {
      int dx = x - center_x;
      int dy = y - center_y;
      if (dx * dx + dy * dy <= radius_squared)
      {
        paint_on_screen_by_pixela(img, x, y, color);
      }
    }
  }
}




void draw_mini_map(t_container *container)
{
    int minimap_block_size = 15; 
    double player_x = container->player.pos.horz; 
    double player_y = container->player.pos.vert; 
    int map_width = container->width; 
    int map_height = container->height; 
    int minimap_size = 5; 
    int player_radius = 3; 
    double player_minimap_x = minimap_size * minimap_block_size / 2;
    double player_minimap_y = minimap_size * minimap_block_size / 2;

    for (int y = 0; y < minimap_size * 2 * minimap_block_size; y++)
    {
        for (int x = 0; x < minimap_size * 2 * minimap_block_size; x++)
        {
            double dx = (x - player_minimap_x) / (double)minimap_block_size;
            double dy = (y - player_minimap_y) / (double)minimap_block_size;

            int map_x = (int)(player_x + dx);
            int map_y = (int)(player_y + dy);

            if (dx * dx + dy * dy <= minimap_size * minimap_size && map_x >= 0 && map_x < map_width && map_y >= 0 && map_y < map_height)
            {
                if (container->data->map[map_y][map_x] == '1')
                    paint_on_screen_by_pixela(&container->bundles.background, x, y, 0xFFFFFF);
            }
        }
    }
    draw_circle(&container->bundles.background, (int)player_minimap_x, (int)player_minimap_y, player_radius, 0xFF0000);
}
