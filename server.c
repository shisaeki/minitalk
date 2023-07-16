/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:02:46 by shisaeki          #+#    #+#             */
/*   Updated: 2023/07/16 17:55:06 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	signal_handler(int signum)
{
	static int				count;
	static unsigned char	c;

	count = 0;
	c = 0;
	c |= (signum == SIGUSR1);
	if (++count == 8)
	{
		count = 0;
		ft_putchar_fd(c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main()
{
	pid_t				pid;
	struct sigaction	sa;
	char				buffer[255];

	pid = getpid();
	sprintf(buffer, "Process ID: %d\n", (int) pid);
	write(STDOUT_FILENO, buffer, ft_strlen(buffer));
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
