/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:51:41 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/21 14:51:53 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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
}

void	destroy_mutex(t_game *g)
{
	t_philosophers	*p;

	p = g->philosopher;
	pthread_mutex_destroy((&(g->writelock)));
	pthread_mutex_destroy((&(g->finished_eating_lock)));
	pthread_mutex_destroy((&(g->someone_died_lock)));
	while (p)
	{
		pthread_mutex_destroy(&(p->last_eaten_lock));
		pthread_mutex_destroy((&(p->right_fork->lock)));
		p = p->next;
		if (p == g->philosopher)
			break ;
	}
}
