/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:34:17 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/16 18:04:05 by otimofie         ###   ########.fr       */
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

	validation(argc, argv[1], &data);

	constructor(&data);

	data.fractol(&data);

	
	mlx_hook(data.m_win_ptr, 4, 1L << 1, zoom, &data);

	mlx_loop(data.m_mlx_ptr);


	return (0);
	}

