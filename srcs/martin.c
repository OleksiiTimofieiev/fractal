/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   martin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:24:12 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/17 15:16:58 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fill_pixel_local(char *my_image_string, int x, int y, int num)
{
	my_image_string[x * 4 + 4000 * y] = num / (256 ^ 2);
	my_image_string[x * 4 + 4000 * y + 1] = (num / 256) % 256;
	my_image_string[x * 4 + 4000 * y + 2] = num % 256;
}

void	martin(t_data *data)
{
	int x;
	int y;
	int z;

	x = 0;
	y = 0;
	z = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			z = (0.01 * data->zoom) * (x * x + y * y);
			fill_pixel_local(data->mlx_get_data_addr, x, y, (int)(z / 16));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->m_mlx_ptr, data->m_win_ptr, data->mlx_new_image, 0, 0);
}
