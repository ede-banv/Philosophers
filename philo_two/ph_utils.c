/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:28:59 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/14 16:53:43 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			printf_sem(char *str, const t_philo *const philo)
{
	sem_wait(g_all->sems.print);
	printf("[%u] Philo %d %s\n", time_ms() - g_all->time_start, philo->n, str);
	if (!ft_strcmp("died", str) || g_all->last_eat || (g_all->ntepme != -1 && g_all->eat_enough == g_all->nb_philo))
		return ;
	sem_post(g_all->sems.print);
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
		usleep(400);
}