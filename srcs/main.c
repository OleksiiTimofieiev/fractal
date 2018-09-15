/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:34:17 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/15 16:58:45 by otimofie         ###   ########.fr       */
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
// 1. Analyze code;
// 2. Putpixel for each type of the fractol;
// 3. Mouse events(scake nad change of the Julia params);
// 4. Image string which is located in the structure;
// 5. threads;

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
#define MAXCOUNT 500

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


			cx = -0.6;
			cy = 0.11;

			cx = sin(6.28 / 720 * (400));
			cy = fabs(cos(6.28 / 720 * (450)));
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

		void Cyrcle(void **mlx_ptr, void **win_ptr, int width, int height)
		{
			int x, y, z;
			int mx, my;

			mx = height / 2;
			my = width / 2;

			for (y = (-my); y <= my; y++)
				for (x = (-mx); x <= mx; x++)
				{
					z = 2 * (x * x + y * y);
					// putpixel(mx + x, my + y, int(z / 16));
					t_rgb rgb;
					rgb.R = mx + x;
					rgb.G = my + y;
					rgb.B = (int)(z / 16);

					mlx_pixel_put(*mlx_ptr, *win_ptr, mx + x, my + y, hex_int_converter(RGBToHexadecimal(rgb)));
				}


}

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
	int height = 800;
	int width = 800;

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
	double MinIm = 2;
	double MaxIm = -2;

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
	void *win_ptr = mlx_new_window(mlx_ptr, width, height, "mandelbrot");
	// mandelbrot4(&mlx_ptr, &win_ptr, MinRe, MaxRe, MinIm, MaxIm);

	julia4(&mlx_ptr, &win_ptr, MinRe, MaxRe, MinIm, MaxIm);

	// Cyrcle(&mlx_ptr, &win_ptr, width, height);


	mlx_hook(win_ptr, 4, 1L << 1, click, (void *)0);
	// mlx_hook(win_ptr, 6, 1L << 1, mouse_move, (void *)0);

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