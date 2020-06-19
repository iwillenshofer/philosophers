/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 15:30:04 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/19 17:49:52 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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

void					ft_usleep(long int us)
{
	uint64_t 	start;

	start = get_time();
	while (get_time() < start + us)
		usleep(50);
}

long					get_elapsedtime(t_game *g)
{
	t_time now;

	gettimeofday(&now, NULL);
	return (ttime_to_ms(now) - g->start_time_ms);
}
