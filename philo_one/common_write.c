/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 14:00:42 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/17 14:56:50 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		ph_write_time(t_philosophers *p)
{
	t_time	curtime;

	gettimeofday(&curtime, NULL);
	ft_putnbr(((curtime.tv_sec - p->game->start_time.tv_sec) * 1000)
		+ ((curtime.tv_usec - p->game->start_time.tv_usec) / 1000));
	ft_putstr_fd("ms ", STDOUT_FILENO);
}

void		ph_writeaction(t_philosophers *p, int action)
{
	ph_write_time(p);
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

void		ph_setaction(t_philosophers *p, int action)
{
	pthread_mutex_lock(&(p->game->writelock));
	pthread_mutex_lock((&(p->game->someone_died_lock)));
	if ((!(p->game->someone_died) && !(p->game->all_finished)))
		ph_writeaction(p, action);
	if (action == AC_DIED)
		p->game->someone_died = 1;
	pthread_mutex_unlock(&(p->game->someone_died_lock));
	pthread_mutex_unlock(&(p->game->writelock));
}
