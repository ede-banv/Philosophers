/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:09:13 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/10 14:21:03 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			printf_lock(char *str, const t_philo *const philo)
{
	pthread_mutex_lock(&g_all->mutex.print);
	printf("[%u] Philo %d %s.\n", time_ms() - g_all->time_start, philo->n, str);
	if (g_all->last_eat || (g_all->ntepme != -1 && g_all->eat_enough == g_all->nb_philo))
		return ;
	pthread_mutex_unlock(&g_all->mutex.print);
}

unsigned int	time_ms(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void			sleep_ph(int time, t_philo *philo)
{
	unsigned int	time_start;
	time_start = time_ms() + time;
	while (time_ms() < time_start)
	{
		if (!philo_dead(philo, 2))
			usleep(400);
		usleep(400);
	}
}