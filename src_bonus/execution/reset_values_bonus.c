/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_values_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:03:59 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/22 22:11:06 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

void	initialize_to_zero(t_container *container)
{
	ft_memset(&container->mouvements, 0, sizeof(container->mouvements));
	ft_memset(&container->player, 1, sizeof(t_playerentity));
	ft_memset(&container->mouse, 0, sizeof(bool));
}
