/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:57:32 by ehafiane          #+#    #+#             */
/*   Updated: 2024/10/06 21:20:25 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

size_t	current_var(size_t var)
{
	size_t	time;

	time = get_current_time();
	return (time - var);
}

void	init_content(t_philo *philo, int ac, char **av)
{
	philo->nb_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->num_meals = 0;
	philo->last_meal = 0;
	philo->max_nb_meals = 0;
	if (ac == 6)
		philo->max_nb_meals = ft_atoi(av[5]);
	philo->next = NULL;
}

void	fill_nodes(t_philo **philo, int ac, char **av)
{
	t_philo	*tmp;
	int		i;

	i = 1;
	while (i < ac)
	{
		tmp = ft_lstnew(ac, av);
		if (!tmp)
			return ;
		ft_lstadd_back(philo, tmp);
		tmp->id = i;
		i++;
	}
}
