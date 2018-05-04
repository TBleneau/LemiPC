##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Created by Thomas BLENEAU
##

CC		= gcc

RM		= rm -f

SRCS		= sources/arround.c	\
		sources/enemies.c	\
		sources/error.c		\
		sources/errno.c		\
		sources/game.c		\
		sources/main.c		\
		sources/map.c		\
		sources/moves.c		\
		sources/player.c	\
		sources/status.c	\

GCNO		= $(SRCS:.c=.gcno)

GCDA		= $(SRCS:.c=.gcda)

CFLAGS		= -I includes/
CFLAGS		+= -W -Wall -Wextra -std=gnu99

NAME		= lemipc

OBJS		= $(SRCS:.c=.o)

CLEAN		= clean

FCLEAN		= fclean

RUN		= tests_run

$(NAME)		: $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all		: $(NAME)

$(RUN)		:
		make $(RUN) -C ./tests/

$(CLEAN)	:
		$(RM) $(OBJS)
		$(RM) $(GCDA)
		$(RM) $(GCNO)
		make $(CLEAN) -C ./tests/

$(FCLEAN)	: $(CLEAN)
		$(RM) $(NAME)
		make $(FCLEAN) -C ./tests/

re		: $(FCLEAN) all

.PHONY : all $(CLEAN) $(FCLEAN) $(RUN) re
