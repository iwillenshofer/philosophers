/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:00:49 by iwillens          #+#    #+#             */
/*   Updated: 2020/06/14 21:45:38 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <semaphore.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>

# define ARGS_INVALID -1

# define AC_TAKENFORK 1
# define AC_EATING 2
# define AC_SLEEPING 4
# define AC_THINKING 8
# define AC_DIED 16
# define AC_DONEEATING 32
# define AC_TAKENLEFTFORK 64
# define AC_TAKENRIGHTFORK 128
# define AC_ALL_EATEN			256

# define ERR_INVALID_ARGS 1
# define ERR_ALLOCATION 2
# define ERR_NO_PHILOSOPHERS 4

# define FORK_FREE	0
# define FORK_BUSY	1
# define FORK_LEFT	2
# define FORK_RIGHT 4

# define FAIL 0
# define SUCCESS 1

# define SCHROEDINGER_ALIVE	0
# define SCHROEDINGER_DEAD	1

# define FALSE 0
# define TRUE 1

typedef struct timeval	t_time;

typedef struct s_game	t_game;

typedef struct			s_philosophers
{
	pthread_t				thread;
	pthread_t				monitor_thread;
	t_game					*game;
	unsigned int			number;
	unsigned int			times_eaten;
	t_time					last_eaten;
	char					*sem_name;
	sem_t					*lasteatenlock;
	struct s_philosophers	*next;
}						t_philosophers;

struct					s_game
{
	t_time			start_time;
	unsigned int	someone_died;
	unsigned int	all_finished;
	unsigned int	finished_eating_count;
	unsigned int	number_of_philosophers;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	number_of_times_each_philosopher_must_eat;
	pthread_t		monitor_thread;
	sem_t			*writelock;
	sem_t			*deadlock;
	sem_t			*eatenlock;
	sem_t			*forks;
	t_philosophers	*philosopher;
};

/*
** *********** common instructions *************
** **** utils:
*/

void					ft_putnbr(ssize_t n);
void					ft_putstr_fd(char *str, int fd);
ssize_t					ft_atoui(char *s);
void					ph_writeaction(t_philosophers *p, int action);
void					ph_setaction(t_philosophers *p, int action);
unsigned long int		ttime_to_ms(t_time time);
char					*set_semname(t_philosophers *p);

/*
** **** args:
*/

int						ca_get_arguments(int argc, char **argv, t_game *game);

/*
** **** err;
*/

int						err_print(int error);

/*
** **** init;
*/

int						init_philosophers(t_game *game);
int						init_game(t_game *game);

/*
** **** memfree;
*/

void					memfree_forks(t_game *g);
void					memfree_philosophers(t_game *g);
void					memfree_all(t_game *g);
void					philo_two_init(t_game *game);
void					wait_for_end(t_game *g);

/*
** **** actions
*/
void					philo_think(t_philosophers *p);
void					philo_sleep(t_philosophers *p);
void					philo_eat(t_philosophers *p);

/*
** **** monitor
*/

void					*monitor(void *philosopher);

/*
** **** end
*/

void					wait_for_end(t_game *g);

#endif
