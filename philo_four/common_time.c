/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 15:30:04 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/18 13:30:46 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

unsigned long int		ttime_to_ms(t_time time)
{
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

unsigned long int		get_time(t_game *g)
{
	t_time now;
	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000 + now.tv_usec / 1000)
		- (g->start_time.tv_sec * 1000 + g->start_time.tv_usec / 1000));
}

void					ft_usleep(long int us)
{
	t_time start;
	t_time cur;

	gettimeofday(&cur, NULL);
	gettimeofday(&start, NULL);
	while ((cur.tv_sec * 1000000 + cur.tv_usec)/1000 <
		(start.tv_sec * 1000000 + start.tv_usec )/1000 + us)
	{
		gettimeofday(&cur, NULL);
		usleep(100);
	}
}
