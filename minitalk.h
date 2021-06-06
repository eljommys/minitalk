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
# include "libft/libft.h"

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

t_string	g_str = {{0}, {{0}, 0}, 0, 0};

#endif
