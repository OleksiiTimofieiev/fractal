/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   martin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:24:12 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/17 15:13:57 by otimofie         ###   ########.fr       */
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

void fill_pixel_local(char *my_image_string, int x, int y, int num)
{
	my_image_string[x * 4 + 4000 * y] = num / (256 ^ 2);
	my_image_string[x * 4 + 4000 * y + 1] = (num / 256) % 256;
	my_image_string[x * 4 + 4000 * y + 2] = num % 256;
}

void martin(t_data *data)
{

	int x, y, z;



	for (y = 0; y < data->height; y++)
		for (x = 0; x < data->width; x++)
		{
			z = (0.1 * data->zoom) * (x * x + y * y);

			fill_pixel_local(data->mlx_get_data_addr, x, y, (int)(z / 16));
			// mlx_pixel_put(data->m_mlx_ptr, data->m_win_ptr, mx + x, my + y, (int)(z / 16));
		}

	mlx_put_image_to_window(data->m_mlx_ptr, data->m_win_ptr, data->mlx_new_image, 0, 0);
}
