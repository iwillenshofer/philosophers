/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:51:41 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/15 10:50:30 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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
	sem_close(g->forks);
	sem_close(g->writelock);
	sem_unlink("fork");
	sem_unlink("writelock");
	while (p)
	{
		sem_close((p->lasteatenlock));
		sem_unlink(p->sem_name);
		free(p->sem_name);
		p = p->next;
		if (p == g->philosopher)
			break ;
	}
}
