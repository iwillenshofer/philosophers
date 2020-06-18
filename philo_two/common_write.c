/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 14:00:42 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/17 19:23:30 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		ph_writeaction(t_philosophers *p, int action, long ms)
{
	ft_putnbr(ms);
	ft_putstr_fd("ms ", STDOUT_FILENO);
	if (action != AC_ALL_EATEN)
		ft_putnbr((ssize_t)p->number);
	if (action == AC_TAKENFORK)
		ft_putstr_fd(" has taken a fork\n", STDOUT_FILENO);
	else if (action == AC_EATING)
		ft_putstr_fd(" is eating\n", STDOUT_FILENO);
	else if (action == AC_DONEEATING)
		ft_putstr_fd(" is done eating\n", STDOUT_FILENO);
	else if (action == AC_SLEEPING)
		ft_putstr_fd(" is sleeping\n", STDOUT_FILENO);
	else if (action == AC_THINKING)
		ft_putstr_fd(" is thinking\n", STDOUT_FILENO);
	else if (action == AC_DIED)
		ft_putstr_fd("\033[93m died\033[0m\n", STDOUT_FILENO);
	else if (action == AC_TAKENLEFTFORK)
		ft_putstr_fd(" has taken a left fork\n", STDOUT_FILENO);
	else if (action == AC_TAKENRIGHTFORK)
		ft_putstr_fd(" has taken a right fork\n", STDOUT_FILENO);
	else if (action == AC_ALL_EATEN)
		ft_putstr_fd("\033[92mAll philosophers have eaten\033[0m\n",
			STDOUT_FILENO);
}

void		ph_setaction(t_philosophers *p, int action, long ms)
{
	sem_wait(p->game->writelock);
	sem_wait(p->game->deadlock);
	if ((!(p->game->someone_died) && !(p->game->all_finished)))
		ph_writeaction(p, action, ms);
	if (action == AC_DIED)
		p->game->someone_died = TRUE;
	if (action == AC_DONEEATING && !(p->game->someone_died)
									&& !(p->game->all_finished))
	{
		if (++(p->times_eaten)
		>= p->game->number_of_times_each_philosopher_must_eat
		&& p->game->number_of_times_each_philosopher_must_eat)
		{
			p->game->finished_eating_count++;
			if (p->game->finished_eating_count
							== p->game->number_of_philosophers)
			{
				ph_writeaction(p, AC_ALL_EATEN, ms);
				p->game->all_finished = TRUE;
			}
		}
	}
	sem_post(p->game->writelock);
	sem_post(p->game->deadlock);
}
