/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:34:17 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/12 21:14:59 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// TODO: leaks;
// TODO: norminette;
// TODO: types: Julia, Mandelbrot, ?
// TODO: Julia set without clicking -> change of the parameter;
// TODO: mouse zoom;
// TODO: several colors to show the depth of the fractol;
// TODO: ESC -> to exit the program;
// TODO: use images for printing the fina image;
// TODO: multi threading;
// TODO: Two valid parameters in the command line, resulting in two fractals in two windows.
// TODO: putimage;
// TODO: several windows;


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


void	Mandelbrot(void **mlx_ptr, void **win_ptr, int width, int height)
{
	//each iteration, it calculates: new = old*old + c, where c is a constant and old starts at current pixel
	double pr, pi;							  //real and imaginary part of the pixel p
	double newRe, newIm, oldRe, oldIm;		  //real and imaginary parts of new and old
	// basic zoom;
	double zoom = 1, moveX = -0.5, moveY = 0; //you can change these to zoom and change position
	// ColorRGB color;							  //the RGB color value for the pixel
	int maxIterations = 128;				  //after how much iterations the function should stop

	// long double min = -2.84;
	// long double max = 1.0;
	// long double factor = 1;

	// zoom = -1;

	clock_t t = 0.0, oldTime, frameTime; //current and old time, and their difference (for input)
											// int showText = 0;

	//begin main program loop
	
	// int count = 0;
	// while (1)
	// {
		// max -= 0.1 * factor;
		// min += 0.15 * factor;
		// factor *= 0.9349;
		// maxIterations += 5;
		// if (count > 30)
		// 	maxIterations += 5;
			// draw the fractal
		for (int y = 0; y < height; y++) 
		for (int x = 0; x < width; x++)
		{
			//calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
			pr = 1.5 * (x - width / 2) / (0.5 * zoom * width) + (moveX);
			pi = (y - height / 2) / (0.5 * zoom * height) + (moveY);
			newRe = newIm = oldRe = oldIm = 0; //these should start at 0,0
			//i will represent the number of iterations
			int i;
			//start the iteration process
			for (i = 0; i < maxIterations; i++)
			{
				//remember value of previous iteration
				oldRe = newRe;
				oldIm = newIm;
				//the actual iteration, the real and imaginary part are calculated
				newRe = oldRe * oldRe - oldIm * oldIm + pr;
				newIm = 2 * oldRe * oldIm + pi;
				//if the point is outside the circle with radius 2: stop
				if ((newRe * newRe + newIm * newIm) > 4)
					break;
			}
			//use color model conversion to get rainbow palette, make brightness black if maxIterations reached
			// color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));
			//draw the pixel
			// pset(x, y, color);
			// generate color func;

			t_hsv _hsv;

			_hsv.H = i % 256;
			_hsv.S = 120; //100
			_hsv.V = 255 * (i < maxIterations);

			t_rgb rgb = hsv_to_rgb(_hsv);

			mlx_pixel_put(*mlx_ptr, *win_ptr, x, y, hex_int_converter(RGBToHexadecimal(rgb)));

			}
		oldTime = clock();
		t = clock();
		frameTime = (float)t - oldTime;
	}
	// count++;

// }

	void Mandelbrot2(void **mlx_ptr, void **win_ptr, int width, int height)
	{
		double MinRe = -2.0;
		double MaxRe = 1.0;
		double MinIm = -1.2;
		double MaxIm = MinIm + (MaxRe - MinRe) * height / width;
		double Re_factor = (MaxRe - MinRe) / (width - 1);
		double Im_factor = (MaxIm - MinIm) / (height - 1);
		
		int MaxIterations = 30;

		for (int y = 0; y < height; ++y)
		{
			double c_im = MaxIm - y * Im_factor;
			for (int x = 0; x < width; ++x)
			{
				double c_re = MinRe + x * Re_factor;

				double Z_re = c_re, Z_im = c_im;
				int isInside = 0;
				int n = 0;
				for (; n < MaxIterations; ++n)
				{
					double Z_re2 = Z_re * Z_re;
					double Z_im2 = Z_im * Z_im;
					if (Z_re2 + Z_im2 > 4)
					{
						isInside = 1;
						break;
					}
					Z_im = 2 * Z_re * Z_im + c_im;
					Z_re = Z_re2 - Z_im2 + c_re;
				}
				if (isInside)
				{
					t_hsv _hsv;

					_hsv.H = n % 256;
					_hsv.S = 120; //100
					_hsv.V = 255 * (n < MaxIterations);

					t_rgb rgb = hsv_to_rgb(_hsv);

					mlx_pixel_put(*mlx_ptr, *win_ptr, x, y, hex_int_converter(RGBToHexadecimal(rgb)));
					// putpixel(x, y);
				}
			}
		}
}
void Julia(void **mlx_ptr, void **win_ptr, int width, int height)
{
	double MinRe = -2.0;
	double MaxRe = 2.0;
	double MinIm = -2.0;
	double MaxIm = MinIm + (MaxRe - MinRe) * height / width;
	
	double Re_factor = (MaxRe - MinRe) / (width - 1);
	double Im_factor = (MaxIm - MinIm) / (height - 1);

	int MaxIterations = 400;

	for (int y = 0; y < height; ++y)
	{
		double c_im = MaxIm - y * Im_factor;
		for (int x = 0; x < width; ++x)
		{
			double c_re = MinRe + x * Re_factor;

			double Z_re = c_re, Z_im = c_im;


			int isInside = 0;
			
			int n = 0;
			
			for (; n < MaxIterations; ++n)
			{
				double Z_re2 = Z_re * Z_re;
				double Z_im2 = Z_im * Z_im;
				if (Z_re2 + Z_im2 > 4)
				{
					isInside = 1;
					break;
				}
				Z_im = 2 * Z_re * Z_im + 0.400;
				Z_re = Z_re2 - Z_im2 + 0.400;
			}
			if (isInside)
			{
				t_hsv _hsv;

				_hsv.H = n % 256;
				_hsv.S = 120;
				_hsv.V = 255 * (n < MaxIterations);

				t_rgb rgb = hsv_to_rgb(_hsv);

				mlx_pixel_put(*mlx_ptr, *win_ptr, x, y, hex_int_converter(RGBToHexadecimal(rgb)));
				// putpixel(x, y);
			}
		}
	}
}

	int main(int argc, char **argv)
	{
		int height = 800;
		int width = 1000;

		validation(argc, argv[1]);

		void *mlx_ptr = mlx_init();
		void *win_ptr = mlx_new_window(mlx_ptr, width, height, "mandelbrot");
		// Mandelbrot(&mlx_ptr, &win_ptr, width, height);

		// Mandelbrot2(&mlx_ptr, &win_ptr, width, height);
		Julia(&mlx_ptr, &win_ptr, width, height);

		mlx_loop(mlx_ptr);

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
