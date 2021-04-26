/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:34:43 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/26 17:10:19 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHILO_H__
# define __PHILO_H__

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include "elements.h"

t_all *g_all;

int				start_philo(t_philo *philo);
int				ft_init_philos(t_philo *philos);
int				ft_parsing(int ac, char **av);
int				ft_sems_init(void);
void			ft_philo_end(t_philo **philo);

void			max_meals(void);
int				philo_dead(t_philo *philo, int i);

/*
** UTILS
*/
void			printf_sem(char *str, const t_philo *const philo);
unsigned int	time_ms(void);
void			sleep_ph(int time);

void			ft_bzero(void *s, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isdigit_str(char *str);
int				ft_atoi_ph(const char *str);

#endif