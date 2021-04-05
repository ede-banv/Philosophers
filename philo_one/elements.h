/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:16:53 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/05 15:25:21 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ELEMENTS_H__
# define __ELEMENTS_H__

# include <pthread.h>

typedef struct	s_fork
{
	pthread_mutex_t	lock;
}				t_fork;

typedef struct	s_philo
{
	int			n;
	pthread_t	thread;
	t_fork		my_fork;
	t_fork		*n_fork;
	int			tolm; //time since last meal
	int			nbtem; //number of times they have eaten a meal
}				t_philo;

typedef struct	s_time
{
	int	time_start;

}				t_time;


typedef struct	s_args
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				ntepme; //nb of times each philosopher must eat
	unsigned int	time_start;
	int				eat_enough;
	pthread_mutex_t	print;
	pthread_mutex_t eat_stop;
	pthread_mutex_t	dead;
}				t_args;

typedef struct	s_all
{
	t_philo			*philos;
}				t_all;


#endif