/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 13:44:25 by marvin            #+#    #+#             */
/*   Updated: 2021/06/06 13:44:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	arr_to_byte(int *arr)
{
	char	byte;
	int		i;

	i = 8;
	byte = 0;
	while (--i)
		byte += arr[i] << (7 - i);
	return (byte);
}

void	byte_writer(int signal)
{
	if (signal == SIGUSR1)
		g_str.byte.arr[g_str.byte.i] = 0;
	else if (signal == SIGUSR2)
		g_str.byte.arr[g_str.byte.i] = 1;
	(g_str.byte.i)++;
	if (g_str.byte.i == 8)
	{
		g_str.byte.i = 0;
		g_str.str[g_str.i] = arr_to_byte(g_str.byte.arr);
		if (g_str.str[g_str.i] == 0)
			g_str.size = g_str.i + 1;
		(g_str.i)++;
	}
}

void	print_str(void)
{
	if (!g_str.size)
		return ;
	write(1, g_str.str, g_str.size);
	write(1, "\n", 1);
	g_str.size = 0;
	g_str.i = 0;
}

void	handler(int signal)
{
	byte_writer(signal);
	print_str();
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
	}
	return (0);
}
