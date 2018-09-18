/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_infrastructure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:45:08 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/18 11:46:53 by otimofie         ###   ########.fr       */
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
	buf->newRe = 0;
	buf->newIm = 0;
	buf->oldRe = 0;
	buf->oldIm = 0;
}

void	m_calculations(t_data *data, t_m_buf m_buf, int *i)
{
	*i = 0;
	while (*i < data->max_iterations)
	{
		m_buf.oldRe = m_buf.newRe;
		m_buf.oldIm = m_buf.newIm;
		m_buf.newRe = m_buf.oldRe * m_buf.oldRe - m_buf.oldIm *
						m_buf.oldIm + m_buf.pr;
		m_buf.newIm = 2 * m_buf.oldRe * m_buf.oldIm + m_buf.pi;
		if ((m_buf.newRe * m_buf.newRe + m_buf.newIm * m_buf.newIm) > 4)
			break ;
		(*i)++;
	}
}
