/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 13:45:32 by marvin            #+#    #+#             */
/*   Updated: 2021/06/06 13:45:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>

# ifndef BUFFERSIZE
#  define BUFFERSIZE 1024
# endif

typedef struct s_byte
{
	int		arr[8];
	int		i;
}				t_byte;

typedef struct s_string
{
	char	str[BUFFERSIZE];
	t_byte	byte;
	int		i;
	int		size;
}				t_string;

char	*ft_itoa(long long int n);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

#endif
