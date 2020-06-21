/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 21:33:34 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/20 21:03:22 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	ft_bzero(void* s, int size)
{
	int i;
	char *str;

	str = (char*)s;
	i = 0;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
}

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

int		init_game(t_game *game)
{
	game->philosopher = NULL;
	game->someone_died = SCHROEDINGER_ALIVE;
	game->finished_eating_count = 0;
	game->all_finished = FALSE;
	if (!(init_philosophers(game)))
	{
		memfree_philosophers(game);
		return (FAIL);
	}
	return (SUCCESS);
}
