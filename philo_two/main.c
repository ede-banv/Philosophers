/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:32:02 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/13 13:52:23 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		philo_sleep(t_philo *philo)
{
	if (!philo_dead(philo, 2))
		return (0);
	printf_sem("is sleeping", philo);
	sleep_ph(g_all->time_to_die);
	return (1);
}

int		philo_eat(t_philo *philo)
{
	if (!philo_dead(philo, 2))
		return (0);
	sem_wait(g_all->sems.forks);
	printf_sem("has taken a fork", philo);
	sem_wait(g_all->sems.fork);
	printf_sem("has taken a fork", philo);
	philo->tolm = time_ms();
	printf_sem("is eating", philo);
	sleep_ph(g_all->time_to_eat);
	philo->nbtem++;
	sem_post(g_all->sems.forks);
	sem_post(g_all->sems.forks);
	return (1);
}

void	*philo_life(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (!philo_dead(philo, 2))
	{
		if (!philo_eat(philo))
			break;
		if (!philo_sleep(philo))
			break;
		printf_sem("is thinking", philo);
	}
}

void	ft_start_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < g_all->nb_philo)
	{
		pthread_create(&philo[i].create, NULL, philo_life, &philo[i])
		i++;
	}
}

void	check_dead(t_philo *philo)
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

int		main(int ac, char **av)
{
	t_philo	*philo;
	t_all	all;

	g_all = &all;
	ft_bzero(g_all, sizeof(t_all));
	if (ac < 5 || ac > 6)
	{
		printf("Error: incorrect number of arguments.\n");
		return (1);
	}
	if (!ft_parsing(ac, av))
	{
		printf("Error: please check all your arguments are positive numbers.\n");
		return (1);
	}
	if (!(philo = malloc(sizeof(t_philo) * g_all->nb_philo)))
	{
		printf("Error: malloc error.\n");
		return (1);
	}
	ft_bzero(philo, sizeof(t_philo) * g_all->nb_philo);
	ft_init_philos(philo);
	if (!ft_sem_init())
	{
		printf("Error creating semaphores.\n")
		free(philo);
		return (1);
	}
	ft_start_thread(philo);
	check_dead(philo);
}