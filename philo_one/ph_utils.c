/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:09:13 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/05 16:07:47 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			printf_lock(char *str, const t_philo *const philo)
{
	pthread_mutex_lock(&g_args->print);
	printf("[%u] Philo %d %s.\n", time_ms() - g_args->time_start, philo->n, str);
	if (time_ms() - philo->tolm >= (unsigned)g_args->time_to_die && (g_args->ntepme != -1 && g_args->eat_enough == g_args->nb_philo))
		return ;
	pthread_mutex_unlock(&g_args->print);
}

unsigned int	time_ms(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void			sleep_ph(int time)
{
	unsigned int	time_start;

	time_start = time_ms() + time;
	while (time_ms() < time_start)
		usleep(500);
}