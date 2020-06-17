/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 21:47:52 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/15 10:45:59 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

/*
** specific initialization for philo_one
** sets all the forks left and right to the philosophers
*/

void	philo_two_init(t_game *g)
{
	t_philosophers	*p;

	p = g->philosopher;
	sem_unlink("fork");
	sem_unlink("writelock");
	sem_unlink("deadlock");
	sem_unlink("eatenlock");
	g->forks = sem_open("fork", O_CREAT, 0777, (g->number_of_philosophers));
	g->writelock = sem_open("writelock", O_CREAT, 0777, 1);
	g->deadlock = sem_open("deadlock", O_CREAT, 0777, 1);
	g->eatenlock = sem_open("eatenlock", O_CREAT, 0777, 1);
	while (p)
	{
		sem_unlink(set_semname(p));
		p->lasteatenlock = sem_open(p->sem_name, O_CREAT, 0777, 1);
		p = p->next;
		if (p == g->philosopher)
			break ;
	}
}
