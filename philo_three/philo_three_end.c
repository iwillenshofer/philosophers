/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:51:41 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/16 12:16:55 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	end_game(t_philosophers *p)
{
	while (p)
	{
		sem_post(p->game->end_game);
		p = p->next;
		if (p == p->game->philosopher)
			break ;
	}
}

void	wait_for_end(t_game *g)
{
	t_philosophers	*p;
	int				status;

	if(g->pid)
		waitpid(-1, &status, 0);
	sem_unlink("forkslock");
	sem_unlink("fork");
	sem_unlink("eatenlock");
	sem_unlink("writelock");
	sem_unlink("deadlock");
	sem_unlink("end_game");
	sem_close(g->eatenlock);
	sem_close(g->forks);
	sem_close(g->forkslock);
	sem_close(g->writelock);
	sem_close(g->deadlock);
	sem_close(g->end_game);
	p = g->philosopher;
	while (p)
	{
		sem_unlink(p->sem_name);
		sem_close(p->lasteatenlock);
		p = p->next;
		if (p == g->philosopher)
			break ;
	}
}
