/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:29:19 by ede-banv          #+#    #+#             */
/*   Updated: 2021/04/03 15:36:00 by ede-banv         ###   ########.fr       */
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

t_args	*g_args;

int		ft_init_philos(t_all *all);
int		ft_parsing(int ac, char **av);
void	ft_start_thread(t_all *all);

/*
** UTILS
*/
void	printf_lock(char *str, const t_philo *const philo);

void	ft_bzero(void *s, size_t n);
int		ft_isdigit_str(char *str);
int		ft_atoi_ph(const char *str);

#endif