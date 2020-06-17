/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:00:35 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/14 21:43:23 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

/*
** convertes a numeric string into an unsigned integer, up to UINT_MAX
** returns ARGS_INVALID (-1) if an error occours
*/

char					*set_semname(t_philosophers *p)
{
	int				digits;
	unsigned int	number;
	char			*s;
	int				i;

	i = 0;
	digits = 1;
	number = p->number;
	while ((number = number / 10))
		digits++;
	s = malloc(3 + digits);
	s[0] = 'p';
	s[1] = 'h';
	number = p->number;
	while (number >= 0)
	{
		s[(digits + 2) - i - 1] = (number % 10) + '0';
		number = number / 10;
		i++;
		if (number == 0)
			break ;
	}
	s[digits + 2] = '\0';
	p->sem_name = s;
	return (s);
}

ssize_t					ft_atoui(char *s)
{
	int		i;
	ssize_t	n;
	int		nb_size;

	i = 0;
	n = 0;
	nb_size = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = (n * 10) + (s[i] - '0');
		i++;
		nb_size++;
	}
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] || n > (ssize_t)UINT_MAX || nb_size > 10)
		return (ARGS_INVALID);
	return (n);
}

void					ft_putnbr(ssize_t n)
{
	char		c;
	ssize_t		signal;

	signal = 1;
	if (n < 0)
	{
		signal = -1;
		write(1, "-", 1);
	}
	if (n / 10)
		ft_putnbr((n / 10) * signal);
	c = ((unsigned int)(n * signal) % 10) + '0';
	write(1, &c, 1);
}

void					ft_putstr_fd(char *str, int fd)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

unsigned long int		ttime_to_ms(t_time time)
{
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
