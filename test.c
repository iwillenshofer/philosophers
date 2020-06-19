/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 16:52:23 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/19 16:56:01 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sys/time.h>
# include <unistd.h>
# include <stdint.h>

typedef struct timeval	t_time;

t_time g_starttime;


void					ft_putstr_fd(char *str, int fd)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	write(fd, str, i);
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

uint64_t		get_time()
{
	t_time		now;
	uint64_t 	t;
	uint64_t 	tg;
	gettimeofday(&now, NULL);
	t = now.tv_sec * 1000000;
	t += now.tv_usec;
	tg = g_starttime.tv_sec * 1000000;
	tg += g_starttime.tv_usec;
	return ((t - tg) / 1000);
}

uint64_t
time_diff ( struct timeval *y, struct timeval *x)
{
	uint64_t res;
  /* Perform the carry for the later subtraction by updating y. */
  if (x->tv_usec < y->tv_usec) {
    uint64_t nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
    y->tv_usec -= 1000000 * nsec;
    y->tv_sec += nsec;
  }
  if (x->tv_usec - y->tv_usec > 1000000) {
    uint64_t nsec = (x->tv_usec - y->tv_usec) / 1000000;
    y->tv_usec += 1000000 * nsec;
    y->tv_sec -= nsec;
  }
  res = (x->tv_sec - y->tv_sec) * 1000000;
  res += x->tv_usec - y->tv_usec;
  return (res / 1000);
}


uint64_t			chrono(void)
{
	uint64_t		time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * (uint64_t)1000 + (tv.tv_usec / 1000);
	return (time);
}

static void		ft_usleep(unsigned int n)
{
	uint64_t	start;

	start = chrono();
	while (1)
	{
		usleep(50);
		if (chrono() - start >= n)
			break ;
	}
}

int main(void)
{
	t_time now;

	gettimeofday(&g_starttime, NULL);
	while (1)
	{
		gettimeofday(&now, NULL);

		ft_putnbr(time_diff(&g_starttime, &now));
		ft_putstr_fd("\n", 1);
		ft_usleep(100);
	}
	return (0);
}
