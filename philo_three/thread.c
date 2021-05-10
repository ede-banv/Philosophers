/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:51:23 by ede-banv          #+#    #+#             */
/*   Updated: 2021/05/10 16:13:39 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_dead(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo_dead(philo, 1) == 0)
		{
			philo->dead++;
			return (NULL);
		}
		else if (philo->nbtem == g_all->ntepme)
		{
			return (NULL);
		}
		usleep(500);
	}
}
