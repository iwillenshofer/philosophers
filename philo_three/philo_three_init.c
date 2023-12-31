/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 21:47:52 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/20 21:10:34 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

/*
** specific initialization for philo_one
** sets all the forks left and right to the philosophers
*/

void	philo_three_init(t_game *g)
{
	t_philosophers	*p;

	p = g->philosopher;
	sem_unlink("forkslock");
	sem_unlink("fork");
	sem_unlink("writelock");
	sem_unlink("deadlock");
	sem_unlink("eatenlock");
	sem_unlink("end_game");
	g->forks = sem_open("fork", O_CREAT, 0777,
								(g->number_of_philosophers));
	g->forkslock = sem_open("forkslock", O_CREAT, 0777, 1);
	g->writelock = sem_open("writelock", O_CREAT, 0777, 1);
	g->deadlock = sem_open("deadlock", O_CREAT, 0777, 1);
	g->eatenlock = sem_open("eatenlock", O_CREAT, 0777, 1);
	g->end_game = sem_open("end_game", O_CREAT, 0777, 0);
	while (p)
	{
		sem_unlink(set_semname(&(p->sem_name), p->number, 'h'));
		p->lasteatenlock = sem_open(p->sem_name, O_CREAT, 0777, 1);
		p = p->next;
		if (p == g->philosopher)
			break ;
	}
}
