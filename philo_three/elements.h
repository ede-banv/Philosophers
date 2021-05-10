/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:20:47 by ede-banv          #+#    #+#             */
/*   Updated: 2021/05/10 15:51:08 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

# include <unistd.h>
# include <semaphore.h>
# include <pthread.h>

typedef struct	s_philo
{
	int			n;
	int			nbtem;
	int			tolm;
	int			dead;
	pid_t		pid;
	pthread_t	thread;

}				t_philo;

typedef struct	s_sem
{
	sem_t	*forks;
	sem_t	*print;
}				t_sem;

typedef struct	s_all
{
	int		nb_philo;
	int		time_to_eat;
	int		time_to_sleep;
	int		time_to_die;
	int		time_start;
	int		ntepme;
	t_sem	sems;
}				t_all;

#endif
