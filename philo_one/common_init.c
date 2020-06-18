/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 21:33:34 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/13 20:50:35 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

/*
** return 0 if allocation fails
*/

int		init_philosophers(t_game *game)
{
	unsigned int	i;
	t_philosophers	*new;
	t_philosophers	*prev;

	i = 0;
	while (i < game->number_of_philosophers)
	{
		if (!(new = (t_philosophers *)malloc(sizeof(t_philosophers))))
			return (FAIL);
		ft_bzero(new, sizeof(t_philosophers));
		new->times_eaten = 0;
		new->number = i + 1;
		new->game = game;
		new->next = NULL;
		if (i == 0)
			game->philosopher = new;
		else
			prev->next = new;
		prev = new;
		i++;
	}
	prev->next = game->philosopher;
	return (SUCCESS);
}

int		init_forks(t_game *game)
{
	unsigned int	i;
	t_forks			*new;
	t_forks			*prev;

	i = 0;
	while (i < game->number_of_philosophers)
	{
		if (!(new = (t_forks *)malloc(sizeof(t_forks))))
			return (FAIL);
		ft_bzero(new, sizeof(t_forks));
		new->next = NULL;
		if (i == 0)
			game->fork = new;
		else
			prev->next = new;
		prev = new;
		i++;
	}
	prev->next = game->fork;
	return (SUCCESS);
}

int		init_game(t_game *game)
{
	game->philosopher = NULL;
	game->fork = NULL;
	game->someone_died = SCHROEDINGER_ALIVE;
	game->finished_eating_count = 0;
	game->all_finished = FALSE;
	gettimeofday(&game->start_time, NULL);
	if (!(init_philosophers(game)) || !(init_forks(game)))
	{
		memfree_forks(game);
		memfree_philosophers(game);
		return (FAIL);
	}
	return (SUCCESS);
}
