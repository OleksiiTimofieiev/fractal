/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 12:32:49 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/18 13:13:40 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	*julia_left_up(void *var)
{
	t_m_buf	m_buf;
	t_data	*data;
	int		i;

	m_buf.y = 0;
	data = (t_data *)var;
	while (m_buf.y < 399)
	{
		m_buf.x = 0;
		while (m_buf.x < 499)
		{
			m_buf.newRe = 1.5 * (m_buf.x - data->width / 2) / (0.5 * data->zoom * data->width) + (data->move_x);
			m_buf.newIm = (m_buf.y - data->height / 2) / (0.5 * data->zoom * data->height) + (data->move_y);
			j_calculations(&i, m_buf, data);
			j_set_color(&m_buf.rgb, i, data->max_iterations);
			fill_pixel(data->mlx_get_data_addr, m_buf.x, m_buf.y, m_buf.rgb);
			m_buf.x++;
		}
		m_buf.y++;
	}
	pthread_exit(0);
}

void	*julia_left_down(void *var)
{
	t_m_buf	m_buf;
	t_data	*data;
	int		i;

	m_buf.y = 399;
	data = (t_data *)var;
	while (m_buf.y < 800)
	{
		m_buf.x = 0;
		while (m_buf.x < 499)
		{
			m_buf.newRe = 1.5 * (m_buf.x - data->width / 2) / (0.5 * data->zoom * data->width) + (data->move_x);
			m_buf.newIm = (m_buf.y - data->height / 2) / (0.5 * data->zoom * data->height) + (data->move_y);
			j_calculations(&i, m_buf, data);
			j_set_color(&m_buf.rgb, i, data->max_iterations);
			fill_pixel(data->mlx_get_data_addr, m_buf.x, m_buf.y, m_buf.rgb);
			m_buf.x++;
		}
		m_buf.y++;
	}
	pthread_exit(0);
}

void	*julia_right_up(void *var)
{
	t_m_buf	m_buf;
	t_data	*data;
	int		i;

	m_buf.y = 0;
	data = (t_data *)var;
	while (m_buf.y < 399)
	{
		m_buf.x = 499;
		while (m_buf.x < 1000)
		{
			m_buf.newRe = 1.5 * (m_buf.x - data->width / 2) / (0.5 * data->zoom * data->width) + (data->move_x);
			m_buf.newIm = (m_buf.y - data->height / 2) / (0.5 * data->zoom * data->height) + (data->move_y);
			j_calculations(&i, m_buf, data);
			j_set_color(&m_buf.rgb, i, data->max_iterations);
			fill_pixel(data->mlx_get_data_addr, m_buf.x, m_buf.y, m_buf.rgb);
			m_buf.x++;
		}
		m_buf.y++;
	}
	pthread_exit(0);
}

void	*julia_right_down(void *var)
{
	t_m_buf	m_buf;
	t_data	*data;
	int		i;

	m_buf.y = 399;
	data = (t_data *)var;
	while (m_buf.y < 800)
	{
		m_buf.x = 499;
		while (m_buf.x < 1000)
		{
			m_buf.newRe = 1.5 * (m_buf.x - data->width / 2) / (0.5 * data->zoom * data->width) + (data->move_x);
			m_buf.newIm = (m_buf.y - data->height / 2) / (0.5 * data->zoom * data->height) + (data->move_y);
			j_calculations(&i, m_buf, data);
			j_set_color(&m_buf.rgb, i, data->max_iterations);
			fill_pixel(data->mlx_get_data_addr, m_buf.x, m_buf.y, m_buf.rgb);
			m_buf.x++;
		}
		m_buf.y++;
	}
	pthread_exit(0);
}

void julia(t_data *data)
{
	pthread_t		tids[4];
	pthread_attr_t	attr;

	pthread_attr_init(&attr);
	pthread_create(&tids[0], &attr, julia_left_up, data);
	pthread_create(&tids[1], &attr, julia_left_down, data);
	pthread_create(&tids[2], &attr, julia_right_up, data);
	pthread_create(&tids[3], &attr, julia_right_down, data);
	pthread_join(tids[0], NULL);
	pthread_join(tids[1], NULL);
	pthread_join(tids[2], NULL);
	pthread_join(tids[3], NULL);
	mlx_put_image_to_window(data->m_mlx_ptr, data->m_win_ptr,
							data->mlx_new_image, 0, 0);
}
