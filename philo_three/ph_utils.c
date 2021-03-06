/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:55:49 by ede-banv          #+#    #+#             */
/*   Updated: 2021/05/10 13:40:24 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			printf_sem(char *str, t_philo *philo)
{
	sem_wait(g_all->sems.print);
	printf("[%d] Philo %d %s\n", time_ms() - g_all->time_start, philo->n, str);
	if (!ft_strcmp("died", str))
		exit(1);
	sem_post(g_all->sems.print);
}

unsigned int	time_ms(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void			sleep_ph(int time, t_philo *philo)
{
	unsigned int	time_start;

	time_start = time_ms() + time;
	while (time_ms() < time_start)
	{
		if (!philo_dead(philo, 1))
			exit(0);
		usleep(400);
	}
}
