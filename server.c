/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:02:46 by shisaeki          #+#    #+#             */
/*   Updated: 2023/07/02 18:46:27 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

int	main()
{
	pid_t	pid;
	struct	sigaction sa;
	char	buffer[255];

	pid = getpid();
	sprintf(buffer, "Process ID: %d\n", (int) pid);
	write(STDOUT_FILENO, buffer, strlen(buffer));

	sigemptyset(&sa.sa_mask);
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while(1)
		pause();

	return (0);
}
