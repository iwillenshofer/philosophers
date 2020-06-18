/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 15:29:30 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/17 21:06:36 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"


unsigned long int		ttime_to_ms(t_time time)
{
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

unsigned long int		get_time(t_game *g)
{
	t_time now;
	gettimeofday(&now, NULL);

	return (((now.tv_sec - g->start_time.tv_sec) * 1000)
		+ ((now.tv_usec - g->start_time.tv_usec) / 1000));
}

void					ft_usleep(long int us)
{
	t_time start;
	t_time cur;

	gettimeofday(&start, NULL);
	gettimeofday(&cur, NULL);
	while ((((cur.tv_sec - start.tv_sec) * 1000000)
		+ ((cur.tv_usec - start.tv_usec))) <= us)
	{
		gettimeofday(&cur, NULL);
		usleep(100);
	}
}
