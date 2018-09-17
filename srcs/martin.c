/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyrcle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:24:12 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/17 14:25:09 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


			void fill(char *my_image_string, int x, int y)
			{
				my_image_string[x * 4 + 4000 * y] = 0;
				my_image_string[x * 4 + 4000 * y + 1] = 80;
				my_image_string[x * 4 + 4000 * y + 2] = 0;
			}

void	martin(t_data *data)
{
	double x, t, y;
	int n;


		x = 0;
		y = 0;
		n = 0;
		while (n < 10 * data->zoom) 
		{
			t = x;
			x = y - sin(x);
			y = 3.14 - t;
			n++;
			mlx_pixel_put(data->m_mlx_ptr, data->m_win_ptr, (x * 2) + 500, floor(y * 2) + 380, 0x008000);
		}
	}


		

