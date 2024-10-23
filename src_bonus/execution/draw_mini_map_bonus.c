/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:51:58 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/23 14:42:50 by ael-qori         ###   ########.fr       */
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

void draw_square(t_texturedata *img, int x, int y, int size, int color)
{
  int i, j;

  for (i = y; i < y + size; i++)
  {
    for (j = x; j < x + size; j++)
    {
      paint_on_screen_by_pixela(img, j, i, color);
    }
  }
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

static int	get_size_of_matrixa(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


void draw_mini_map(t_container *container)
{
    int minimap_block_size = 15; 
    int player_x = container->player.pos.horz; 
    int player_y = container->player.pos.vert; 
    int map_width = ft_strlen(container->data->map[0]); 
    int map_height = get_size_of_matrixa(container->data->map); 
    int minimap_size = 5; 
    int player_radius = 3; 
    int minimap_radius = minimap_size * minimap_block_size;
    int minimap_center_x = (minimap_size * minimap_block_size);
    int minimap_center_y = (minimap_size * minimap_block_size);
    for (int y = minimap_center_y - minimap_radius; y <= minimap_center_y + minimap_radius; y++)
    {
        for (int x = minimap_center_x - minimap_radius; x <= minimap_center_x + minimap_radius; x++)
        {
            int dx = x - minimap_center_x;
            int dy = y - minimap_center_y;
            if (dx * dx + dy * dy <= minimap_radius * minimap_radius)
            {
                int map_x = player_x + (dx / minimap_block_size);
                int map_y = player_y + (dy / minimap_block_size);

                if (map_x >= 0 && map_x < map_width && map_y >= 0 && map_y < map_height && container->data->map[map_y][map_x] == '1')
                    paint_on_screen_by_pixela(&container->bundles.background, x, y, 0xFFFFFF);
            }
        }
    }

    draw_circle(&container->bundles.background, minimap_center_x, minimap_center_y, player_radius, 0xFF0000); 
}