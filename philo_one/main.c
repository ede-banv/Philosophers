/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:50:50 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/07 16:45:56 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		philo_sleep(t_philo *philo)
{
	//if (!philo_dead(philo, 0))
	//	return (0);
	printf_lock("is sleeping", philo);
	sleep_ph(g_all->time_to_sleep, philo);
	return (1);
}

int		philo_eat(t_philo *philo)
{
	//if (!philo_dead(philo, 0))
	//	return (0);
	pthread_mutex_lock(&philo->my_fork.lock);
	pthread_mutex_lock(&philo->n_fork->lock);
	printf_lock("has taken a fork", philo);
	printf_lock("has taken a fork", philo);
	printf_lock("is eating", philo);
	philo->tolm = time_ms();
	philo->nbtem++;
	sleep_ph(g_all->time_to_eat, philo);
	if (g_all->ntepme != -1 && g_all->eat_enough == g_all->nb_philo)
		max_meals();
	pthread_mutex_unlock(&philo->my_fork.lock);
	pthread_mutex_unlock(&philo->n_fork->lock);
	return (1);
}

void	*philo_life(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (philo_dead(philo, 2))
	{
		if (!philo_eat(philo))
			break;
		if (g_all->ntepme != -1 && g_all->eat_enough == g_all->nb_philo)
			break;
		if (!philo_sleep(philo))
			break;
		printf_lock("is thinking", philo);
	}
	return (NULL);
}

void	ft_start_thread(t_philo *philos)
{
	int i;

	i = 0;
	while (i < g_all->nb_philo)
	{
		pthread_create(&philos[i].thread, NULL, philo_life, &philos[i]);
		i += 2;
	}
	usleep(800);
	i = 1;
	while (i < g_all->nb_philo)
	{
		pthread_create(&philos[i].thread, NULL, philo_life, &philos[i]);
		i += 2;
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
			{
				//printf_lock("is dead", philo);
				return ;
			}
			i++;
		}
		usleep(200);
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
	ft_mutex_init();
	ft_start_thread(philo);
	check_dead(philo);
	return (0);
}