/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 23:55:55 by shinsaeki         #+#    #+#             */
/*   Updated: 2023/10/14 13:20:09 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	skip_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

long	get_long(const char *str, int sign)
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

long int	ft_abs(long int nbr)
{
	if (nbr < 0)
		return (-1 * nbr);
	else
		return (nbr);
}

int	ft_len(long int nbr)
{
	int	len;

	if (nbr <= 0)
		len = 1;
	else
		len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*c;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_len(n);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (0);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}