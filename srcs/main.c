/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:34:17 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/17 15:32:14 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// TODO: norminette;

int main(int argc, char **argv)
{
	t_data data;
	
	// system("afplay ./sounds/Agnus_Dei.mp3&");
	validation(argc, argv[1], &data);
	constructor(&data);
	data.fractol(&data);
	mlx_hook(data.m_win_ptr, 4, 1L << 1, zoom, &data);
	mlx_key_hook(data.m_win_ptr, deal_with_keyboard, &data);
	mlx_hook(data.m_win_ptr, 6, 1L << 1, mouse_move, &data);
	mlx_loop(data.m_mlx_ptr);
	return (0);
}
