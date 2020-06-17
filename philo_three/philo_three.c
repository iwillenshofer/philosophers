/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:00:41 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/16 12:17:36 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		check_death_or_finish(t_game *g)
{
	int ret;

	ret = 0;
	if ((g->someone_died))
		ret = 1;
	if ((g->all_finished))
		ret = 1;
	return (ret);
}

void	*wait_end(void *philosopher)
{
	t_philosophers *p;

	p = (t_philosophers*)philosopher;
	sem_wait(p->game->end_game);
	exit(0);
}

int		philo_action(t_philosophers *p)
{
	sem_wait(p->game->sync);
	gettimeofday(&(p->game->start_time), NULL);
	gettimeofday(&(p->last_eaten), NULL);
	pthread_create(&(p->end_thread), NULL, &wait_end, p);
	pthread_detach(p->end_thread);
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
	while (p)
	{
		p->pid = fork();
		if (p->pid == 0)
			return (philo_action(p));
		p = p->next;
		if (p == g->philosopher)
			break ;
	}
	while (p)
	{
		sem_post(p->game->sync);
		usleep(10);
		p = p->next;
		if (p == g->philosopher)
			break ;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_game game;

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
