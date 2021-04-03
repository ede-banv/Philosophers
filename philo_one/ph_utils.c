/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:09:13 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/03 15:46:42 by ede-banv         ###   ########.fr       */
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