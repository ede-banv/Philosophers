/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:49:07 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/02 16:43:17 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_init_philos(t_all *all)
{
	int		i;

	i = 1;
	if (!(all->philos = malloc(sizeof(t_philo) * all->args->nb_philo)))
		return (0);
	while (i <= all->args->nb_philo)
	{
		all->philos[i - 1].n = i;
		pthread_mutex_init(&all->philos[i - 1].my_fork.lock, NULL);
		if (i < all->args->nb_philo)
			all->philos[i - 1].n_fork = &all->philos[i].my_fork;
		i++;
	}
	all->philos[all->args->nb_philo - 1].n_fork = &all->philos[0].my_fork;
	return (1);
}

int		ft_parsing(t_all *all, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
		if (!ft_isdigit_str(av[i++]))
			return (1);//error message
	i = 1;
	all->args->nb_philo = ft_atoi_ph(av[i++]);
	all->args->time_to_die = ft_atoi_ph(av[i++]);
	all->args->time_to_eat = ft_atoi_ph(av[i++]);
	all->args->time_to_sleep = ft_atoi_ph(av[i++]);
	all->args->ntepme = ac == 6 ? ft_atoi_ph(av[i]) : -1;
}