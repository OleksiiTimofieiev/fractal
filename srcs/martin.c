/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   martin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:24:12 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/17 15:00:32 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"




// void	martin(t_data *data)
// {
// 	double x, t, y;
// 	int n;


// 		x = 0;
// 		y = 0;
// 		n = 0;
// 		while (n < 10 * data->zoom) 
// 		{
// 			t = x;
// 			x = y - sin(x);
// 			y = 3.14 - t;
// 			n++;
// 			mlx_pixel_put(data->m_mlx_ptr, data->m_win_ptr, (x * 2) + 500, floor(y * 2) + 380, 0x008000);
// 		}
// 	}

void martin(t_data *data)
{

	int x, y, z;
	int mx, my;



	mx = data->width / 2;
	my = data->height / 2;

	for (y = (-my); y <= my; y++)
		for (x = (-mx); x <= mx; x++)
		{
			z = (0.1 * data->zoom) * (x * x + y * y);
			ft_putnbr((int)(z / 16));
			ft_putstr("\n");
				mlx_pixel_put(data->m_mlx_ptr, data->m_win_ptr, mx + x, my + y, (int)(z / 16));
		}
			
		
}
