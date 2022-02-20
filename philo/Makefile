# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 20:37:45 by jihoh             #+#    #+#              #
#    Updated: 2022/02/20 20:58:10 by jihoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wextra -Wall

NAME = philo

SRCS = main.c philo.c init.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "\033[32m[$(NAME)]: compiled\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "clean"

fclean: clean
	@rm -rf $(NAME)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "fclean"

re: fclean all

.PHONY: all clean fclean re