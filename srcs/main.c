/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:34:17 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 17:51:13 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// TODO: leaks;
// TODO: norminette;
// TODO: ESC -> to exit the program;

// TODO: Plan:
// threads;
// different windows;
// stop with if;
// music
// zoom without movements;





	// mlx_hook(data.m_win_ptr, 6, 1L << 1, mouse_move, &data);

int main(int argc, char **argv)
{
	t_data data;
	// void (*f)(t_data *data);

	validation(argc, argv[1]);

	constructor(&data);

	julia(&data);
	// mandelbrot(&data);


	// different func;
	
	mlx_hook(data.m_win_ptr, 4, 1L << 1, zoom, &data);

	mlx_loop(data.m_mlx_ptr);


	return (0);
	}

