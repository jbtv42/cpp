# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 09:14:35 by jvittoz           #+#    #+#              #
#    Updated: 2025/04/24 09:14:37 by jvittoz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
       Bureaucrat.cpp \
	   AForm.cpp \
	   PresidentialPardonForm.cpp \
	   RobotomyRequestForm.cpp \
	   ShrubberyCreationForm.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re