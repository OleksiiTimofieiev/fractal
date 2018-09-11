// TODO: leaks;
// TODO: norminette;
// TODO: perror;
// TODO: types: Julia, Mandelbrot, ?
// TODO: Julia set without clicking -> change of the parameter;
// TODO: mouse zoom;
// TODO: several colors to show the depth of the fractol;
// TODO: ESC -> to exit the program;
// TODO: use images for printing the fina image;
// TODO: multi threading;
// TODO: Two valid parameters in the command line, resulting in two fractals in two windows.

#include "../includes/fractol.h"

int		main(int argc, char **argv)
{
	validation(argc, argv[2]);
	return (0);
}
