# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svoort <svoort@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/22 18:18:58 by svoort         #+#    #+#                 #
#    Updated: 2019/03/16 14:29:51 by svoort        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

FUN		=	ft_pipex.c ft_joinfree.c ft_strlen.c ft_error.c main.c ft_path.c \
			ft_strncmp.c ft_memset.c ft_memalloc.c ft_strnew.c ft_strsplit.c \
			ft_countwords.c ft_strncat.c ft_strclr.c helper.c
			
FUNDIR	=	./

GFLG	=	gcc -Wall -Wextra -Werror -c

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

HD		=	$(addprefix -I, .)

OBJDIR	=	./obj/

OBJS	=	$(FUN:.c=.o)

OBJ		=	$(addprefix $(OBJDIR), $(OBJS))

all: $(NAME)

$(NAME): ./pipex.h $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo $(NAME) "ready"

$(OBJDIR)%.o: $(FUNDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(GFLG) $(HD) -o $@ $<

clean:
	@rm -rf $(OBJDIR)
	@echo "Objects deleted"

fclean: clean
	@rm -f $(NAME)
	@echo $(NAME) "deleted"

re: fclean all
