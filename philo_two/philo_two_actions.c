/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:54:15 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/15 10:48:28 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	philo_think(t_philosophers *p)
{
	ph_setaction(p, AC_THINKING);
}

void	philo_sleep(t_philosophers *p)
{
	ph_setaction(p, AC_SLEEPING);
	usleep(p->game->time_to_sleep * 1000);
}

void	philo_getfork(t_philosophers *p)
{
	sem_wait(p->game->forks);
	ph_setaction(p, AC_TAKENFORK);
}

void	philo_eat(t_philosophers *p)
{
	philo_getfork(p);
	philo_getfork(p);
	sem_wait(p->lasteatenlock);
	gettimeofday(&(p->last_eaten), NULL);
	sem_post(p->lasteatenlock);
	ph_setaction(p, AC_EATING);
	usleep(p->game->time_to_eat * 1000);
	sem_post(p->game->forks);
	sem_post(p->game->forks);
	ph_setaction(p, AC_DONEEATING);
}
