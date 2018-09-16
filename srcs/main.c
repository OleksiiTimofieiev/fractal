/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:34:17 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 10:13:46 by otimofie         ###   ########.fr       */
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

int click(int button, int x, int y, void *param)
{
	(void)param;
	ft_putnbr(x);
	ft_putstr("\n");
	ft_putnbr(y);
	ft_putstr("\n");
	ft_putnbr(button);
	ft_putstr("\n");

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

	double MinRe = -1.5; // x0
	double MaxRe = 1.0; // xmax
	double MaxIm = -2;
	double MinIm = 2;

	// double mouseRe = (double)453 / (800 / (MaxRe - MinRe)) + MinRe;
	// double mouseIm = (double)240 / (800 / (MaxIm - MinIm)) + MinIm;

	// double interpolation = 1.0 / 1.01; // 1.5 = max,1.05
	// MinRe = interpolate(mouseRe, MinRe, interpolation);
	// MinIm = interpolate(mouseIm, MinIm, interpolation);
	// MaxRe = interpolate(mouseRe, MaxRe, interpolation);
	// MaxIm = interpolate(mouseIm, MaxIm, interpolation);

	// mouseRe = (double)703 / (800 / (MaxRe - MinRe)) + MinRe;
	// mouseIm = (double)415 / (800 / (MaxIm - MinIm)) + MinIm;


	// MinRe = interpolate(mouseRe, MinRe, interpolation);
	// MinIm = interpolate(mouseIm, MinIm, interpolation);
	// MaxRe = interpolate(mouseRe, MaxRe, interpolation);
	// MaxIm = interpolate(mouseIm, MaxIm, interpolation);

	// mouseRe = (double)703 / (800 / (MaxRe - MinRe)) + MinRe;
	// mouseIm = (double)427 / (800 / (MaxIm - MinIm)) + MinIm;

	// MinRe = interpolate(mouseRe, MinRe, interpolation);
	// MinIm = interpolate(mouseIm, MinIm, interpolation);
	// MaxRe = interpolate(mouseRe, MaxRe, interpolation);
	// MaxIm = interpolate(mouseIm, MaxIm, interpolation);

	// mouseRe = (double)696 / (800 / (MaxRe - MinRe)) + MinRe;
	// mouseIm = (double)447 / (800 / (MaxIm - MinIm)) + MinIm;

	// MinRe = interpolate(mouseRe, MinRe, interpolation);
	// MinIm = interpolate(mouseIm, MinIm, interpolation);
	// MaxRe = interpolate(mouseRe, MaxRe, interpolation);
	// MaxIm = interpolate(mouseIm, MaxIm, interpolation);

	// mouseRe = (double)698 / (800 / (MaxRe - MinRe)) + MinRe;
	// mouseIm = (double)456 / (800 / (MaxIm - MinIm)) + MinIm;

	// MinRe = interpolate(mouseRe, MinRe, interpolation);
	// MinIm = interpolate(mouseIm, MinIm, interpolation);
	// MaxRe = interpolate(mouseRe, MaxRe, interpolation);
	// MaxIm = interpolate(mouseIm, MaxIm, interpolation);

	// mouseRe = (double)689 / (800 / (MaxRe - MinRe)) + MinRe;
	// mouseIm = (double)471 / (800 / (MaxIm - MinIm)) + MinIm;

	// MinRe = interpolate(mouseRe, MinRe, interpolation);
	// MinIm = interpolate(mouseIm, MinIm, interpolation);
	// MaxRe = interpolate(mouseRe, MaxRe, interpolation);
	// MaxIm = interpolate(mouseIm, MaxIm, interpolation);

	// mouseRe = (double)685 / (800 / (MaxRe - MinRe)) + MinRe;
	// mouseIm = (double)481 / (800 / (MaxIm - MinIm)) + MinIm;

	// MinRe = interpolate(mouseRe, MinRe, interpolation);
	// MinIm = interpolate(mouseIm, MinIm, interpolation);
	// MaxRe = interpolate(mouseRe, MaxRe, interpolation);
	// MaxIm = interpolate(mouseIm, MaxIm, interpolation);

	// mouseRe = (double)677 / (800 / (MaxRe - MinRe)) + MinRe;
	// mouseIm = (double)492 / (800 / (MaxIm - MinIm)) + MinIm;

	// MinRe = interpolate(mouseRe, MinRe, interpolation);
	// MinIm = interpolate(mouseIm, MinIm, interpolation);
	// MaxRe = interpolate(mouseRe, MaxRe, interpolation);
	// MaxIm = interpolate(mouseIm, MaxIm, interpolation);

	// mouseRe = (double)676 / (800 / (MaxRe - MinRe)) + MinRe;
	// mouseIm = (double)504 / (800 / (MaxIm - MinIm)) + MinIm;

	// MinRe = interpolate(mouseRe, MinRe, interpolation);
	// MinIm = interpolate(mouseIm, MinIm, interpolation);
	// MaxRe = interpolate(mouseRe, MaxRe, interpolation);
	// MaxIm = interpolate(mouseIm, MaxIm, interpolation);

	// mouseRe = (double)673 / (800 / (MaxRe - MinRe)) + MinRe;
	// mouseIm = (double)514 / (800 / (MaxIm - MinIm)) + MinIm;

	// MinRe = interpolate(mouseRe, MinRe, interpolation);
	// MinIm = interpolate(mouseIm, MinIm, interpolation);
	// MaxRe = interpolate(mouseRe, MaxRe, interpolation);
	// MaxIm = interpolate(mouseIm, MaxIm, interpolation);

	// mouseRe = (double)680 / (800 / (MaxRe - MinRe)) + MinRe;
	// mouseIm = (double)524 / (800 / (MaxIm - MinIm)) + MinIm;

	// MinRe = interpolate(mouseRe, MinRe, interpolation);
	// MinIm = interpolate(mouseIm, MinIm, interpolation);
	// MaxRe = interpolate(mouseRe, MaxRe, interpolation);
	// MaxIm = interpolate(mouseIm, MaxIm, interpolation);

	// mouseRe = (double)679 / (800 / (MaxRe - MinRe)) + MinRe;
	// mouseIm = (double)535 / (800 / (MaxIm - MinIm)) + MinIm;

	// MinRe = interpolate(mouseRe, MinRe, interpolation);
	// MinIm = interpolate(mouseIm, MinIm, interpolation);
	// MaxRe = interpolate(mouseRe, MaxRe, interpolation);
	// MaxIm = interpolate(mouseIm, MaxIm, interpolation);

	// mouseRe = (double)693 / (800 / (MaxRe - MinRe)) + MinRe;
	// mouseIm = (double)543 / (800 / (MaxIm - MinIm)) + MinIm;

	// MinRe = interpolate(mouseRe, MinRe, interpolation);
	// MinIm = interpolate(mouseIm, MinIm, interpolation);
	// MaxRe = interpolate(mouseRe, MaxRe, interpolation);
	// MaxIm = interpolate(mouseIm, MaxIm, interpolation);

	// mouseRe = (double)686 / (800 / (MaxRe - MinRe)) + MinRe;
	// mouseIm = (double)552 / (800 / (MaxIm - MinIm)) + MinIm;

	// MinRe = interpolate(mouseRe, MinRe, interpolation);
	// MinIm = interpolate(mouseIm, MinIm, interpolation);
	// MaxRe = interpolate(mouseRe, MaxRe, interpolation);
	// MaxIm = interpolate(mouseIm, MaxIm, interpolation);
	
	// mouseRe = (double)765 / (800 / (MaxRe - MinRe)) + MinRe;
	// mouseIm = (double)586 / (800 / (MaxIm - MinIm)) + MinIm;


	// MinRe = interpolate(mouseRe, MinRe, interpolation);
	// MinIm = interpolate(mouseIm, MinIm, interpolation);
	// MaxRe = interpolate(mouseRe, MaxRe, interpolation);
	// MaxIm = interpolate(mouseIm, MaxIm, interpolation);

	// mouseRe = (double)700 / (800 / (MaxRe - MinRe)) + MinRe;
	// mouseIm = (double)198 / (800 / (MaxIm - MinIm)) + MinIm;


	// MinRe = interpolate(mouseRe, MinRe, interpolation);
	// MinIm = interpolate(mouseIm, MinIm, interpolation);
	// MaxRe = interpolate(mouseRe, MaxRe, interpolation);
	// MaxIm = interpolate(mouseIm, MaxIm, interpolation);

	// mouseRe = (double)658 / (800 / (MaxRe - MinRe)) + MinRe;
	// mouseIm = (double)211 / (800 / (MaxIm - MinIm)) + MinIm;

	// MinRe = interpolate(mouseRe, MinRe, interpolation);
	// MinIm = interpolate(mouseIm, MinIm, interpolation);
	// MaxRe = interpolate(mouseRe, MaxRe, interpolation);
	// MaxIm = interpolate(mouseIm, MaxIm, interpolation);

	validation(argc, argv[1]);

	void *mlx_ptr = mlx_init();
	void *win_ptr = mlx_new_window(mlx_ptr, 800, 800, "mandelbrot");

	// void *mlx_ptr1 = mlx_init();
	// void *win_ptr1 = mlx_new_window(mlx_ptr, width, height, "julia");

	// void *mlx_ptr2 = mlx_init();
	// void *win_ptr2 = mlx_new_window(mlx_ptr, width, height, "cyrcle");
	
	// mandelbrot(&data);
	mandelbrot(&mlx_ptr, &win_ptr, MinRe, MaxRe, MinIm, MaxIm);
		// if (mlx_ptr1)
		// 	julia4(&mlx_ptr1, &win_ptr1, MinRe, MaxRe, MinIm, MaxIm);
		// if (mlx_ptr2)
		// 	Cyrcle(&mlx_ptr2, &win_ptr2, width, height);

		// mlx_hook(win_ptr, 4, 1L << 1, click, (void *)0);
		// if (mlx_ptr1)
		// 	mlx_hook(win_ptr1, 4, 1L << 1, click, (void *)0);
		// if (mlx_ptr2)
		// 	mlx_hook(win_ptr2, 4, 1L << 1, click, (void *)0);

		// mlx_hook(win_ptr, 6, 1L << 1, mouse_move, (void *)0);

	mlx_loop(mlx_ptr);

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

	// fr->cRe = sin(6.28 / 720 * (x));
	// fr->cIm = _ABS(cos(6.28 / 720 * (y))) / 3;