/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:30:16 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/13 13:46:39 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_sem_init(void)
{
	if (sem_init(&g_all->sems.forks, 0, 100) == -1)
		return (0);
	if (sem_init(&g_all->sems.meals, 0, g_all->nb_philo) == -1)
		return (0);
	if (!sem_init(&g_all->sems.print, 0, 1) == -1)
		return (0);
}

int		ft_init_philos(t_philo *philos)
{
	int	i;

	i = 1;
	g_all->time_start = time_ms();
	while (i <= g_all->nb_philo)
	{
		philos[i - 1].n = i;
		philos[i - 1].tolm = time_ms();
		i++;
	}
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