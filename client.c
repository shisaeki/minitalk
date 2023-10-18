/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:40:29 by shinsaeki         #+#    #+#             */
/*   Updated: 2023/10/18 13:09:37 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_str(int pid, char *str)
{
	int	count;

	count = 7;
	while (*str)
	{
		if (*str >> count & 1)
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		if (count == 0)
		{
			count += 8;
			str++;
		}
		usleep(100);
		count--;
	}
}

int	main(int argc, char **argv)
{
	char	*str;

	if (argc != 3)
		return (0);
	str = argv[2];
	send_str(ft_atoi(argv[1]), argv[2]);
	return (0);
}
