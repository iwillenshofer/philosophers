/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:00:41 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/17 19:58:39 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"



int		check_death_or_finish(t_game *g)
{
	int ret;

	ret = 0;
	pthread_mutex_lock(&(g->someone_died_lock));
	if (g->someone_died)
		ret = 1;
	pthread_mutex_unlock(&(g->someone_died_lock));
	pthread_mutex_lock(&(g->finished_eating_lock));
	if (g->all_finished)
		ret = 1;
	pthread_mutex_unlock(&(g->finished_eating_lock));
	return (ret);
}

void	*philo_action(void *philosopher)
{
	t_philosophers *p;

	p = (t_philosophers *)philosopher;
	gettimeofday(&(p->last_eaten), NULL);
	while (42 && !(p->game->someone_died) && !(p->game->all_finished))
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

void	play_game(t_game *g)
{
	t_philosophers	*p;
	p = g->philosopher;
	gettimeofday(&(g->start_time), NULL);
	while (p)
	{
		pthread_create(&(p->thread), NULL, &philo_action, p);
		pthread_create(&(p->monitor_thread), NULL, &monitor, p);
		pthread_detach(p->monitor_thread);
		p = p->next;
		if (p == g->philosopher)
			break ;
	}
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
		philo_one_init(&game);
		play_game(&game);
		wait_for_end(&game);
		destroy_mutex(&game);
	}
	else
		err_print(ERR_ALLOCATION);
	memfree_all(&game);
	return (0);
}
