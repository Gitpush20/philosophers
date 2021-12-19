# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 13:55:55 by mbel-bas          #+#    #+#              #
#    Updated: 2021/12/19 09:43:48 by mbel-bas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = main.c philo_utils.c 

BFILES = 

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = philo.h 

OFILES = $(CFILES:.c=.o)

OFILES_B =$(BFILES:.c=.o) 

RM = rm -rf


all:
	$(CC) $(CFLAGS) $(CFILES) -I $(INCLUDE) -o philo

clean:
	$(RM) $(OFILES) $(OFILES_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all