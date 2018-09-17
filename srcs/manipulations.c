/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 16:06:30 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/17 13:09:32 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		zoom(int button, int x, int y, t_data *data)
{
	if (x >= 0 && y >= 0 && x <= data->width
		&& y <= data->height && button == 5)
	{
		data->zoom += (data->zoom / 10);
		data->move_x -= (data->width / 2 - x) /
		(data->zoom * data->width * 2);
		data->move_y -= (data->height / 2 - y) /
		(data->zoom * data->height * 2);
		(data->max_iterations >= 128) ? data->max_iterations += 5 : 0;
	}
	else if (x >= 0 && y >= 0 && x <= data->width &&
		y <= data->height && button == 4)
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
	if (data->process)
	{
		data->c_im = fabs(cos((3.14 * 2) / 720 * (y))) / 3;
		data->c_re = sin((3.14 * 2) / 720 * (x));
		data->fractol(data);
	}
	return (1);
}

void	fill_pixel(char *my_image_string, int x, int y, t_rgb rgb)
{
	my_image_string[x * 4 + 4000 * y] = rgb.g;
	my_image_string[x * 4 + 4000 * y + 1] = rgb.b;
	my_image_string[x * 4 + 4000 * y + 2] = rgb.r;
}

int		deal_with_keyboard(int key, t_data *data)
{
	if (key == 49 && data->process == 0)
		data->process = 1;
	else if (key == 49 && data->process != 0)
		data->process = 0;
	else if (key == 124 || key == 123 
		|| key == 125 || key == 126)
	{
		if (key == 124)
				data->move_x -= 0.01;
		else if (key == 123)
			data->move_x += 0.01;
		else if (key == 125)
			data->move_y -= 0.01;
		else if (key == 126)
			data->move_y += 0.01;
		data->fractol(data);
	}
	else if (key == 53)
	{
		system("killall afplay");
		exit(0);
	}
	return (1);
}
