# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 17:04:57 by shisaeki          #+#    #+#              #
#    Updated: 2023/10/18 13:19:29 by shinsaeki        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER=server
NAME_CLIENT=client

CC=gcc

CFLAGS=-g -Wall -Wextra -Werror

SRCS_SERVER=server.c ft_atoi.c ft_itoa.c
SRCS_CLIENT=client.c ft_atoi.c ft_itoa.c

INCLUDES=minitalk.h \

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SRCS_SERVER)
	$(CC) -o $(NAME_SERVER) -I $(INCLUDES) $(SRCS_SERVER)

$(NAME_CLIENT): $(SRCS_CLIENT)
	$(CC) -o $(NAME_CLIENT) -I $(INCLUDES) $(SRCS_CLIENT)
clean:
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
re: clean all

