/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 09:35:26 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 14:42:14 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


// static int hex_int_converter(char *input)
// {
// 	int base;
// 	size_t len;
// 	int dec_val;
// 	int i;

// 	base = 1;
// 	len = ft_strlen(input);
// 	dec_val = 0;
// 	i = len - 1;
// 	while (i >= 0)
// 	{
// 		if (input[i] >= '0' && input[i] <= '9')
// 		{
// 			dec_val += (input[i] - 48) * base;
// 			base = base * 16;
// 		}
// 		else if (input[i] >= 'A' && input[i] <= 'F')
// 		{
// 			dec_val += (input[i] - 55) * base;
// 			base = base * 16;
// 		}
// 		i--;
// 	}
// 	return (dec_val);
// }

static void set_color(t_rgb *rgb, int IterationsPerPixel, int MaxIterations)
{
	if (IterationsPerPixel == MaxIterations)
	{
		rgb->R = 51;
		rgb->G = 0;
		rgb->B = 0;
	}
	else if (IterationsPerPixel < 64)
	{
		rgb->R = IterationsPerPixel * 2;
		rgb->G = 0;
		rgb->B = 0;
	}
	else if (IterationsPerPixel < 128)
	{
		rgb->R = (((IterationsPerPixel - 64) * 128) / 126) + 128;
		rgb->G = 0;
		rgb->B = 0;
	}
	
}

void fill_pixel(char *my_image_string, int x, int y, t_rgb rgb)
{
	my_image_string[x * 4 + 4000 * y] = rgb.R;
	my_image_string[x * 4 + 4000 * y + 1] = rgb.G;
	my_image_string[x * 4 + 4000 * y + 2] = rgb.B;
}

void mandelbrot(t_data *data) // different funcs;
{
	//each iteration, it calculates: new = old*old + c, where c is a constant and old starts at current pixel
	double pr, pi;	
	
	
	
					   //real and imaginary part of the pixel p
	double newRe, newIm, oldRe, oldIm; //real and imaginary parts of new and old

	
	// basic zoom;
	//you can change these to zoom and change position
	// ColorRGB color;							  //the RGB color value for the pixel
	int maxIterations = 128; //after how much iterations the function should stop
	int i;
		// int showText = 0;
		int x = 0;
		int y = 0;
		
	for (y = 0; y < data->height; y++)
	{
		for (x = 0; x < data->width; x++)
		{
			//calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
			pr = 1.5 * (x - data->width / 2) / (0.5 * data->zoom * data->width) + (data->moveX);
			pi = (y - data->height / 2) / (0.5 * data->zoom * data->height) + (data->moveY);
			newRe = newIm = oldRe = oldIm = 0; //these should start at 0,0
			//i will represent the number of iterations
			
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

			// mlx_pixel_put(data->m_mlx_ptr, data->m_win_ptr, x, y, hex_int_converter(RGBToHexadecimal(rgb)));
			t_rgb rgb;
			
			set_color(&rgb, i, maxIterations);

			fill_pixel(data->mlx_get_data_addr, x, y, rgb);
		}

	}
	mlx_put_image_to_window(data->m_mlx_ptr, data->m_win_ptr, data->mlx_new_image, 0, 0);
}

