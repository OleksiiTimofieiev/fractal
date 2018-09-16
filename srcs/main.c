/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:34:17 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 12:26:30 by otimofie         ###   ########.fr       */
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



	

		// void julia4(void **mlx_ptr, void **win_ptr, float left, float top, float xside, float yside)
		// {
		// 	float xscale, yscale, zx, zy, cx, tempx, cy;
		// 	int x, y; /* i, j;*/
		// 	int maxx, maxy, count;

		// 	// getting maximum value of x-axis of screen
		// 	maxx = 800;

		// 	// getting maximum value of y-axis of screen
		// 	maxy = 800;

		// 	// setting up the xscale and yscale
		// 	xscale = xside / maxx;
		// 	yscale = yside / maxy;


		// 	cx = -0.6;
		// 	cy = 0.11;

		// 	cx = sin(6.28 / 720 * (400));
		// 	cy = fabs(cos(6.28 / 720 * (450)));
		// 	// scanning every point in that rectangular area.
		// 	// Each point represents a Complex number (x + yi).
		// 	// Iterate that complex number
		// 	for (y = 1; y <= maxy - 1; y++)
		// 	{
		// 		for (x = 1; x <= maxx - 1; x++)
		// 		{
		// 			// c_real
		// 			zx = x * xscale + left;

		// 			// c_imaginary
		// 			zy = y * yscale + top;

		// 			count = 0;

		// 			// Calculate whether c(c_real + c_imaginary) belongs
		// 			// to the Mandelbrot set or not and draw a pixel
		// 			// at coordinates (x, y) accordingly
		// 			// If you reach the Maximum number of iterations
		// 			// and If the distance from the origin is
		// 			// greater than 2 exit the loop
		// 			while ((zx * zx + zy * zy < 4) && (count < MAXCOUNT))
		// 			{
		// 				// Calculate Mandelbrot function
		// 				// z = z*z + c where z is a complex number

		// 				// tempx = z_real*_real - z_imaginary*z_imaginary + c_real
		// 				tempx = zx * zx - zy * zy;

		// 				// 2*z_real*z_imaginary + c_imaginary
		// 				zy = 2 * zx * zy + cy;

		// 				// Updating z_real = tempx
		// 				zx = tempx + cx;

		// 				// Increment count
		// 				count++;
		// 			}

		// 			// To display the created fractal
		// 			t_hsv _hsv;

		// 			_hsv.H = count % 256;
		// 			_hsv.S = 120;
		// 			_hsv.V = 255 * (count < MAXCOUNT);

		// 			t_rgb rgb = hsv_to_rgb(_hsv);

		// 			mlx_pixel_put(*mlx_ptr, *win_ptr, x, y, hex_int_converter(RGBToHexadecimal(rgb)));
		// 		}
		// 	}
		// }

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

// int hook_mousemove(int x, int y, t_mlx *mlx)
// {
// 	mlx->mouse->lastx = mlx->mouse->x;
// 	mlx->mouse->lasty = mlx->mouse->y;
// 	mlx->mouse->x = x;
// 	mlx->mouse->y = y;

// 	if (mlx->mouse->isdown & (1 << 1))
// 	{
// 		mlx->map->center->x += (x - mlx->mouse->lastx);
// 		mlx->map->center->y += (y - mlx->mouse->lasty);
// 		ft_draw(mlx);
// 	}

// 	if (mlx->mouse->isdown & (1 << 2))
// 	{
// 		mlx->map->matrix->ry -= (x - mlx->mouse->lastx) / 200.0f;
// 		mlx->map->matrix->rx += (y - mlx->mouse->lasty) / 200.0f;
// 		ft_draw(mlx);
// 	}

// 	return (0);
// }

// int mouse_scroll(int button, int x, int y, void *param)
// {
// 	t_fr *fr;

// 	fr = (t_fr *)param;
// 	if (x >= 0 && y >= 0 && x <= data->w && y <= data->h && button == 4)
// 	{
// 		fr->zoom += (fr->zoom / 10);
// 		fr->moveX -= (fr->w / 2 - x) / (fr->zoom * fr->w * 2);
// 		fr->moveY -= (fr->h / 2 - y) / (fr->zoom * fr->h * 2);
// 		fr->tmp1 = 1.5 / ((double)fr->zoom * (double)fr->w2);
// 		fr->tmp2 = (double)(fr->zoom * fr->h2);
// 	}
// 	else if (x >= 0 && y >= 0 && x <= fr->w && y <= fr->h && button == 5 && fr->zoom > 1)
// 	{
// 		fr->moveX -= (fr->w / 2 - x) / (fr->zoom * fr->w * 2);
// 		fr->moveY -= (fr->h / 2 - y) / (fr->zoom * fr->h * 2);
// 		fr->zoom -= (fr->zoom / 10);
// 		fr->tmp1 = 1.5 / ((double)fr->zoom * (double)fr->w2);
// 		fr->tmp2 = (double)(fr->zoom * fr->h2);
// 	}
// 	//printf("%f, %f, %f\n", fr->moveX, fr->moveY, fr->zoom);
// 	fr->fractol(fr);
// 	return (0);
// }

int click(int button, int x, int y, t_data *data)
{
	// float mouseRe = (float)x / (data->width / (data->m_max_re - data->m_min_re)) + data->m_min_re;
	// float mouseIm = (float)y / (data->height / (data->m_max_im - data->m_min_im)) + data->m_min_im;

	// float interpolation = 1.0 / 1.4; // 1.5 = max,1.05
	// data->m_min_re = interpolate( data->m_min_re, mouseRe, interpolation);
	// data->m_max_re = interpolate( data->m_max_re, mouseRe, interpolation);
	// data->m_min_im = interpolate(mouseIm, data->m_min_im, interpolation);
	// data->m_max_im = interpolate(mouseIm, data->m_max_im, interpolation);
	// (void)x;
	// (void)y;

	// // data->m_max_im += 0.01;
	// data->m_max_re += 0.01;
	// data->m_min_re += 0.01;
	// data->m_min_im += 0.01;

	// {
	// 	t_fr *fr;

	// 	fr = (t_fr *)param;
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

	ft_putnbr(button);
	ft_putstr("\n");

	mandelbrot(data);

	return (1);
}

int mouse_move(int x, int y, void *param)
{
	(void)param;
	ft_putnbr(x);
	ft_putstr("\n");
	ft_putnbr(y);
	ft_putstr("\n");

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
	mandelbrot(&data);
		// if (mlx_ptr1)
		// 	julia4(&mlx_ptr1, &win_ptr1, MinRe, MaxRe, MinIm, MaxIm);
		// if (mlx_ptr2)
		// 	Cyrcle(&mlx_ptr2, &win_ptr2, width, height);

		// mlx_hook(win_ptr, 4, 1L << 1, click, (void *)0);
		// if (mlx_ptr1)
		// 	mlx_hook(win_ptr1, 4, 1L << 1, click, (void *)0);
		// if (mlx_ptr2)

		// mlx_hook(win_ptr, 6, 1L << 1, mouse_move, (void *)0);

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