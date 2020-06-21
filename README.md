<p align="center">
	<img width="130px;" src="https://raw.githubusercontent.com/iwillenshofer/resources/main/images/42_logo_black.svg" align="center" alt="42" />&nbsp;&nbsp;&nbsp;
	<img width="130px" src="https://raw.githubusercontent.com/iwillenshofer/resources/main/achievements/philosophers.png" align="center" alt="philosophers" />
	<h1 align="center">philosophers</h1>
</p>
<p align="center">
	<img src="https://img.shields.io/badge/Success-100/100_✓-gray.svg?colorA=61c265&colorB=4CAF50&style=for-the-badge">
	<img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black">
	<img src="https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=apple&logoColor=white">
</p>

<p align="center">
	<b><i>Development repository for the 42cursus Philosophers project @ 42 São Paulo</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/iwillenshofer/philosophers?color=blueviolet" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/iwillenshofer/philosophers?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/commit-activity/t/iwillenshofer/philosophers?color=brightgreen" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/iwillenshofer/philosophers?color=brightgreen" />
</p>
<br>

> _Eat, Sleep, Spaghetti, repeat. This project is about learning how threads work by precisely timing a group of philosophers on when to pick up forks and eat spaghetti without dying from hunger._



<br>

<p align="center">
	<table>
		<tr>
			<td><b>Est. Time</b></td>
			<td><b>Skills</b></td>
			<td><b>Allowed Functions</b></td>
			<td><b>Difficulty</b></td>
		</tr>
		<tr>
			<td valign="top">70 hours</td>
			<td valign="top">
<img src="https://img.shields.io/badge/Imperative programming-555"><br>
<img src="https://img.shields.io/badge/Unix-555"><br>
<img src="https://img.shields.io/badge/Rigor-555">
			</td>
			<td valign="top">
				<img src="https://img.shields.io/badge/common-blue"><br>
				<img src="https://img.shields.io/badge/memset()-lightgrey">
				<img src="https://img.shields.io/badge/malloc()-lightgrey">
				<img src="https://img.shields.io/badge/free()-lightgrey">
				<img src="https://img.shields.io/badge/write()-lightgrey"><br>
				<img src="https://img.shields.io/badge/pthread_create()-lightgrey">
				<img src="https://img.shields.io/badge/pthread_detach()-lightgrey">
				<img src="https://img.shields.io/badge/pthread_join()-lightgrey"><br>
				<img src="https://img.shields.io/badge/usleep()-lightgrey">
				<img src="https://img.shields.io/badge/gettimeofday()-lightgrey"><br><br>
				<img src="https://img.shields.io/badge/philo_one-blue"><br>
				<img src="https://img.shields.io/badge/pthread_mutex_init-lightgrey">
				<img src="https://img.shields.io/badge/pthread_mutex_destroy-lightgrey"><br>
				<img src="https://img.shields.io/badge/pthread_mutex_lock-lightgrey">
				<img src="https://img.shields.io/badge/pthread_mutex_unlock-lightgrey"><br><br>
				<img src="https://img.shields.io/badge/philo_two-blue"><br>
				<img src="https://img.shields.io/badge/sem_open-lightgrey">
				<img src="https://img.shields.io/badge/sem_clos-lightgrey">
				<img src="https://img.shields.io/badge/sem_post-lightgrey"><br>
				<img src="https://img.shields.io/badge/sem_wait-lightgrey">
				<img src="https://img.shields.io/badge/sem_unlink-lightgrey"><br><br>
				<img src="https://img.shields.io/badge/philo_three-blue"><br>
				<img src="https://img.shields.io/badge/fork-lightgrey">
				<img src="https://img.shields.io/badge/kill-lightgrey">
				<img src="https://img.shields.io/badge/exit-lightgrey">
				<img src="https://img.shields.io/badge/waitpid-lightgrey">
				<img src="https://img.shields.io/badge/sem_open-lightgrey"><br>
				<img src="https://img.shields.io/badge/sem_clos-lightgrey">
				<img src="https://img.shields.io/badge/sem_post-lightgrey">
				<img src="https://img.shields.io/badge/sem_wait-lightgrey">
				<img src="https://img.shields.io/badge/sem_unlink-lightgrey">
			</td>
			<td valign="top"> 3360 XP</td>
		</tr>
	</table>
</p>

<br>

### Usage
```bash
$ cd philo_[one, two, three]
$ make
$ ./philo_[one, two, three] number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

#### Argument definitions:
` number_of_philosophers ` is the number of philosophers and also the number of forks

` time_to_die ` is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after starting his last meal or the beginning of the simulation, it dies

` time_to_eat ` is in milliseconds and is the time it takes for a philosopher to eat. During that time he will need to keep the two forks.

` time_to_sleep ` is in milliseconds and is the time the philosopher will spend sleeping.

` number_of_times_each_philosopher_must_eat ` argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.


#### philo[one, two, three] programs:
` philo_one ` philosopher with threads and mutex

` philo_two ` philosopher with threads and semaphore

` philo_three ` philosopher with processes and semaphore
