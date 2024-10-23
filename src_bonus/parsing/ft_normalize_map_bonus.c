/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_map_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relhamma <relhamma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:01:13 by relhamma          #+#    #+#             */
/*   Updated: 2024/10/23 15:55:02 by relhamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

int	ft_normalize_map(t_parsing *data)
{
	int	size;
	int	i;

	size = buffer_counting(data->map);
	size -= 1;
	while (size >= 0 && !data->map[size][0])
		free(data->map[size--]);
	data->map[size + 1] = 0;
	i = 0;
	while (i <= size)
	{
		if (!data->map[i][0])
			return (0);
		i++;
	}
	return (1);
}

t_door *ft_new_door(char i, int j, int c)
{
	t_door *door;

	door = malloc(sizeof(t_door));
	door->door_status = i;
	door->door_x = j;
	door->door_y = c;
	return door;
}