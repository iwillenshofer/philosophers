/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_monitor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:55:30 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/17 13:50:01 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*monitor(void *philosopher)
{
	t_game			*g;
	t_philosophers	*p;
	t_time			time;
	t_time			time_lasteaten;

	p = (t_philosophers*)philosopher;
	g = p->game;
	while (p && !(g->someone_died) && (!(g->all_finished)))
	{
		pthread_mutex_lock((&(p->last_eaten_lock)));
		gettimeofday(&time, NULL);
		time_lasteaten = p->last_eaten;
		if (ttime_to_ms(time) > ttime_to_ms(time_lasteaten) + g->time_to_die)
		{
			ph_setaction(p, AC_DIED);
		}
		pthread_mutex_unlock((&(p->last_eaten_lock)));
		usleep(5);
	}
	return (0);
}
