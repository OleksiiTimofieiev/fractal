/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 09:48:23 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 12:44:34 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	constructor(t_data *data)
{
	data->width = MONITOR_WIDTH;
	data->height = MONITOR_HEIGHT;
	// data->m_min_re = -1.5;
	// data->m_max_re = 1.0;
	// data->m_max_im = -2;
	// data->m_min_im = 2;
	data->max_iterations = MAX_ITERATIONS;
	data->m_mlx_ptr = mlx_init();
	data->m_win_ptr = mlx_new_window(data->m_mlx_ptr, data->width, data->height, "mandelbrot");
	data->zoom = 1;
	data->moveX = -0.5;
	data->moveY = 0;
	data->zoom = 1;
	data->cRe = -0.7;
	data->cIm = 0.27015;
}
