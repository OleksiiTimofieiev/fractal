/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:34:17 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 14:48:29 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// TODO: leaks;
// TODO: norminette;
// TODO: ESC -> to exit the program;

// TODO: Plan:
// 4. Image string which is located in the structure;
// 5. threads;
// 6. different windows;
// stop with if;
 // music

int hex_int_converter(char *input)
{
	int base;
	size_t len;
	int dec_val;
	int i;

	base = 1;
	len = ft_strlen(input);
	dec_val = 0;
	i = len - 1;
	while (i >= 0)
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			dec_val += (input[i] - 48) * base;
			base = base * 16;
		}
		else if (input[i] >= 'A' && input[i] <= 'F')
		{
			dec_val += (input[i] - 55) * base;
			base = base * 16;
		}
		i--;
	}
	return (dec_val);
}


int zoom(int button, int x, int y, t_data *data)
{
	if (x >= 0 && y >= 0 && x <= data->width && y <= data->height && button == 1)
	{
		data->zoom += (data->zoom / 10);
		data->moveX -= (data->width / 2 - x) / (data->zoom * data->width * 2);
		data->moveY -= (data->height / 2 - y) / (data->zoom * data->height * 2);

	}
	else if (x >= 0 && y >= 0 && x <= data->width && y <= data->height && button == 2 && data->zoom > 1)
	{
		data->moveX -= (data->width / 2 - x) / (data->zoom * data->width * 2);
		data->moveY -= (data->height / 2 - y) / (data->zoom * data->height * 2);
		data->zoom -= (data->zoom / 10);
	}
	mandelbrot(data);
	// julia(data);

	return (1);
}

int mouse_move(int x, int y, t_data *data)
{

	data->cRe = sin(6.28 / 720 * (x));
	data->cIm = fabs(cos(6.28 / 720 * (y))) / 3;
	// julia(data);

	return (1);
}



int main(int argc, char **argv)
{
	// pointer to func;
	// different windows;
	t_data data;

	validation(argc, argv[1]);

	constructor(&data);

	// julia(&data);
	mandelbrot(&data);

	// mlx_hook(data.m_win_ptr, 6, 1L << 1, mouse_move, &data);
	mlx_hook(data.m_win_ptr, 4, 1L << 1, zoom, &data);
	mlx_loop(data.m_mlx_ptr);


	return (0);
	}

