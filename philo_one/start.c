/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 14:34:01 by ede-banv          #+#    #+#             */
/*   Updated: 2021/05/10 11:31:35 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		philo_sleep(t_philo *philo)
{
	if (!philo_dead(philo, 2) && g_all->dead)
		return (0);
	printf_lock("is sleeping", philo);
	sleep_ph(g_all->time_to_sleep);
	return (1);
}

int		philo_eat(t_philo *philo)
{
	if (!philo_dead(philo, 2) && g_all->dead)
		return (0);
	pthread_mutex_lock(&philo->my_fork.lock);
	printf_lock("has taken a fork", philo);
	pthread_mutex_lock(&philo->n_fork->lock);
	printf_lock("has taken a fork", philo);
	philo->nbtem++;
	printf_lock("is eating", philo);
	philo->tolm = time_ms();
	sleep_ph(g_all->time_to_eat);
	if (g_all->ntepme != -1 && philo->nbtem == g_all->ntepme)
		max_meals();
	pthread_mutex_unlock(&philo->my_fork.lock);
	pthread_mutex_unlock(&philo->n_fork->lock);
	return (1);
}

void	*philo_life(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (philo_dead(philo, 2) && !g_all->dead)
	{
		if (!philo_eat(philo))
			break;
		if (g_all->ntepme != -1 && philo->nbtem == g_all->ntepme)
			break;
		if (!philo_sleep(philo))
			break;
	}
	return (NULL);
}

void	check_dead(t_philo *philo)
{
	int i;

	while (1)
	{
		i = -1;
		while (++i < g_all->nb_philo)
		{
			if (g_all->ntepme == -1)
			{
				if (!philo_dead(&philo[i], 3))
					return ;
			}
			else if (philo->nbtem < g_all->ntepme)
				if (!philo_dead(&philo[i], 3))
					return ;
			if (g_all->ntepme != -1 && g_all->eat_enough == g_all->nb_philo)
				return ;
		}
		usleep(500);
	}
}

int		start_philo(t_philo *philo)
{
	int	i;

	i = 0;
	if (g_all->nb_philo < 2)
		return (0);
	ft_init_philos(philo);
	ft_mutex_init();
	while (i < g_all->nb_philo)
	{
		pthread_create(&philo[i].thread, NULL, philo_life, &philo[i]);
		i += 2;
	}
	usleep(400);
	i = 1;
	while (i < g_all->nb_philo)
	{
		pthread_create(&philo[i].thread, NULL, philo_life, &philo[i]);
		i += 2;
	}
	check_dead(philo);
	i = -1;
	while (++i < g_all->nb_philo)
		pthread_join(philo[i].thread, NULL);
	return (0);
}