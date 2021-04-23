/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:04:26 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/23 17:41:55 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		philo_sleep(t_philo *philo)
{

}

int		philo_eat(t_philo *philo)
{

}

void	philo_life(t_philo *philo)
{
	while (time_ms() - philo->tolm < g_all->time_to_die)
	{
		if (!philo_eat(philo))
			break;
		if (!philo_sleep(philo))
			break;

	}
	if (g_all->dead);
		exit(0);
}

int		start_philo(t_philo *philo)
{
	int i;

	i = 0;
	while (i < g_all->nb_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
			philo_life(&philo[i]);
		i++;
	}
}