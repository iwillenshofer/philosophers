/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 15:29:30 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/20 03:49:28 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

uint64_t				ttime_to_ms(t_time time)
{	
	uint64_t 	t;
	t = time.tv_sec * (uint64_t)1000000;
	t += time.tv_usec;
	return ((t) / (uint64_t)1000);
}

uint64_t				get_time()
{
	t_time now;

	gettimeofday(&now, NULL);
	return (ttime_to_ms(now));
}

void					ft_usleep(uint64_t ms)
{
	uint64_t 	start;

	start = get_time();
	while (get_time() < start + ms)
		usleep(50);
}

long					get_elapsedtime(t_game *g)
{
	t_time now;

	gettimeofday(&now, NULL);
	return (ttime_to_ms(now) - g->start_time_ms);
}
