/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 09:48:23 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 14:39:53 by otimofie         ###   ########.fr       */
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
	data->moveX = -0.5;
	data->moveY = 0;
	data->zoom = 1;
	data->cRe = -0.7;
	data->cIm = 0.27015;
	data->m_mlx_ptr = mlx_init();
	
	data->m_win_ptr = mlx_new_window(data->m_mlx_ptr, data->width, data->height, "mandelbrot");
	
	data->mlx_new_image = mlx_new_image(data->m_mlx_ptr, data->width, data->height);

	data->mlx_get_data_addr = mlx_get_data_addr(data->mlx_new_image, &size, &width, &endian);

	// ft_putnbr(width);
	// exit(0);
}
