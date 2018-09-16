/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:34:17 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 12:50:49 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// TODO: leaks;
// TODO: norminette;
// TODO: Julia set without clicking -> change of the parameter;
// TODO: mouse zoom;
// TODO: ESC -> to exit the program;
// TODO: use images for printing the final image;
// TODO: multi threading;
// TODO: Two valid parameters in the command line, resulting in two fractals in two windows.
// TODO: several windows;

// TODO: Plan:
// 2. Putpixel for each type of the fractol;
// 3. Mouse events(scake nad change of the Julia params);
// 4. Image string which is located in the structure;
// 5. threads;
// 6. different windows;

double interpolate(double start, double end, double interpolation)
{
	return start + ((end - start) * interpolation);
}

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



	


		// void Cyrcle(void **mlx_ptr, void **win_ptr, int width, int height)
		// {
		// 	int x, y, z;
		// 	int mx, my;

		// 	mx = height / 2;
		// 	my = width / 2;

		// 	for (y = (-my); y <= my; y++)
		// 		for (x = (-mx); x <= mx; x++)
		// 		{
		// 			z = 0.1 * (x * x + y * y);
		// 			// putpixel(mx + x, my + y, int(z / 16));
		// 			t_rgb rgb;
		// 			rgb.R = mx + x;
		// 			rgb.G = my + y;
		// 			rgb.B = (int)(z / 16);

		// 			mlx_pixel_put(*mlx_ptr, *win_ptr, mx + x, my + y, hex_int_converter(RGBToHexadecimal(rgb)));
		// 		}


		// }



int click(int button, int x, int y, t_data *data)
{
	if (x >= 0 && y >= 0 && x <= data->width && y <= data->height && button == 1)
	{
		data->zoom += (data->zoom / 10);
		data->moveX -= (data->width / 2 - x) / (data->zoom * data->width * 2);
		data->moveY -= (data->height / 2 - y) / (data->zoom * data->height * 2);

	}
	else if (x >= 0 && y >= 0 && x <= data->width && y <= data->height && button == 5 && data->zoom > 1)
	{
		data->moveX -= (data->width / 2 - x) / (data->zoom * data->width * 2);
		data->moveY -= (data->height / 2 - y) / (data->zoom * data->height * 2);
		data->zoom -= (data->zoom / 10);
	}
	// mandelbrot(data);
	julia(data);

	return (1);
}

int mouse_move(int x, int y, t_data *data)
{

	data->cRe = sin(6.28 / 720 * (x));
	data->cIm = fabs(cos(6.28 / 720 * (y))) / 3;
	julia(data);

	return (1);
}



int main(int argc, char **argv)
{
	t_data data;

	// float left, top, xside, yside;

	// const double CxMin = -2.5;
	// const double CxMax = 1.5;
	// const double CyMin = -2.0;
	// const double CyMax = 2.0;

	// left = -1.5;
	// top = 1.0;
	// xside = 2;
	// yside = -2;

	// left = -1.5;
	// top = 1.2;
	// xside = 2;
	// yside = -2;

	// double MinRe = -1.5; // x0
	// double MaxRe = 1.0; // xmax
	// double MaxIm = -2;
	// double MinIm = 2;



	validation(argc, argv[1]);

	constructor(&data);

	// void *mlx_ptr = mlx_init();
	// void *win_ptr = mlx_new_window(mlx_ptr, 800, 800, "mandelbrot");

	// void *mlx_ptr1 = mlx_init();
	// void *win_ptr1 = mlx_new_window(mlx_ptr, width, height, "julia");

	// void *mlx_ptr2 = mlx_init();
	// void *win_ptr2 = mlx_new_window(mlx_ptr, width, height, "cyrcle");
	
	// mandelbrot(&data);
	// mandelbrot(&data);
	julia(&data);
		// if (mlx_ptr1)
		// 	julia4(&mlx_ptr1, &win_ptr1, MinRe, MaxRe, MinIm, MaxIm);
		// if (mlx_ptr2)
		// 	Cyrcle(&mlx_ptr2, &win_ptr2, width, height);

		// mlx_hook(win_ptr, 4, 1L << 1, click, (void *)0);
		// if (mlx_ptr1)
		// 	mlx_hook(win_ptr1, 4, 1L << 1, click, (void *)0);
		// if (mlx_ptr2)

	mlx_hook(data.m_win_ptr, 6, 1L << 1, mouse_move, &data);

	mlx_hook(data.m_win_ptr, 4, 1L << 1, click, &data);
	mlx_loop(data.m_mlx_ptr);

	// if (mlx_ptr1)
	// 	mlx_loop(mlx_ptr1);
	// if(mlx_ptr2)
	// 	mlx_loop(mlx_ptr2);

	// t_hsv data = {154, 0.43, 0.60};
	// t_rgb value = hsv_to_rgb(data);

	// printf("R->%d, G->%d, B->%d", value.R, value.G, value.B);

	// t_rgb	rgb;
	// rgb.R = 245;
	// rgb.G = 255;
	// rgb.B = 250;

	// ft_putstr(RGBToHexadecimal(rgb));

	// system("leaks -q fractol");
	return (0);
	}

	// data->cRe = sin(6.28 / 720 * (x));
	// data->cIm = _ABS(cos(6.28 / 720 * (y))) / 3;