# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 17:04:57 by shisaeki          #+#    #+#              #
#    Updated: 2024/01/12 12:32:38 by shinsaeki        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER=server
NAME_CLIENT=client

CC=gcc

CFLAGS=-g -Wall -Wextra -Werror

SRCS_SERVER=server.c minitalk_utils/ft_atoi.c minitalk_utils/ft_itoa.c
SRCS_CLIENT=client.c minitalk_utils/ft_atoi.c minitalk_utils/ft_itoa.c

INCLUDES=minitalk.h \

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SRCS_SERVER)
	$(CC) -o $(NAME_SERVER) -I $(INCLUDES) $(SRCS_SERVER)

$(NAME_CLIENT): $(SRCS_CLIENT)
	$(CC) -o $(NAME_CLIENT) -I $(INCLUDES) $(SRCS_CLIENT)
clean:
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
re: clean all

