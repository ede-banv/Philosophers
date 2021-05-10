/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:49:07 by ede-banv          #+#    #+#             */
/*   Updated: 2021/05/10 13:39:31 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mutex_init(void)
{
	pthread_mutex_init(&g_all->mutex.print, NULL);
	pthread_mutex_init(&g_all->mutex.eat_stop, NULL);
}

int		ft_init_philos(t_philo *philos)
{
	int	i;

	i = 1;
	g_all->time_start = time_ms();
	while (i <= g_all->nb_philo)
	{
		philos[i - 1].n = i;
		pthread_mutex_init(&philos[i - 1].my_fork.lock, NULL);
		philos[i - 1].tolm = time_ms();
		if (i < g_all->nb_philo)
			philos[i - 1].n_fork = &philos[i].my_fork;
		i++;
	}
	philos[g_all->nb_philo - 1].n_fork = &philos[0].my_fork;
	return (1);
}

int		ft_parsing(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
		if (!ft_isdigit_str(av[i++]))
			return (0);
	i = 1;
	g_all->nb_philo = ft_atoi_ph(av[i++]);
	g_all->time_to_die = ft_atoi_ph(av[i++]);
	g_all->time_to_eat = ft_atoi_ph(av[i++]);
	g_all->time_to_sleep = ft_atoi_ph(av[i++]);
	g_all->ntepme = ac == 6 ? ft_atoi_ph(av[i]) : -1;
	return (1);
}
