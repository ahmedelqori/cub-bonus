/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_execution_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:48:48 by ael-qori          #+#    #+#             */
/*   Updated: 2024/10/23 10:38:53 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

static void	init_mlx(t_container *container);

void	ft_execute(t_parsing *parsing)
{
	t_container	*container;

	container = malloc(sizeof(t_container));
	if (container == NULL)
		safe_exit(parsing, 1, ALLOC_CONTAINER);
	container->data = parsing;
	container->data->map[5][26] = 'C';
	init_mlx(container);
	initialize_to_zero(container);
	initialize_defaults(container);
	guns_asset(container, &container->bundles.walls.gun);
	handle_events(container);
	mlx_loop_hook(container->mlx, update_render, container);
	mlx_loop(container->mlx);
}

void	init_mlx(t_container *container)
{
	container->mlx = mlx_init();
	container->win = mlx_new_window(container->mlx, \
		SCREEN_WIDTH, SCREEN_HEIGHT, NAME);
}
