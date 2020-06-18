/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 21:47:52 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/13 16:17:52 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

/*
** specific initialization for philo_one
** sets all the forks left and right to the philosophers
*/

void	philo_one_init(t_game *g)
{
	t_philosophers	*p;
	t_forks			*fork;

	fork = g->fork;
	p = g->philosopher;
	pthread_mutex_init(&(g->someone_died_lock), NULL);
	pthread_mutex_init(&(g->finished_eating_lock), NULL);
	pthread_mutex_init(&(g->writelock), NULL);
	while (p)
	{
		pthread_mutex_init(&(p->last_eaten_lock), NULL);
		pthread_mutex_init(&(fork->lock), NULL);
		p->left_fork = fork;
		p->next->right_fork = fork;
		p = p->next;
		fork = fork->next;
		if (p == g->philosopher)
			break ;
	}
}
