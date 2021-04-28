/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_stop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:07:54 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/28 15:02:14 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		philo_dead(t_philo *philo, int i)
{
	if (!(time_ms() - philo->tolm < (unsigned)g_all->time_to_die))
	{
		if (i & 1)
			printf_sem("died", philo);
		return (0);
	}
	return (1);
}