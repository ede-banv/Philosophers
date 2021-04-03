/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:07:46 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/03 15:45:09 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	printf_lock("is sleeping", philo);
	usleep(g_args->time_to_sleep * 1000);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->my_fork.lock);
	printf_lock("has taken a fork", philo);
	pthread_mutex_lock(&philo->n_fork->lock);
	printf_lock("has taken a fork", philo);
	philo->nbtem++;
	printf_lock("is eating", philo);
	philo->tslm = 0;
	usleep(g_args->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->my_fork.lock);
	pthread_mutex_unlock(&philo->n_fork->lock);
}

void	*philo_life(void *arg)
{
	int		i;

	i = 0;
	t_philo *philo = (t_philo *)arg;
	while (philo->tslm < g_args->time_to_die && (g_args->ntepme != -1 && philo->nbtem < g_args->ntepme))
	{
		philo_eat(philo);
		philo_sleep(philo);
		printf_lock("is thinking", philo);
	}
	pthread_mutex_unlock(&g_args->dead);
	return (NULL);
}

void	ft_start_thread(t_all *all)
{
	int i;

	i = 0;
	while (i < g_args->nb_philo)
	{
		pthread_create(&all->philos[i].thread, NULL, philo_life, &all->philos[i]);
		usleep(400);
		i++;
	}
}

int		main(int ac, char **av)
{
	t_all	all;
	t_args	args;

	g_args = &args;
	ft_bzero(&all, sizeof(t_all));
	ft_bzero(g_args, sizeof(t_args));
	pthread_mutex_init(&g_args->print, NULL);
	pthread_mutex_init(&g_args->dead, NULL);
	pthread_mutex_lock(&g_args->dead);
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
	if (!ft_init_philos(&all))
	{
		printf("Error: malloc error.\n");
		return (1);
	}
	ft_start_thread(&all);
	pthread_mutex_lock(&g_args->dead);
	return (0);
}