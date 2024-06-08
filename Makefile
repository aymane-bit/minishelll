# Variables

# ANSI escape codes for colors
RED = "\033[31m"
GREEN = "\033[32m"
RESET = "\033[0m"

CC = cc

# CFLAGS = -Wall -Wextra -Werror

MAKE = make

SRC =   $(addprefix sources/parsing/, pipe_checker.c parser.c redirection.c extra_parse.c heredoc_checker.c echo.c) \
    	$(addprefix sources/, hellGate.c expander.c lexer.c extra_cases.c ) \
		$(addprefix sources/utils/, expander_utils2.c utils1.c lexer_utils.c expander_utils.c \
					tk_list_opti.c) \
		$(addprefix sources/free_and_errors/, free.c erros.c) \

# valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./miniHell

OBJ = $(SRC:.c=.o)

INCLUDES = includes/miniHell.h

READLINE_LIB = -lreadline

NAME = miniHell

LIBFT_AR = ./libft/libft.a

# Targets

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_AR)
		$(CC) $(CFLAGS)  $(OBJ) $(READLINE_LIB) $(LIBFT_AR) -o $(NAME)
	@printf "\n"
	@printf $(RED)
	@printf "███╗░░░███╗██╗███╗░░██╗██╗██╗░░██╗███████╗██╗░░░░░██╗░░░░░\n"
	@printf "████╗░████║██║████╗░██║██║██║░░██║██╔════╝██║░░░░░██║░░░░░\n"
	@printf "██╔████╔██║██║██╔██╗██║██║███████║█████╗░░██║░░░░░██║░░░░░\n"
	@printf "██║╚██╔╝██║██║██║╚████║██║██╔══██║██╔══╝░░██║░░░░░██║░░░░░\n"
	@printf "██║░╚═╝░██║██║██║░╚███║██║██║░░██║███████╗███████╗███████╗\n"
	@printf "╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝╚═╝░░╚═╝╚══════╝╚══════╝╚══════╝\n"
	@printf $(GREEN)
	@printf "	     　 ▒█▀▀█ █▀▀ █▀▀█ █▀▀▄ █░░█\n"
	@printf "	     　 ▒█▄▄▀ █▀▀ █▄▄█ █░░█ █▄▄█\n"
	@printf "	     　 ▒█░▒█ ▀▀▀ ▀░░▀ ▀▀▀░ ▄▄▄█\n"
	@printf $(RESET)

$(LIBFT_AR):
		@$(MAKE) -C ./libft
		@echo "libft lib made"

clean:
		@rm -rf $(OBJ)
		@$(MAKE) clean -C ./libft
		@echo "Objects files removed"

fclean: clean
		@rm -rf $(NAME)
		@$(MAKE) fclean -C ./libft
		@echo "miniHell program destructed"
		@echo "libft archive cleaned"

re: fclean all

.phonix: clean fclean re all
