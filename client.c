/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:33:35 by marvin            #+#    #+#             */
/*   Updated: 2021/06/06 17:33:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	byte_to_arr(char c, int *arr)
{
	int		i;

	i = -1;
	while (++i < 8)
	{
		arr[7 - i] = (int)(c % 2);
		c = c >> 1;
	}
}

void	send_signals(char *str, int pid)
{
	int		arr[8];
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		byte_to_arr(str[i], arr);
		j = -1;
		while (++j < 8)
		{
			if (arr[j])
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(300);
		}
		i++;
	}
	j = -1;
	while (++j < 8)
	{
		kill(pid, SIGUSR1);
		usleep(600);
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
		return (-1);
	pid = ft_atoi(argv[1]);
	send_signals(argv[2], pid);
	return (0);
}
