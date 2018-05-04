##
## EPITECH PROJECT, 2018
## Makefile<PSU_lemipc_2017>
## File description:
## Created by Thomas BLENEAU
##

CC 		= gcc

RM		= rm -rf

CLEAN		= clean

FCLEAN		= fclean

MKDIR		= mkdir

TMPDIRNAME	= tmp

MV		= mv

RUN		= tests_run

PROJECTPATH	= ../sources

TESTPATH	= .

SRCS		= $(PROJECTPATH)/arround.c	\
		$(PROJECTPATH)/enemies.c	\
		$(PROJECTPATH)/error.c		\
		$(PROJECTPATH)/errno.c		\
		$(PROJECTPATH)/game.c		\
		$(PROJECTPATH)/map.c		\
		$(PROJECTPATH)/moves.c		\
		$(PROJECTPATH)/player.c		\
		$(PROJECTPATH)/status.c		\
		$(TESTPATH)/tests_enemies.c	\
		$(TESTPATH)/tests_errno.c	\
		$(TESTPATH)/tests_error.c	\
		$(TESTPATH)/tests_player.c	\

GCNO		= $(SRCS:.c=.gcno)

GCDA		= $(SRCS:.c=.gcda)

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -W -Wall -Wextra -DUNIT_TEST
CFLAGS		+= -I ../includes

LDFLAGS		= -lcriterion -coverage

NAME		= tests

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
	$(MKDIR) $(TMPDIRNAME)
	$(MV) ../sources/*.o ./$(TMPDIRNAME)
	$(MV) ./*.o ./$(TMPDIRNAME)

all:	$(NAME)

$(RUN): $(FCLEAN) all
	./$(NAME)

$(CLEAN):
	$(RM) $(OBJS)
	$(RM) $(GCDA)
	$(RM) $(GCNO)

$(FCLEAN): clean
	$(RM) $(NAME)
	$(RM) $(TMPDIRNAME)

re: fclean all

.PHONY: all $(CLEAN) $(FCLEAN) $(RUN) re
