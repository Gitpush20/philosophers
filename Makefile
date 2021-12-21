# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 13:55:55 by mbel-bas          #+#    #+#              #
#    Updated: 2021/12/21 22:11:13 by aben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = main.c threads.c philo_utils.c

BFILES = main.c utils.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = philo.h 

OFILES = philo

NAME = philo

OFILES_B =$(BFILES:.c=.o) 

RM = rm -rf


all:
	$(CC) $(CFLAGS) $(CFILES) -I $(INCLUDE) -o $(NAME)

bonus:
	$(CC) $(CFLAGS) $(BFILES) -I $(INCLUDE) -o $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) philo

re: fclean all