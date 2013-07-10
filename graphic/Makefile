##
## Makefile for zhappy in /home/louaze_j
## 
## Made by louaze_j
## Login   <louaze_j@epitech.net>
## 
## Started on  Tue Jul  9 01:12:19 2013 louaze_j
## Last update Wed Jul 10 14:14:32 2013 louaze_j
##

CC			= g++

RM			= rm -f

CPPFLAGS		+= -W -Wall -Wextra -g3
CPPFLAGS		+= -I ./includes/
CPPFLAGS		+= -I ./libmy_c/includes/

LDFLAGS			= -L. ./libmy_c/libmy_c.so

NAME			= graphic
SRCS_DIR		= sources/

SRCS			= $(SRCS_DIR)main.cpp \
			$(SRCS_DIR)World.cpp \
			$(SRCS_DIR)Square.cpp \
			$(SRCS_DIR)Graphic.cpp \
			$(SRCS_DIR)Parser.cpp \
			$(SRCS_DIR)Treatment.cpp \
			$(SRCS_DIR)Teams.cpp \
			$(SRCS_DIR)Players.cpp

OBJS			= $(SRCS:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean
