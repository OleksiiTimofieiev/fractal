/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 09:48:23 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 10:13:57 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	constructor(t_data *data)
{
	data->width = MONITOR_WIDTH;
	data->height = MONITOR_HEIGHT;
	data->m_min_re = -1.5;
	data->m_max_re = 1.0;
	data->m_max_im = -2;
	data->m_min_im = 2;
	data->max_iterations = MAX_ITERATIONS;
	data->m_mlx_ptr = mlx_init();
	data->m_win_ptr = mlx_new_window(data->m_mlx_ptr, data->width, data->height, "mandelbrot");
}
