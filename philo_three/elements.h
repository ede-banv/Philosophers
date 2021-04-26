/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:20:47 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/26 17:26:07 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ELEMENTS_H__
# define __ELEMENTS_H__

# include <unistd.h>
# include <semaphore.h>

typedef struct	s_philo
{
	int		n;
	int		nbtem;
	int		tolm;
	pid_t	pid;
}				t_philo;

typedef struct	s_sem
{
	sem_t	forks;
	sem_t	print;
}				t_sem;

typedef struct	s_all
{
	int		nb_philo;
	int		time_to_eat;
	int		time_to_sleep;
	int		time_to_die;
	int		time_start;
	int		ntepme;
	int		dead;
	t_sem	sems;
}				t_all;


#endif