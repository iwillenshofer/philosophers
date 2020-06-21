/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:51:41 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/21 14:55:49 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	close_sems(t_game *g)
{
	sem_close(g->forkslock);
	sem_close(g->forks);
	sem_close(g->writelock);
	sem_close(g->deadlock);
	sem_close(g->eatenlock);
	sem_unlink("fork");
	sem_unlink("writelock");
	sem_unlink("forkslock");
	sem_unlink("deadlock");
	sem_unlink("eatenlock");
}

void	wait_for_end(t_game *g)
{
	t_philosophers	*p;

	p = g->philosopher;
	while (p)
	{
		pthread_join(p->thread, NULL);
		p = p->next;
		if (p == g->philosopher)
			break ;
	}
	close_sems(g);
	p = g->philosopher;
	while (p)
	{
		sem_close((p->lasteatenlock));
		sem_unlink(p->sem_name);
		pthread_join(p->monitor_thread, NULL);
		free(p->sem_name);
		p = p->next;
		if (p == g->philosopher)
			break ;
	}
}
