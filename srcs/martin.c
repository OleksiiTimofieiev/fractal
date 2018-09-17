/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   martin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:24:12 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/17 14:35:08 by otimofie         ###   ########.fr       */
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

#define a 1
#define b 3
#define dt 5

void martin(t_data *data)
{
	int i, j, k;
	float x, y;

	for (i = 0; i <= 43; i++)
		for (j = 0; j <= 37; j++)
		{
			x = i;
			y = j;
			for (k = 1; k <= 100; k++)
			{
				y = y + sin(x + a * sin(b * x)) * dt;
				x = x - sin(y + a * sin(b * y)) * dt;
				// putpixel(int(x*15), int(y*15), (i+j)%10);
				mlx_pixel_put(data->m_mlx_ptr, data->m_win_ptr, (int)(x * 23), (int)(y * 21), (0x008000));
			}
		}
}
