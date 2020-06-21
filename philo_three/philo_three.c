/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:00:41 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/21 14:44:09 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		check_death_or_finish(t_game *g)
{
	int ret;

	ret = 0;
	sem_wait(g->deadlock);
	if ((g->someone_died))
		ret = 1;
	sem_post(g->deadlock);
	sem_wait(g->eatenlock);
	if ((g->all_finished))
		ret = 1;
	sem_post(g->eatenlock);
	return (ret);
}

void	*wait_end(void *philosopher)
{
	t_philosophers	*p;
	t_game			*g;

	p = (t_philosophers*)philosopher;
	g = p->game;
	sem_wait(g->deadlock);
	g->someone_died = 1;
	sem_post(g->deadlock);
	sem_wait(g->eatenlock);
	g->all_finished = 1;
	sem_post(g->eatenlock);
	return (0);
}

int		philo_action(t_philosophers *p)
{	
	gettimeofday(&(p->last_eaten), NULL);
	pthread_create(&(p->monitor_thread), NULL, &monitor, p);
	pthread_detach(p->monitor_thread);
	while (42 && !((p->game->someone_died)) && !((p->game->all_finished)))
	{
		if (check_death_or_finish(p->game))
			break ;
		philo_eat(p);
		if (check_death_or_finish(p->game))
			break ;
		philo_sleep(p);
		if (check_death_or_finish(p->game))
			break ;
		philo_think(p);
	}
	return (0);
}

int		play_game(t_game *g)
{
	t_philosophers	*p;

	p = g->philosopher;
	gettimeofday(&(p->game->start_time), NULL);
	p->game->start_time_ms = ttime_to_ms(p->game->start_time);
	ph_setaction(p, AC_TAKENFORK, get_elapsedtime(p->game));
	while (p)
	{
		p->pid = fork();
		if (p->pid == 0)
			return (philo_action(p));
		else
			(p->game->pid = p->pid);
		p = p->next;
		if (p == g->philosopher)
			break ;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_game game;

	ft_bzero(&game, sizeof(t_game));
	if (ca_get_arguments(argc, argv, &game) == ARGS_INVALID)
		return (err_print(ERR_INVALID_ARGS));
	else if (game.number_of_philosophers == 0)
		return (err_print(ERR_NO_PHILOSOPHERS));
	if ((init_game(&game)))
	{
		philo_three_init(&game);
		play_game(&game);
		if (game.pid)
			wait_for_end(&game);
	}
	else
		err_print(ERR_ALLOCATION);
	memfree_all(&game);
	return (0);
}
