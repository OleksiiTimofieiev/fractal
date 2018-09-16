/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:27:44 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 20:51:48 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	void	options(void)
{
	ft_putstr("Options:\n\n");
	ft_putstr("1. mandelbrot;\n");
	ft_putstr("2. julia;\n");
	ft_putstr("3. cyrcle;\n");
	ft_putstr("4. mult;\n");
}

static	int		check_fractol_type(char *fractol)
{
	if (ft_strequ(fractol, "mandelbrot"))
		return (1);
	else if (ft_strequ(fractol, "julia"))
		return (1);
	else if (ft_strequ(fractol, "cyrcle"))
		return (1);
	else if (ft_strequ(fractol, "mult"))
		return (1);
	return (0);
}

void validation(int argc, char *argv, t_data *data)
{
	data->fractol = &mandelbrot;
	 if (argc != 2 || !check_fractol_type(argv))
	{
		options();
		exit(0);
	}
	else if (ft_strequ("mandelbrot", argv))
	{
		data->fractol = &mandelbrot;
	}
	else if (ft_strequ("julia", argv))
	{
		data->fractol = &julia;
	}
	else if (ft_strequ("cyrcle", argv)) // TODO: make it;
	{
		data->fractol = &julia;
	}
}
