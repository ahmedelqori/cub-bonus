/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_map_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relhamma <relhamma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:01:13 by relhamma          #+#    #+#             */
/*   Updated: 2024/10/23 17:02:58 by relhamma         ###   ########.fr       */
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

int ft_verify_door(char **line, int i, int j)
{
    return ((line[i][j - 1] == '1' && line[i][j + 1] == '1') || (line[i + 1][j] == '1' && line[i - 1][j] == '1'));
}
