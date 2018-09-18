/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_infrastructure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:04:02 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/18 13:05:16 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	j_set_color(t_rgb *rgb, int iterations_per_pixel, int max_iterations)
{
	if (iterations_per_pixel == max_iterations)
	{
		rgb->r = 0;
		rgb->g = 0;
		rgb->b = 0;
	}
	else if (iterations_per_pixel < 64)
	{
		rgb->r = iterations_per_pixel * 2;
		rgb->g = 50;
		rgb->b = 15;
	}
	else if (iterations_per_pixel < 128)
	{
		rgb->r = 15;
		rgb->g = 0;
		rgb->b = (((iterations_per_pixel - 64) * 128) / 126) + 128;
	}
}

void	j_calculations(int *i, t_m_buf m_buf, t_data *data)
{
	*i = 0;
	while (*i < data->max_iterations)
	{
		m_buf.oldRe = m_buf.newRe;
		m_buf.oldIm = m_buf.newIm;
		m_buf.newRe = m_buf.oldRe * m_buf.oldRe - m_buf.oldIm *
			m_buf.oldIm + data->c_re;
		m_buf.newIm = 2 * m_buf.oldRe * m_buf.oldIm + data->c_im;
		if ((m_buf.newRe * m_buf.newRe + m_buf.newIm * m_buf.newIm) > 4)
			break ;
		(*i)++;
	}
}
