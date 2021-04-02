/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:07:46 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/02 15:31:15 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		main(int ac, char **av)
{
	t_all	all;

	ft_bzero(all, sizeof(t_all));
	if (ac < 5 || ac > 6)
	{
		return (1);//error msg not enough or too many arguments
	}
	ft_parsing(&all, ac, av);
	ft_init_philos(&all);
	ft_start_thread(&all);
	return (0);
}