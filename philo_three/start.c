/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:04:26 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/26 17:30:12 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		philo_sleep(t_philo *philo)
{
	if (!philo_dead(philo, 1))
		exit (0);
	printf_sem("is sleeping", philo);
	sleep_ph(g_all->time_to_sleep, philo);
}

int		philo_eat(t_philo *philo)
{
	if (!philo_dead(philo, 1))
		exit (0);
	sem_wait(g_all->sems.forks);
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
	while (time_ms() - philo->tolm < g_all->time_to_die)
	{
		if (g_all->ntepme != -1 && philo->nbtem < g_all->ntepme)
			break;
		if (!philo_eat(philo))
			break;
		if (philo->nbtem == g_all->ntepme)
			break;
		if (!philo_sleep(philo))
			break;
		printf_sem("is thinking", philo);
	}
}

int		start_philo(t_philo *philo)
{
	int i;
	int status;

	i = 0;
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
	i = 0;
	while (i < g_all->nb_philo)
	{
		waitpid(philo[i].pid, &status, 0);
		i++;
	}
}