/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:03:23 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/15 11:00:35 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	err_print(int error)
{
	if (error == ERR_INVALID_ARGS)
		ft_putstr_fd("Invalid Arguments\n", STDERR_FILENO);
	if (error == ERR_NO_PHILOSOPHERS)
		ft_putstr_fd("You need at least one philosopher\n", STDERR_FILENO);
	return (error);
}
