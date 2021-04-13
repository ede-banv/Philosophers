/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_Stop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:47:23 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/13 13:47:38 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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