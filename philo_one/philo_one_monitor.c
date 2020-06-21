/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_monitor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:55:30 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/21 15:29:41 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	unlock_forks(t_game *g)
{
	t_philosophers *p;

	p = g->philosopher;
	while (p)
	{
		pthread_mutex_unlock(&(p->left_fork->lock));
		p = p->next;
		if (p == g->philosopher)
			break ;
	}
}

void	*monitor(void *philosopher)
{
	t_game			*g;
	t_philosophers	*p;
	t_time			time;
	t_time			time_lasteaten;
	int				i;

	i = 0;
	p = (t_philosophers*)philosopher;
	g = p->game;
	ft_usleep(50);
	while (p && !(g->someone_died) && (!(g->all_finished)))
	{
		pthread_mutex_lock((&(p->last_eaten_lock)));
		gettimeofday(&time, NULL);
		time_lasteaten = p->last_eaten;
		if ( ttime_to_ms(time_lasteaten) + g->time_to_die < ttime_to_ms(time))
		{
			ph_setaction(p, AC_DIED, get_elapsedtime(p->game));
			unlock_forks(g);
		}
		pthread_mutex_unlock((&(p->last_eaten_lock)));
		usleep(1000);
	}
	return (0);
}
