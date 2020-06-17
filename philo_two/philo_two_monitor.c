/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_monitor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:55:30 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/15 10:51:57 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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
		sem_wait(p->lasteatenlock);
		time_lasteaten = p->last_eaten;
		if (ttime_to_ms(time) > ttime_to_ms(time_lasteaten) + g->time_to_die)
		{
			ph_setaction(p, AC_DIED);
			sem_post(p->lasteatenlock);
			sem_post(g->forks);
			sem_post(g->forks);
			break ;
		}
		sem_post(p->lasteatenlock);
	}
	return (0);
}
