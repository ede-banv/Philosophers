/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:35:44 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/26 17:10:42 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ELEMENTS_H__
# define __ELEMENTS_H__

# include <pthread.h>
# include <semaphore.h>

typedef struct	s_philo
{
	int			n;
	pthread_t	thread;
	int			tolm;
	int			nbtem;
}				t_philo;

typedef struct	s_sem
{
	sem_t		*forks;
	sem_t		*print;
	sem_t		*meals;
}				t_sem;

typedef struct	s_all
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				ntepme;
	unsigned int	time_start;
	int				eat_enough;
	int				dead;
	t_sem			sems;
}				t_all;

#endif