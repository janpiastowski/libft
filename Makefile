# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiastow <jpiastow@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 11:20:45 by jpiastow          #+#    #+#              #
#    Updated: 2022/11/01 11:14:34 by jpiastow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_toupper.c ft_tolower.c ft_strrchr.c ft_strnstr.c ft_strncmp.c \
 	ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strdup.c ft_strchr.c ft_memset.c \
 	ft_memmove.c ft_memcpy.c ft_memcmp.c ft_memchr.c ft_isprint.c ft_isdigit.c \
 	ft_isascii.c ft_isalpha.c ft_isalnum.c ft_calloc.c ft_atoi.c ft_bzero.c \
	ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_striteri.c \
	ft_strmapi.c ft_itoa.c ft_split.c ft_strtrim.c ft_substr.c ft_strjoin.c

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstadd_back.c

BONUS_OBJS = $(BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJS): libft.h
	@$(CC) $(CFLAGS) -c $(SRCS)

clean: 
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean
	@$(MAKE) all

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus