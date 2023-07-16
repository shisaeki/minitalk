/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:02:59 by shisaeki          #+#    #+#             */
/*   Updated: 2023/07/16 12:32:58 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

static void	send_str(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		str++;
	}
	i = 8;
	while (i)
	{
		kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	target_pid;
	
	if (argc != 3)
		return (0);

	target_pid = atoi(argv[1]);
	send_str(target_pid, argv[2]);

	return (0);
}
