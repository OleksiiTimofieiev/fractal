/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_infrastructure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:45:08 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/18 13:19:48 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_color_m(t_rgb *rgb, int iterations_per_pixel, int max_iterations)
{
	if (iterations_per_pixel == max_iterations)
	{
		rgb->r = 51;
		rgb->g = 0;
		rgb->b = 0;
	}
	else if (iterations_per_pixel < 64)
	{
		rgb->r = iterations_per_pixel * 2;
		rgb->g = 0;
		rgb->b = 0;
	}
	else if (iterations_per_pixel < 128)
	{
		rgb->r = (((iterations_per_pixel - 64) * 128) / 126) + 128;
		rgb->g = 0;
		rgb->b = 0;
	}
}

void	buf_zero(t_m_buf *buf)
{
	buf->new_re = 0;
	buf->new_im = 0;
	buf->old_re = 0;
	buf->old_im = 0;
}

void	m_calculations(t_data *data, t_m_buf m_buf, int *i)
{
	*i = 0;
	while (*i < data->max_iterations)
	{
		m_buf.old_re = m_buf.new_re;
		m_buf.old_im = m_buf.new_im;
		m_buf.new_re = m_buf.old_re * m_buf.old_re - m_buf.old_im *
						m_buf.old_im + m_buf.pr;
		m_buf.new_im = 2 * m_buf.old_re * m_buf.old_im + m_buf.pi;
		if ((m_buf.new_re * m_buf.new_re + m_buf.new_im * m_buf.new_im) > 4)
			break ;
		(*i)++;
	}
}
