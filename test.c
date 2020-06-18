/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 16:52:23 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/18 20:36:10 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sys/time.h>
# include <unistd.h>

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
    char        str[20];
	ssize_t		signal;
	int			digits;
    int			i;
	ssize_t		number;
	i = 0;
	digits = 0;
	signal = 0;
	if (n < 0)
	{
		signal = 1;
        n = n * 1;
	}
	number = n;
	while ((number = number / 10))
		digits += 1;
    while (n >= 0)
    {
        str[digits-i] = (n % 10) + '0';
        n = n / 10;
		i++;
        if (n == 0)
            break;
    }
	str[i] = '\n';
	str[i + 1] = '\0';
	ft_putstr_fd(str, 1);
}

unsigned long int		get_time()
{
	t_time now;
	gettimeofday(&now, NULL);
	return (((now.tv_sec * 1000000 + now.tv_usec)
		- (g_starttime.tv_sec * 1000000 + g_starttime.tv_usec)) / 1000);
}

void        ft_usleep(long int us)
{
    t_time start;
    t_time cur;

    gettimeofday(&cur, NULL);
	start = cur;
    while (((cur.tv_sec - start.tv_sec) * 1000000)
        + ((cur.tv_usec - start.tv_usec)) < us)
    {
        gettimeofday(&cur, NULL);   
        usleep(1);
    }
}

int main(void)
{
	gettimeofday(&g_starttime, NULL);
	while (1)
	{
		ft_putnbr(get_time());
		ft_usleep(100 * 1000);
	}
	return (0);
}