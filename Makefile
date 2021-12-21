# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 13:55:55 by mbel-bas          #+#    #+#              #
#    Updated: 2021/12/21 09:13:51 by mbel-bas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = main.c threads.c philo_utils.c

BFILES = 

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = philo.h 

OFILES = philo

NAME = philo

OFILES_B =$(BFILES:.c=.o) 

RM = rm -rf


all:
	$(CC) $(CFLAGS) $(CFILES) -I $(INCLUDE) -o $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) philo

re: fclean all