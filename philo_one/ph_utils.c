/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:09:13 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/05 14:11:17 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printf_lock(char *str, const t_philo *const philo)
{
	pthread_mutex_lock(&g_args->print);
	printf("[ ] Philo %d %s.\n", philo->n, str);
	if (!(philo->tslm < g_args->time_to_die && (g_args->ntepme != -1 && philo->nbtem < g_args->ntepme)))
		exit(0);
	pthread_mutex_unlock(&g_args->print);
}

unsigned int		time_ms(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	sleep_ph(int time)
{
	unsigned int	time_start;

	time_start = time_ms() + time;
	while (time_ms() < time_start)
		usleep(500);
}