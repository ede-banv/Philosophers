/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:20:17 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/27 12:00:48 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHILO_H__
# define __PHILO_H__

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/time.h>
# include <sys/wait.h>
# include "elements.h"

t_all *g_all;

int				start_philo(t_philo *philo);

int				ft_parsing(int ac, char **av);
int				ft_sems_init(void);
int				ft_init_philos(t_philo *philos);
void			ft_philo_end(t_philo **philo);

int				philo_dead(t_philo *philo, int i);

void			printf_sem(char *str, t_philo *philo);
unsigned int	time_ms(void);
void			sleep_ph(int time, t_philo *philo);

int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isdigit_str(char *str);
int				ft_atoi_ph(const char *str);

#endif