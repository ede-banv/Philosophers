/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:45:41 by ede-banv          #+#    #+#             */
/*   Updated: 2021/05/10 13:37:50 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_error(const char *const str)
{
	printf("Error: %s.\n", str);
	return (1);
}

int			main(int ac, char **av)
{
	t_philo	*philo;
	t_all	all;

	g_all = &all;
	ft_bzero(g_all, sizeof(t_all));
	if (ac < 5 || ac > 6)
		return (ft_error("incorrect number of arguments"));
	if (!ft_parsing(ac, av))
		return (ft_error("check all your arguments are positive numbers"));
	if (!(philo = malloc(sizeof(t_philo) * g_all->nb_philo)))
		return (ft_error("malloc error"));
	ft_bzero(philo, sizeof(t_philo) * g_all->nb_philo);
	if (!start_philo(philo))
	{
		ft_philo_end(&philo);
		return (1);
	}
	ft_philo_end(&philo);
	return (0);
}
