/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_stop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:23:55 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/30 17:06:22 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	max_meals()
{
	pthread_mutex_lock(&g_all->mutex.eat_stop);
	g_all->eat_enough++;
	pthread_mutex_unlock(&g_all->mutex.eat_stop);
}

/*
 * i & 1 => option 1 (i == 1)
 * i & 2 => option 2 (i == 2)
 * i & 1 && i & 2 => option 1 && option 2 (i == 3)
 */

int		philo_dead(t_philo *philo, int i)
{
	if (!(time_ms() - philo->tolm < (unsigned)g_all->time_to_die))
	{
		if (i & 1)
			printf_lock("died", philo);
		return (0);
	}
	if ((i & 2) && (g_all->ntepme != -1 && g_all->eat_enough >= g_all->nb_philo))
		return (0);
	return (1);
}

void	end_philo(t_philo *philo)
{
	int i;

	i = 0;
	pthread_mutex_destroy(&g_all->mutex.print);
	pthread_mutex_destroy(&g_all->mutex.eat_stop);
	while (i < g_all->nb_philo)
		pthread_mutex_destroy(&philo[i++].my_fork.lock);
	free(philo);
}
