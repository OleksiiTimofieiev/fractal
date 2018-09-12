/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:34:17 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/12 21:39:36 by otimofie         ###   ########.fr       */
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


											// int showText = 0;
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

			t_hsv _hsv;

			_hsv.H = i % 256;
			_hsv.S = 120; //100
			_hsv.V = 255 * (i < maxIterations);

			t_rgb rgb = hsv_to_rgb(_hsv);

			mlx_pixel_put(*mlx_ptr, *win_ptr, x, y, hex_int_converter(RGBToHexadecimal(rgb)));

			}
	}

	void Julia(void **mlx_ptr, void **win_ptr, int width, int height)
	{
		//each iteration, it calculates: new = old*old + c, where c is a constant and old starts at current pixel

		double newRe, newIm, oldRe, oldIm; //real and imaginary parts of new and old
		
		double cRe = -0.7, cIm = 0.27015;
		// basic zoom;
		double zoom = 1, moveX = 0.0, moveY = 0; //you can change these to zoom and change position
		// ColorRGB color;							  //the RGB color value for the pixel
		int maxIterations = 128; //after how much iterations the function should stop


											 // int showText = 0;
		for (int y = 0; y < height; y++)
			for (int x = 0; x < width; x++)
			{
				//calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
				newRe = 1.5 * (x - width / 2) / (0.5 * zoom * width) + (moveX);
				newIm = (y - height / 2) / (0.5 * zoom * height) + (moveY);
				// newRe = newIm = oldRe = oldIm = 0; //these should start at 0,0
				//i will represent the number of iterations
				int i;
				//start the iteration process
				for (i = 0; i < maxIterations; i++)
				{
					//remember value of previous iteration
					oldRe = newRe;
					oldIm = newIm;
					//the actual iteration, the real and imaginary part are calculated
					newRe = oldRe * oldRe - oldIm * oldIm + cRe;
					newIm = 2 * oldRe * oldIm + cIm;
					//if the point is outside the circle with radius 2: stop
					if ((newRe * newRe + newIm * newIm) > 4)
						break;
				}

				t_hsv _hsv;

				_hsv.H = i % 256;
				_hsv.S = 120; //100
				_hsv.V = 255 * (i < maxIterations);

				t_rgb rgb = hsv_to_rgb(_hsv);

				mlx_pixel_put(*mlx_ptr, *win_ptr, x, y, hex_int_converter(RGBToHexadecimal(rgb)));
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

	fr->cRe = sin(6.28 / 720 * (x));
	fr->cIm = _ABS(cos(6.28 / 720 * (y))) / 3;