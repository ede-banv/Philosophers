/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:04:26 by ede-banv          #+#    #+#             */
/*   Updated: 2021/05/10 15:54:38 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	if (!philo_dead(philo, 1))
		exit(0);
	printf_sem("is sleeping", philo);
	sleep_ph(g_all->time_to_sleep, philo);
}

void	philo_eat(t_philo *philo)
{
	if (!philo_dead(philo, 1))
		exit(0);
	sem_wait(g_all->sems.forks);
	if (!philo_dead(philo, 1))
		exit(0);
	printf_sem("has taken a fork", philo);
	sem_wait(g_all->sems.forks);
	printf_sem("has taken a fork", philo);
	philo->tolm = time_ms();
	printf_sem("is eating", philo);
	sleep_ph(g_all->time_to_eat, philo);
	philo->nbtem++;
	sem_post(g_all->sems.forks);
	sem_post(g_all->sems.forks);
}

void	philo_life(t_philo *philo)
{
	pthread_create(&philo->thread, NULL, check_dead, philo);
	while (philo_dead(philo, 1) && !philo->dead)
	{
		if (g_all->ntepme != -1 && philo->nbtem == g_all->ntepme)
			break ;
		philo_eat(philo);
		if (philo->nbtem == g_all->ntepme)
			break ;
		philo_sleep(philo);
		printf_sem("is thinking", philo);
	}
	pthread_join(philo->thread, NULL);
	exit(0);
}

int		check_status(t_philo *philo)
{
	int i;
	int status;

	i = 0;
	while (i < g_all->nb_philo)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 1)
		{
			i = 0;
			while (i < g_all->nb_philo)
				kill(philo[i++].pid, SIGKILL);
			break ;
		}
		else
			i++;
	}
	return (1);
}

int		start_philo(t_philo *philo)
{
	int i;

	i = 0;
	if (g_all->nb_philo < 2)
		return (0);
	ft_init_philos(philo);
	if (!ft_sems_init())
	{
		printf("Error creating semaphores.\n");
		free(philo);
		return (0);
	}
	while (i < g_all->nb_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
			philo_life(&philo[i]);
		usleep(g_all->time_to_eat * (i % 2) / 2);
		i++;
	}
	check_status(philo);
	return (1);
}
