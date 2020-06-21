/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_monitor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:55:30 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/20 04:16:33 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*monitor(void *philosopher)
{
	t_game			*g;
	t_philosophers	*p;
	t_time			time;
	t_time			time_lasteaten;

	p = (t_philosophers*)philosopher;
	g = p->game;
	while (p && !((g->someone_died)) && (!((g->all_finished))))
	{
		sem_wait(p->game->deadlock);
		if ((p->game->someone_died))
			exit(0);
		sem_post(p->game->deadlock);
		gettimeofday(&time, NULL);
		sem_wait(p->lasteatenlock);
		time_lasteaten = p->last_eaten;
		if (ttime_to_ms(time) > ttime_to_ms(time_lasteaten) + g->time_to_die)
		{
			ph_setaction(p, AC_DIED, get_elapsedtime(p->game));
			sem_post(p->lasteatenlock);
			break ;
		}
		sem_post(p->lasteatenlock);
		usleep(1000);
	}
	return (0);

}
