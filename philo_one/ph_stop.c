/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_stop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:23:55 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/05 15:37:43 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	max_meals()
{
	pthread_mutex_lock(&g_args->eat_stop);
	g_args->eat_enough++;
	pthread_mutex_unlock(&g_args->eat_stop);
}

int		philo_dead(t_philo *philo, int time_test)
{
	unsigned int time_now;

	time_now = time_ms();
	if (time_now - philo->tolm >= (unsigned)g_args->time_to_die)
	{
		printf_lock("is dead", philo);
		return (0);
	}
	else if (time_now + time_test - philo->tolm >= (unsigned)g_args->time_to_die)
	{
		sleep_ph(time_now - philo->tolm + time_test - (unsigned)g_args->time_to_die);
		printf_lock("is dead", philo);
		return (0);
	}
	return (1);
}