# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 18:05:35 by mbel-bas          #+#    #+#              #
#    Updated: 2021/11/16 08:42:39 by mbel-bas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = ft_toupper.c ft_tolower.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
	 ft_isascii.c ft_isprint.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c\
	 ft_memcmp.c ft_bzero.c ft_atoi.c ft_calloc.c ft_strlen.c ft_strchr.c\
	 ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_strlcpy.c ft_strlcat.c\
	 ft_strdup.c ft_substr.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c\
	 ft_putnbr_fd.c ft_putendl_fd.c ft_split.c ft_strmapi.c ft_strtrim.c\
	 ft_strjoin.c ft_striteri.c

BFILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c\
		ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c ft_lstiter_bonus.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = libft.h

NAME = libft.a

OFILES = $(CFILES:.c=.o)

OFILES_B =$(BFILES:.c=.o)

ARC = ar rcs

RM = rm -f

all : $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o ${<:.c=.o}

${NAME}: $(OFILES)
	$(ARC) $(NAME) $(OFILES)
	
bonus : $(OFILES_B) $(BFILES)
	$(ARC) $(NAME) $(OFILES_B)


clean:
	$(RM) $(OFILES) $(OFILES_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all
