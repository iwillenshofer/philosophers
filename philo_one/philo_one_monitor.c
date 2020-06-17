/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_monitor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:55:30 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/15 10:51:25 by iwillens         ###   ########.fr       */
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
		gettimeofday(&time, NULL);
		pthread_mutex_lock((&(p->last_eaten_lock)));
		time_lasteaten = p->last_eaten;
		pthread_mutex_unlock((&(p->last_eaten_lock)));
		if (ttime_to_ms(time) > ttime_to_ms(time_lasteaten) + g->time_to_die)
		{
			ph_setaction(p, AC_DIED);
			break ;
		}
	}
	return (0);
}
