/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_monitor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:55:30 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/21 15:40:08 by iwillens         ###   ########.fr       */
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
	ft_usleep(50);
	while (p && !((g->someone_died)) && (!((g->all_finished))))
	{
		gettimeofday(&time, NULL);
		sem_wait(p->lasteatenlock);
		time_lasteaten = p->last_eaten;
		if (ttime_to_ms(time_lasteaten) + g->time_to_die < ttime_to_ms(time))
		{
			ph_setaction(p, AC_DIED, get_elapsedtime(p->game));
			sem_post(p->lasteatenlock);
			break ;
		}
		sem_post(p->lasteatenlock);
		ft_usleep(1);
	}
	return (0);
}
