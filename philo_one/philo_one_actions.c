/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:54:15 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/14 19:26:44 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_think(t_philosophers *p)
{
	ph_setaction(p, AC_THINKING);
}

void	philo_sleep(t_philosophers *p)
{
	ph_setaction(p, AC_SLEEPING);
	usleep(p->game->time_to_sleep * 1000);
}

void	philo_getfork(t_philosophers *p, char side)
{
	if (side == FORK_RIGHT)
	{
		pthread_mutex_lock(&(p->right_fork->lock));
		ph_setaction(p, AC_TAKENRIGHTFORK);
	}
	else if (side == FORK_LEFT)
	{
		pthread_mutex_lock(&(p->left_fork->lock));
		ph_setaction(p, AC_TAKENLEFTFORK);
	}
}

void	philo_eat(t_philosophers *p)
{
	philo_getfork(p, p->number % 2 ? FORK_LEFT : FORK_RIGHT);
	philo_getfork(p, p->number % 2 ? FORK_RIGHT : FORK_LEFT);
	pthread_mutex_lock((&(p->last_eaten_lock)));
	ph_setaction(p, AC_EATING);
	gettimeofday(&(p->last_eaten), NULL);
	pthread_mutex_unlock((&(p->last_eaten_lock)));
	usleep(p->game->time_to_eat * 1000);
	pthread_mutex_unlock((&(p->left_fork->lock)));
	pthread_mutex_unlock((&(p->right_fork->lock)));
	ph_setaction(p, AC_DONEEATING);
	if (++(p->times_eaten)
		== p->game->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_lock(&(p->game->finished_eating_lock));
		p->game->finished_eating_count++;
		pthread_mutex_unlock(&(p->game->finished_eating_lock));
		if (p->game->finished_eating_count == p->game->number_of_philosophers)
		{
			ph_setaction(p, AC_ALL_EATEN);
			p->game->all_finished = TRUE;
		}
	}
}
