/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:50:50 by ede-banv          #+#    #+#             */
/*   Updated: 2021/05/10 12:26:03 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		main(int ac, char **av)
{
	t_philo	*philo;
	t_all	all;

	g_all = &all;
	ft_bzero(g_all, sizeof(t_all));
	if (ac < 5 || ac > 6)
	{
		printf("Error: incorrect number of arguments.\n");
		return (1);
	}
	if (!ft_parsing(ac, av))
	{
		printf("Error: check all your arguments are positive numbers.\n");
		return (1);
	}
	if (!(philo = malloc(sizeof(t_philo) * g_all->nb_philo)))
	{
		printf("Error: malloc error.\n");
		return (1);
	}
	ft_bzero(philo, sizeof(t_philo) * g_all->nb_philo);
	start_philo(philo);
	end_philo(philo);
	return (0);
}
