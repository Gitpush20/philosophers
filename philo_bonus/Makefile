# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 10:42:40 by mbel-bas          #+#    #+#              #
#    Updated: 2021/12/22 11:39:38 by mbel-bas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main_bonus.c utils_bonus.c philantropist.c
NAME = philo_bonus
FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(SRC)
	@gcc $(FLAG) $(SRC) -o $(NAME) 
clean:
	@rm -rf $(NAME)
fclean: clean
re : fclean all
.PHONY: all clean fclean re