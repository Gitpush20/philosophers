# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 13:55:55 by mbel-bas          #+#    #+#              #
#    Updated: 2021/12/22 10:46:52 by mbel-bas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c threads.c philo_utils.c
NAME = philo
FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(SRC)
	@gcc $(FLAG) $(SRC) -o $(NAME)
clean:
	@rm -rf $(NAME)
fclean: clean
re : fclean all
.PHONY: all clean fclean re