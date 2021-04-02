/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:07:46 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/02 17:05:52 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	printf("[ ]Philo %d is sleeping\n", philo->n);
	usleep(all->args->time_to_sleep * 1000);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->my_fork.lock);
	printf("[ ]Philo %d has taken a fork\n", philo->n);
	pthread_mutex_lock(&philo->n_fork->lock);
	printf("[ ]Philo %d has taken a fork\n", philo->n);
	printf("[ ]Philo %d is eating\n", philo->n);
	usleep(all->args->time_to_eat * 1000);
}

void	*philo_life(void *arg)
{
	t_philo *philo = (t_philo *)arg;

}

void	ft_start_thread(t_all *all)
{
	int i;

	i = 0;
	while (i < all->args->nb_philo)
	{
		pthread_create(all->philos[i].thread, NULL, philo_life, &all->philos[i]);
	}
}

int		main(int ac, char **av)
{
	t_all	all;

	ft_bzero(&all, sizeof(t_all));
	if (ac < 5 || ac > 6)
	{
		return (1);//error msg not enough or too many arguments
	}
	if (!ft_parsing(&all, ac, av))
		;//erreur d'arguments
	if (!ft_init_philos(&all))
		;//erreur de malloc
	ft_start_thread(&all);
	//comment est-ce que je fais mon main attendre pr srtir qu'un philo soit mort (join?)
	return (0);
}