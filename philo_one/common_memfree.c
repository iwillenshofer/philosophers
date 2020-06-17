/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_memfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 22:30:48 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/13 16:19:52 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	memfree_philosophers(t_game *g)
{
	t_philosophers *p;
	t_philosophers *tmp;

	p = g->philosopher;
	while (p)
	{
		tmp = p;
		p = p->next;
		free(tmp);
		if (p == g->philosopher)
			break ;
	}
	g->philosopher = NULL;
}

void	memfree_forks(t_game *g)
{
	t_forks *p;
	t_forks *tmp;

	p = g->fork;
	while (p)
	{
		tmp = p;
		p = p->next;
		free(tmp);
		if (p == g->fork)
			break ;
	}
	g->fork = NULL;
}

void	memfree_all(t_game *g)
{
	memfree_philosophers(g);
	memfree_forks(g);
}
