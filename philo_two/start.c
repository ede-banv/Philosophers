/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:32:02 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/15 17:17:03 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_sleep(t_philo *philo)
{
	if (!philo_dead(philo, 2) && g_all->dead)
		return (0);
	printf_sem("is sleeping", philo);
	sleep_ph(g_all->time_to_sleep);
	return (1);
}

static int	philo_eat(t_philo *philo)
{
	if (!philo_dead(philo, 2) && g_all->dead)
		return (0);
	sem_wait(g_all->sems.forks);
	sem_wait(g_all->sems.forks);
	printf_sem("has taken a fork", philo);
	printf_sem("has taken a fork", philo);
	if (g_all->ntepme != -1 && philo->nbtem == g_all->ntepme - 1 && g_all->eat_enough == g_all->nb_philo - 1)
		g_all->last_eat++;
	printf_sem("is eating", philo);
	philo->tolm = time_ms();
	philo->nbtem++;
	sleep_ph(g_all->time_to_eat);
	if (g_all->ntepme != -1 && philo->nbtem == g_all->ntepme)
		max_meals();
	sem_post(g_all->sems.forks);
	sem_post(g_all->sems.forks);
	return (1);
}

static void	*philo_life(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (philo_dead(philo, 2) && !g_all->dead)
	{
		if (!philo_eat(philo))
			break;
		if (g_all->ntepme != -1 && g_all->eat_enough == g_all->nb_philo && g_all->dead)
			break;
		if (!philo_sleep(philo))
			break;
		printf_sem("is thinking", philo);
	}
	return (NULL);
}

static void	check_dead(t_philo *philo)
{
	int i;

	while (1)
	{
		i = 0;
		while (i < g_all->nb_philo)
		{
			if (!philo_dead(&philo[i], 3))
				return ;
			i++;
		}
		usleep(500);
	}
}

void	join_thread(t_philo *philo)
{
	int i;

	i = 0;
	while (i < g_all->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
		printf("lol\n");
	}
}

int		start_philo(t_philo *philo)
{
	int	i;

	i = 0;
	ft_init_philos(philo);
	if (!ft_sems_init())
	{
		printf("Error creating semaphores.\n");
		free(philo);
		return (0);
	}
	while (i < g_all->nb_philo)
	{
		pthread_create(&philo[i].thread, NULL, philo_life, &philo[i]);
		usleep(200);
		i++;
	}
	check_dead(philo);
	join_thread(philo);
	return (0);
}
