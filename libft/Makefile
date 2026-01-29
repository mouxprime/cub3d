# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 15:50:42 by jmenard           #+#    #+#              #
#    Updated: 2025/02/24 13:10:37 by jmenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
NC=\033[0m

NAME = libft.a

INCLUDES = libft.h

SRC = ft_strdup.c ft_strjoin.c ft_substr.c ft_strtrim.c ft_atoi.c \
    ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
    ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_isalpha.c ft_isdigit.c \
    ft_isalnum.c ft_isascii.c ft_isprint.c ft_memset.c ft_bzero.c ft_memmove.c \
    ft_strlcpy.c ft_strlcat.c ft_calloc.c ft_toupper.c ft_tolower.c ft_strchr.c \
    ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_memcpy.c \
    ft_strlen.c ./get_next_line/get_next_line_bonus.c ./get_next_line/get_next_line_utils_bonus.c \
    ./ft_printf/ft_printf_utils_bis.c ./ft_printf/ft_printf_utils.c ./ft_printf/ft_printf.c ft_exit.c ft_malloc.c \
    ft_strcmp.c ft_fork.c ft_open.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.o \
    ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
    ft_lstiter_bonus.c \

SRC_BONUS = 

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = cc 
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

bonus: all $(OBJ_BONUS)
	@ar -rv $(NAME) $(OBJ_BONUS) > /dev/null 2>&1

$(NAME): $(OBJ)
	@echo "${YELLOW}Compiling Libft...${NC}"
	@ar -rv $(NAME) $(OBJ) > /dev/null 2>&1
	@echo "${GREEN}Libft compiled successfully!${NC}"

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
