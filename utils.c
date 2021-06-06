/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:48:32 by marvin            #+#    #+#             */
/*   Updated: 2021/06/06 19:48:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	itoa_isnegative(long long int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char	*ft_itoa(long long int n)
{
	long long int		tmpn;
	int					len;
	int					negative;
	char				*str;

	tmpn = n;
	len = 1;
	negative = 0;
	itoa_isnegative(&n, &negative);
	while (tmpn % 10)
	{
		tmpn /= 10;
		len++;
	}
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

int	ft_atoi(const char *str)
{
	long long int	var[3];

	var[0] = 0;
	var[1] = 1;
	var[2] = 0;
	while (str[var[2]] == 32 || (9 <= str[var[2]] && str[var[2]] <= 13))
		var[2]++;
	if ((str[var[2]] == '-' || str[var[2]] == '+') && str[var[2]++] == '-')
		var[1] = -1;
	while (str[var[2]])
	{
		if (str[var[2]] < 48 || 57 < str[var[2]])
			return (var[0] * var[1]);
		else
			var[0] = (var[0] * 10) + (long long int)(str[var[2]] - '0');
		if (var[0] < -2147483648)
			return (1);
		else if (2147483648 < var[0])
			return (0);
		var[2]++;
	}
	return ((long int)(var[0] * var[1]));
}

size_t		ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}
