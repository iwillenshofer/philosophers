# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwillens <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/10 17:45:43 by iwillens          #+#    #+#              #
#    Updated: 2020/06/20 03:46:34 by iwillens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_two
CC = clang
CCFLAGS = -Wall -Wextra -Werror -Wno-nullability-completeness -fsanitize=address -g

OBJ_DIR= ./build
SRC_DIR= ./

HEADERS = philo_two.h

SRCS =  $(SRC_DIR)/common_args.c \
		$(SRC_DIR)/common_error.c \
		$(SRC_DIR)/common_utils.c \
		$(SRC_DIR)/common_init.c \
		$(SRC_DIR)/common_memfree.c \
		$(SRC_DIR)/common_write.c \
		$(SRC_DIR)/common_time.c \
		$(SRC_DIR)/philo_two_init.c \
		$(SRC_DIR)/philo_two_actions.c \
		$(SRC_DIR)/philo_two_monitor.c \
		$(SRC_DIR)/philo_two_end.c \
		$(SRC_DIR)/philo_two.c


OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all : $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CCFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	mkdir -p ./build
	$(CC) -c $(CCFLAGS) $< $(INCLUDES) -o $@

test: all
	./$(NAME) 1 910 200 200 4

clean: 
	rm -rf ./build

fclean: clean
	rm -f $(NAME)

re: fclean all
