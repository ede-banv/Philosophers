/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:49:07 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/06 16:27:19 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_init_philos(t_all *all)
{
	int	i;

	i = 1;
	if (!(all->philos = malloc(sizeof(t_philo) * g_args->nb_philo)))
		return (0);
	ft_bzero(all->philos, sizeof(t_philo) * g_args->nb_philo);
	g_args->time_start = time_ms();
	while (i <= g_args->nb_philo)
	{
		all->philos[i - 1].n = i;
		pthread_mutex_init(&all->philos[i - 1].my_fork.lock, NULL);
		if (i < g_args->nb_philo)
		{
			all->philos[i - 1].tolm = time_ms();
			all->philos[i - 1].n_fork = &all->philos[i].my_fork;
		}
		i++;
	}
	all->philos[g_args->nb_philo - 1].tolm = time_ms();
	all->philos[g_args->nb_philo - 1].n_fork = &all->philos[0].my_fork;
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
	g_args->nb_philo = ft_atoi_ph(av[i++]);
	g_args->time_to_die = ft_atoi_ph(av[i++]);
	g_args->time_to_eat = ft_atoi_ph(av[i++]);
	g_args->time_to_sleep = ft_atoi_ph(av[i++]);
	g_args->ntepme = ac == 6 ? ft_atoi_ph(av[i]) : -1;
	return (1);
}