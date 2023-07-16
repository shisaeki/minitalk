/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:43:49 by shisaeki          #+#    #+#             */
/*   Updated: 2023/07/16 17:14:15 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <limits.h>

void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);

#endif
