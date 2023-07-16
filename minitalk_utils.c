/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:42:29 by shisaeki          #+#    #+#             */
/*   Updated: 2023/07/16 17:12:58 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	skip_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static long	get_long(const char *str, int sign)
{
	long	nbr;
	size_t	i;

	nbr = 0;
	i = 0;
	while ('0' <= str[i] && str[i] <= '9' && str[i] != '\0')
	{
		if (sign == 1)
		{
			if ((nbr == LONG_MAX / 10 && str[i] > LONG_MAX % 10 + '0')
				|| (nbr > LONG_MAX / 10))
				return (LONG_MAX);
		}
		else
		{
			if ((-1 * nbr == LONG_MIN / 10 && -1
					* (str[i] - '0') < (LONG_MIN % 10))
				|| (-1 * nbr < LONG_MIN / 10))
				return (LONG_MIN);
		}
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	return (sign * nbr);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	i;

	sign = 1;
	i = 0;
	while (str[i] != '\0' && skip_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (get_long(&str[i], sign));
}
