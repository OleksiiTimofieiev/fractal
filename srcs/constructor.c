/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 09:48:23 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 18:18:40 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	constructor(t_data *data)
{
	int size;
	int	endian;
	int width;

	data->width = MONITOR_WIDTH;
	data->height = MONITOR_HEIGHT;
	data->max_iterations = MAX_ITERATIONS;
	data->zoom = 1;
	data->move_x = -0.5;
	data->move_y = 0;
	data->zoom = 1;
	data->c_re = -0.7;
	data->c_im = 0.27015;
	data->m_mlx_ptr = mlx_init();
	data->m_win_ptr = mlx_new_window(data->m_mlx_ptr,
							data->width, data->height, "mandelbrot");
	data->mlx_new_image = mlx_new_image(data->m_mlx_ptr,
							data->width, data->height);
	data->mlx_get_data_addr = mlx_get_data_addr(data->mlx_new_image,
							&size, &width, &endian);
	data->process = 1;
}
