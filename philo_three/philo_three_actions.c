/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:54:15 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/20 06:01:13 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	philo_think(t_philosophers *p)
{
	ph_setaction(p, AC_THINKING, get_elapsedtime(p->game));
}

void	philo_sleep(t_philosophers *p)
{
	ph_setaction(p, AC_SLEEPING, get_elapsedtime(p->game));
	ft_usleep(p->game->time_to_sleep);
}

void	philo_getfork(t_philosophers *p)
{
	sem_wait(p->game->forks);
	ph_setaction(p, AC_TAKENFORK, get_elapsedtime(p->game));
}

void	philo_eat(t_philosophers *p)
{
	sem_wait(p->game->forkslock);
	philo_getfork(p);
	philo_getfork(p);
	sem_post(p->game->forkslock);
	sem_wait(p->lasteatenlock);
	ph_setaction(p, AC_EATING, get_elapsedtime(p->game));
	gettimeofday(&(p->last_eaten), NULL);
	sem_post(p->lasteatenlock);
	ft_usleep(p->game->time_to_eat);
	sem_post(p->game->forks);
	sem_post(p->game->forks);
	ph_setaction(p, AC_DONEEATING, get_elapsedtime(p->game));
}
