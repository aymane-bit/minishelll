# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achahid- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 11:56:28 by achahid-          #+#    #+#              #
#    Updated: 2023/11/15 11:56:31 by achahid-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = ft_isalnum.c ft_isprint.c ft_memcmp.c \
		ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
		ft_memcpy.c ft_strchr.c ft_strlcpy.c \
		ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c \
		ft_memmove.c ft_strdup.c ft_strlen.c ft_strrchr.c \
		ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c \

CFILES_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJECTS = $(CFILES:.c=.o)

OBJECTS_B = $(CFILES_B:.c=.o)

CC = cc

FLAGS = -Werror -Wextra -Wall

NAME = libft.a

AR = ar rcs

all: $(NAME)

bonus:  $(OBJECTS_B) $(CFILES_B)
		$(CC) $(FLAGS) -c $(CFILES_B)
		$(AR) $(NAME) $(OBJECTS_B)

$(NAME): $(OBJECTS) $(CFILES)
		@$(CC) $(FLAGS) -c $(CFILES)
		@$(AR) $(NAME) $(OBJECTS)

clean: 
		@rm -f $(OBJECTS) $(OBJECTS_B)

fclean: clean
		@rm -f $(NAME)

re: clean fclean all
