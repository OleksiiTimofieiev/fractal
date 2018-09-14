/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:34:17 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/14 16:01:27 by otimofie         ###   ########.fr       */
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

// double mouseRe = (double)mouse_x / (WIN_L / (e->Re.max - e->Re.min)) + e->Re.min;
// double mouseIm = (double)mouse_y / (WIN_H / (e->Im.max - e->Im.min)) + e->Im.min;

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
					_hsv.S = 120;
					_hsv.V = 255 * (n < MaxIterations);

					t_rgb rgb = hsv_to_rgb(_hsv);

					mlx_pixel_put(*mlx_ptr, *win_ptr, x, y, hex_int_converter(RGBToHexadecimal(rgb)));
				}
			}
		}
	}

	double interpolate(double start, double end, double interpolation)
	{
		return start + ((end - start) * interpolation);
	}



	void Julia2(void **mlx_ptr, void **win_ptr, int width, int height)
	{
		// borders section;
		double MinRe = -2.0;
		double MaxRe = 1.0;
		double MinIm = -1.2;
		double MaxIm = MinIm + (MaxRe - MinRe) * height / width;

		// void applyZoom(t_fractal * e, double mouseRe, double mouseIm, double zoomFactor)
		// {

		double mouseRe = (double)250 / (1000 / (MaxRe - MinRe)) + MinRe;
		double mouseIm = (double)400 / (800 / (MaxIm - MinIm)) + MinIm;
		
		double interpolation = 1.0 / 1.01;
		MinRe = interpolate(mouseRe, MinRe, interpolation);
		MinIm = interpolate(mouseIm, MinIm, interpolation);
		MaxRe = interpolate(mouseRe, MaxRe, interpolation);
		MaxIm = interpolate(mouseIm, MaxIm, interpolation);
		// }

		// to get the coordinates in the complex numbers;
		double Re_factor = (MaxRe - MinRe) / (width - 1);
		double Im_factor = (MaxIm - MinIm) / (height - 1);

		int MaxIterations = 450;

		for (int y = 0; y < height; ++y)
		{
			// get the coordinates in the comlex formaat;
			double c_im = MaxIm - y * Im_factor;

			for (int x = 0; x < width; ++x)
			{
				// get the coordinates in the comlex formaat;
				double c_re = MinRe + x * Re_factor;

				double Z_re = c_re, Z_im = c_im;

				// Final complex numbers according to the coordinates;
				
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
					Z_im = 2 * Z_re * Z_im + 0.350;
					Z_re = Z_re2 - Z_im2 + 0.353;
				}
				if (isInside)
				{
					t_hsv _hsv;

					_hsv.H = n % 256;
					_hsv.S = 120;
					_hsv.V = 255 * (n < MaxIterations);

					t_rgb rgb = hsv_to_rgb(_hsv);

					mlx_pixel_put(*mlx_ptr, *win_ptr, x, y, hex_int_converter(RGBToHexadecimal(rgb)));
				}
			}
		}
	}

	void mandelbrot3(void **mlx_ptr, void **win_ptr)
	{
		int iX, iY;
		const int iXmax = 800;
		const int iYmax = 800;
		/* world ( double) coordinate = parameter plane*/
		double Cx, Cy;
		const double CxMin = -2.5;
		const double CxMax = 1.5;
		const double CyMin = -2.0;
		const double CyMax = 2.0;
		/* */
		double PixelWidth = (CxMax - CxMin) / iXmax;
		double PixelHeight = (CyMax - CyMin) / iYmax;
		/* color component ( R or G or B) is coded from 0 to 255 */
		/* it is 24 bit color RGB file */
		// const int MaxColorComponentValue = 255;
		// char *filename = "new1.ppm";
		// char *comment = "# "; /* comment should start with # */
		// static unsigned char color[3];
		/* Z=Zx+Zy*i  ;   Z0 = 0 */
		double Zx, Zy;
		double Zx2, Zy2; /* Zx2=Zx*Zx;  Zy2=Zy*Zy  */
		/*  */
		int Iteration;
		const int IterationMax = 200;
		/* bail-out value , radius of circle ;  */
		const double EscapeRadius = 2;
		double ER2 = EscapeRadius * EscapeRadius;
		/*create new file,give it a name and open it in binary mode  */

		/* compute and write image data bytes to the file*/
		for (iY = 0; iY < iYmax; iY++)
		{
			Cy = CyMin + iY * PixelHeight;
			if (fabs(Cy) < PixelHeight / 2)
				Cy = 0.0; /* Main antenna */
			for (iX = 0; iX < iXmax; iX++)
			{
				Cx = CxMin + iX * PixelWidth;
				/* initial value of orbit = critical point Z= 0 */
				Zx = 0.0;
				Zy = 0.0;
				Zx2 = Zx * Zx;
				Zy2 = Zy * Zy;
				/* */
				for (Iteration = 0; Iteration < IterationMax && ((Zx2 + Zy2) < ER2); Iteration++)
				{
					Zy = 2 * Zx * Zy + Cy;
					Zx = Zx2 - Zy2 + Cx;
					Zx2 = Zx * Zx;
					Zy2 = Zy * Zy;
				};
				// /* compute  pixel color (24 bit = 3 bytes) */
				// if (Iteration == IterationMax)
				// { /*  interior of Mandelbrot set = black */
				// 	color[0] = 0;
				// 	color[1] = 0;
				// 	color[2] = 0;
				// }
				// else
				// {					/* exterior of Mandelbrot set = white */
				// 	color[0] = 255; /* Red*/
				// 	color[1] = 255; /* Green */
				// 	color[2] = 255; /* Blue */
				// };
				// /*write color to the file*/
				// fwrite(color, 1, 3, fp);
				t_hsv _hsv;

				_hsv.H = Iteration % 256;
				_hsv.S = 120;
				_hsv.V = 255 * (Iteration < IterationMax);

				t_rgb rgb = hsv_to_rgb(_hsv);

				mlx_pixel_put(*mlx_ptr, *win_ptr, iX, iY, hex_int_converter(RGBToHexadecimal(rgb)));
			}
		}


	}
#define MAXCOUNT 120

	void mandelbrot4(void **mlx_ptr, void **win_ptr, float left, float top, float xside, float yside)
	{
			float xscale, yscale, zx, zy, cx, tempx, cy;
			int x, y; /* i, j;*/
			int maxx, maxy, count;

			// getting maximum value of x-axis of screen
			maxx = 800;

			// getting maximum value of y-axis of screen
			maxy = 800;

			// setting up the xscale and yscale
			xscale = xside / maxx;
			yscale = yside / maxy;

			// scanning every point in that rectangular area.
			// Each point represents a Complex number (x + yi).
			// Iterate that complex number
			for (y = 1; y <= maxy - 1; y++)
			{
				for (x = 1; x <= maxx - 1; x++)
				{
					// c_real
					cx = x * xscale + left;

					// c_imaginary
					cy = y * yscale + top;

					// z_real
					zx = 0;

					// z_imaginary
					zy = 0;
					count = 0;

					// Calculate whether c(c_real + c_imaginary) belongs
					// to the Mandelbrot set or not and draw a pixel
					// at coordinates (x, y) accordingly
					// If you reach the Maximum number of iterations
					// and If the distance from the origin is
					// greater than 2 exit the loop
					while ((zx * zx + zy * zy < 4) && (count < MAXCOUNT))
					{
						// Calculate Mandelbrot function
						// z = z*z + c where z is a complex number

						// tempx = z_real*_real - z_imaginary*z_imaginary + c_real
						tempx = zx * zx - zy * zy + cx;

						// 2*z_real*z_imaginary + c_imaginary
						zy = 2 * zx * zy + cy;

						// Updating z_real = tempx
						zx = tempx;

						// Increment count
						count = count + 1;
					}

					// To display the created fractal
					t_hsv _hsv;

					_hsv.H = count % 256;
					_hsv.S = 120;
					_hsv.V = 255 * (count < MAXCOUNT);

					t_rgb rgb = hsv_to_rgb(_hsv);

					mlx_pixel_put(*mlx_ptr, *win_ptr, x, y, hex_int_converter(RGBToHexadecimal(rgb)));
				}
			}
		}

		void julia4(void **mlx_ptr, void **win_ptr, float left, float top, float xside, float yside)
		{
			float xscale, yscale, zx, zy, cx, tempx, cy;
			int x, y; /* i, j;*/
			int maxx, maxy, count;

			// getting maximum value of x-axis of screen
			maxx = 800;

			// getting maximum value of y-axis of screen
			maxy = 800;

			// setting up the xscale and yscale
			xscale = xside / maxx;
			yscale = yside / maxy;


			cx = -0.7;
			cy = 0.27015;

			// cx = sin(6.28 / 720 * (420));
			// cy = fabs(cos(6.28 / 720 * (470)));
			// scanning every point in that rectangular area.
			// Each point represents a Complex number (x + yi).
			// Iterate that complex number
			for (y = 1; y <= maxy - 1; y++)
			{
				for (x = 1; x <= maxx - 1; x++)
				{
					// c_real
					zx = x * xscale + left;

					// c_imaginary
					zy = y * yscale + top;

					count = 0;

					// Calculate whether c(c_real + c_imaginary) belongs
					// to the Mandelbrot set or not and draw a pixel
					// at coordinates (x, y) accordingly
					// If you reach the Maximum number of iterations
					// and If the distance from the origin is
					// greater than 2 exit the loop
					while ((zx * zx + zy * zy < 4) && (count < MAXCOUNT))
					{
						// Calculate Mandelbrot function
						// z = z*z + c where z is a complex number

						// tempx = z_real*_real - z_imaginary*z_imaginary + c_real
						tempx = zx * zx - zy * zy;

						// 2*z_real*z_imaginary + c_imaginary
						zy = 2 * zx * zy + cy;

						// Updating z_real = tempx
						zx = tempx + cx;

						// Increment count
						count++;
					}

					// To display the created fractal
					t_hsv _hsv;

					_hsv.H = count % 256;
					_hsv.S = 120;
					_hsv.V = 255 * (count < MAXCOUNT);

					t_rgb rgb = hsv_to_rgb(_hsv);

					mlx_pixel_put(*mlx_ptr, *win_ptr, x, y, hex_int_converter(RGBToHexadecimal(rgb)));
				}
			}
		}

		int main(int argc, char **argv)
		{
			int height = 800;
			int width = 800;

			float left, top, xside, yside;

			// const double CxMin = -2.5;
			// const double CxMax = 1.5;
			// const double CyMin = -2.0;
			// const double CyMax = 2.0;

			// left = -1.5;
			// top = 1.0;
			// xside = 2;
			// yside = -2;

			left = -1.5;
			top = 1.2;
			xside = 2;
			yside = -2;

			double MinRe = -1.5;
			double MaxRe = 1.2;
			double MinIm = 2;
			double MaxIm = -2;

			// double mouseRe = (double)200 / (800 / (MaxRe - MinRe)) + MinRe;
			// double mouseIm = (double)300 / (800 / (MaxIm - MinIm)) + MinIm;

			// double interpolation = 1.0 / 1.0; // 1.5 = max
			// MinRe = interpolate(mouseRe, MinRe, interpolation);
			// MinIm = interpolate(mouseIm, MinIm, interpolation);
			// MaxRe = interpolate(mouseRe, MaxRe, interpolation);
			// MaxIm = interpolate(mouseIm, MaxIm, interpolation);


			validation(argc, argv[1]);

			void *mlx_ptr = mlx_init();
			void *win_ptr = mlx_new_window(mlx_ptr, width, height, "mandelbrot");
			// mandelbrot4(&mlx_ptr, &win_ptr, left, top, xside, yside);

			julia4(&mlx_ptr, &win_ptr, MinRe, MaxRe, MinIm, MaxIm);

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

	// fr->cRe = sin(6.28 / 720 * (x));
	// fr->cIm = _ABS(cos(6.28 / 720 * (y))) / 3;