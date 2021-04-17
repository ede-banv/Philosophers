/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:30:16 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/16 13:59:08 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_sem(sem_t **sem, const char *const name, const int init)
{
	sem_unlink(name);
	if ((*sem = sem_open(name, O_CREAT, 644, init)) == SEM_FAILED)
		return (0);
	return (1);
}

int			ft_sems_init(void)
{
	if (!init_sem(&g_all->sems.forks, "sem_forks", g_all->nb_philo))
		return (0);
	if (!init_sem(&g_all->sems.meals, "sem_meals", 1))
		return (0);
	if (!init_sem(&g_all->sems.print, "sem_print", 1))
		return (0);
	return (1);
}

int			ft_init_philos(t_philo *philos)
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

int			ft_parsing(int ac, char **av)
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

void		ft_philo_end(t_philo **philo)
{
	sem_close(g_all->sems.forks);
	sem_close(g_all->sems.meals);
	sem_close(g_all->sems.print);

	free(*philo);
}