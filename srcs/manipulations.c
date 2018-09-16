/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 16:06:30 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 18:13:21 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		zoom(int button, int x, int y, t_data *data)
{
	if (x >= 0 && y >= 0 && x <= data->width
		&& y <= data->height && button == 5)
	{
		data->zoom += (data->zoom / 20);
		data->move_x -= (data->width / 2 - x) /
		(data->zoom * data->width * 2);
		data->move_y -= (data->height / 2 - y) /
		(data->zoom * data->height * 2);
		data->max_iterations += 5;
	}
	else if (x >= 0 && y >= 0 && x <= data->width &&
		y <= data->height && button == 4 && data->zoom > 1)
	{
		data->move_x -= (data->width / 2 - x) / (data->zoom * data->width * 2);
		data->move_y -= (data->height / 2 - y) /
		(data->zoom * data->height * 2);
		data->zoom -= (data->zoom / 10);
	}
	data->fractol(data);
	return (1);
}

int		mouse_move(int x, int y, t_data *data)
{
	data->c_re = sin(6.28 / 720 * (x));
	data->c_im = fabs(cos(6.28 / 720 * (y))) / 3;
	data->fractol(data);
	return (1);
}

void	fill_pixel(char *my_image_string, int x, int y, t_rgb rgb)
{
	my_image_string[x * 4 + 4000 * y] = rgb.g;
	my_image_string[x * 4 + 4000 * y + 1] = rgb.b;
	my_image_string[x * 4 + 4000 * y + 2] = rgb.r;
}
