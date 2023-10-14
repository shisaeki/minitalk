/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:40:29 by shinsaeki         #+#    #+#             */
/*   Updated: 2023/10/14 13:36:49 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char** argv)
{
    if (argc != 3)
        return (0);
    
    char *str = argv[2];
    int i = 7;
    while (*str)
    {
        if (*str >> i & 1)
        {
            kill (ft_atoi(argv[1]), SIGUSR1);
            write(STDOUT_FILENO, "1", 1);
        }
        else
        {
            kill (ft_atoi(argv[1]), SIGUSR2);
            write(STDOUT_FILENO, "0", 1);
        }    
        if (i == 0)
        {
            write(STDOUT_FILENO, "\n", 1);
            i += 8;
            str++;
        }
        usleep(100);
        i--;
    }
}