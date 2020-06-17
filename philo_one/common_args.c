/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:08:30 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/13 16:22:51 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

/*
** returns ARGS_INVALID (-1) if an argument is invalid;
*/

int	ca_get_arguments(int argc, char **argv, t_game *game)
{
	ssize_t	args[5];
	int		i;

	i = 0;
	while (i < 4)
	{
		if (argc <= i + 1 || argc > 6
		|| (args[i] = ft_atoui(argv[i + 1])) == ARGS_INVALID)
			return (ARGS_INVALID);
		i++;
	}
	args[4] = 0;
	if (argc == 6 && (args[4] = ft_atoui(argv[5])) == ARGS_INVALID)
		return (ARGS_INVALID);
	game->number_of_philosophers = args[0];
	game->time_to_die = args[1];
	game->time_to_eat = args[2];
	game->time_to_sleep = args[3];
	game->number_of_times_each_philosopher_must_eat = args[4];
	return (0);
}
