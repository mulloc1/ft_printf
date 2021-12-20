# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 20:54:36 by jaebae            #+#    #+#              #
#    Updated: 2021/12/07 20:25:58 by jaebae           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAG = -Wall -Wextra -Werror

AR = ar
ARFLAGS = crs

INCLUDES = ./libft.h

SRC = libft/

SRCS = $(SRC)ft_substr.c $(SRC)ft_split.c $(SRC)ft_itoa.c $(SRC)ft_atoi.c $(SRC)ft_bzero.c $(SRC)ft_calloc.c $(SRC)ft_memset.c $(SRC)ft_memcpy.c $(SRC)ft_memmove.c $(SRC)ft_memchr.c $(SRC)ft_memcmp.c $(SRC)ft_strlen.c $(SRC)ft_isalpha.c $(SRC)ft_isdigit.c $(SRC)ft_isalnum.c $(SRC)ft_isascii.c $(SRC)ft_isprint.c $(SRC)ft_toupper.c $(SRC)ft_tolower.c $(SRC)ft_strchr.c $(SRC)ft_strrchr.c $(SRC)ft_strncmp.c $(SRC)ft_strlcpy.c $(SRC)ft_strlcat.c $(SRC)ft_strnstr.c $(SRC)ft_strdup.c $(SRC)ft_strjoin.c $(SRC)ft_strtrim.c $(SRC)ft_strmapi.c $(SRC)ft_putchar_fd.c $(SRC)ft_putstr_fd.c $(SRC)ft_putendl_fd.c $(SRC)ft_putnbr_fd.c $(SRC)ft_striteri.c ft_convert.c ft_convert2.c ft_printf.c $(SRC)ft_lstadd_back.c $(SRC)ft_lstadd_front.c $(SRC)ft_lstclear.c $(SRC)ft_lstdelone.c $(SRC)ft_lstiter.c $(SRC)ft_lstlast.c $(SRC)ft_lstmap.c $(SRC)ft_lstnew.c $(SRC)ft_lstsize.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

fclean : clean
	rm -f $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	rm -f $(OBJS)

re : fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY : re fclean clean bonus all
